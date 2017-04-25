#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>

#include "slamBase.h"
using namespace std;


//socket编程需要的头文件
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX 10
#define CLIENT_IP "219.216.87.67"
#define PORT 9407


int main( int argc, char** argv )
{
        int socket_server,new_socket_server,fd;
        int len,rgblen,depthlen;
        int is_connect[MAX]={0};
        fd_set myreadfds;
        
        struct sockaddr_in client_addr;
        unsigned int addr_len = sizeof(struct sockaddr_in);
        char buf[BUFSIZ];
        int test[BUFSIZ];

      //  ushort depthline[640*480];     
      //  cv::Mat rgb,depth;

        memset(&client_addr,0,sizeof(client_addr));
        client_addr.sin_family=AF_INET;
        client_addr.sin_addr.s_addr=INADDR_ANY;        //inet_addr(CLIENT_IP);
        client_addr.sin_port=htons(PORT);
        
        
        /************************   socket  ********************************/
       if((socket_server=socket(PF_INET,SOCK_STREAM,0))<0)
        {
                perror("socket");
                return 1;
        }


        /************************   bind  ********************************/
        if(bind(socket_server,(struct sockaddr*)&client_addr,sizeof(client_addr))<0)
        {
                perror("bind");
                return 1;
        }
        else
        {
                cout<<"bind OK! "<<endl;
                cout<<"local port: "<<PORT<<endl;
        }

        
        /************************   listen  ********************************/
        if (listen(socket_server,5)<0)
        {
                perror("listen");
                return 1;
        }
        else
        {
                cout<<"listening ..."<<endl;
        }


        while(1)
        {
                FD_ZERO(&myreadfds);            // 清空标志
                FD_SET(socket_server,&myreadfds);    //设置一个标志

                for( fd=0;fd<MAX;fd++)
                {
                        if(is_connect[fd])          //判断有没有连接
                        {                           
                                FD_SET(fd,&myreadfds);    //设置标记
                        }
                }

                if (!select(MAX,&myreadfds,NULL,NULL,NULL))  //select 函数用法 ： http://blog.csdn.net/gooer/article/details/3951135
                {                                            //                 http://www.cnblogs.com/renyuan/p/5100184.html
                        continue;         //如果达到最大连接数，进入下次循环
                }
                
                for(fd=0;fd<MAX;fd++)
                {
                        if(FD_ISSET(fd,&myreadfds))        //  FD_ISSET(s,*set)：若s为集合中一员，非零；否则为零。
                        {
                                if(socket_server==fd)
                                {
                                        if ((new_socket_server=accept(socket_server,(struct sockaddr*)&client_addr,&addr_len))<0)
                                        {
                                                perror("accept");
                                                return 1;
                                        }
                                        else
                                        {
                                                is_connect[new_socket_server]=1;         //设置标志
                                                cout<<"connected from : "<<inet_ntoa(client_addr.sin_addr)<<endl;     //输出客户ip
                                        }
                                }               
                                else
                                {
                                        cout<<"传输开始！"<<endl;
                                        char rgb_name[13];
                                        char depth_name[13];
                                        int rgbnumb=0;
                                        int depthnumb=0;
                                        string rgbstr="../data/rgb_png/";
                                        string depthstr="../data/depth_png/";
                                        
                                        while(1)
                                        {
                                                /****************************  RGB图接受  *****************************/
                                                cv::Mat rgb=cv::Mat::zeros(480,640,CV_8UC3);
                                                int rgbSize=rgb.total()*rgb.elemSize();
                                                uchar sockDataRgb[rgbSize];
                
                                                for(int i=0;i<rgbSize;i+=rgblen)
                                                {
                                                        if((rgblen=recv(new_socket_server,sockDataRgb+i,rgbSize-i,0))==-1)
                                                        {
                                                                cout<<"recv faild"<<endl;                                                
                                                        }
                                                        if(rgblen==0)
                                                        {
                                                                break;
                                                        }
                                                }

                                                int ptr=0;
                                                for(int i=0;i<rgb.rows;i++)
                                                {
                                                        for(int j=0;j<rgb.cols;j++)
                                                        {
                                                                rgb.at<cv::Vec3b>(i,j)=cv::Vec3b(sockDataRgb[ptr+0],sockDataRgb[ptr+1],sockDataRgb[ptr+2]);
                                                                ptr=ptr+3;
                                                        }
                                                }
                                                
                                                sprintf(rgb_name, "%d%s", ++rgbnumb, ".png");
                                                cv::imwrite( rgbstr+rgb_name, rgb); 


                                                /****************************  深度图接受        *****************************/
                                                cv::Mat depth1=cv::Mat::zeros(480,640,CV_16UC1);
                                                int depthSize=depth1.total()*depth1.elemSize();
                                                ushort sockDataDepth[depthSize/depth1.elemSize()];
                        
                                                for(int i=0;i<depthSize;i+=depthlen)
                                                {
                                                        if((depthlen=recv(new_socket_server,sockDataDepth+i/2,depthSize-i,0))==-1)
                                                        {
                                                                cout<<"recv faild"<<endl;
                                                        }
                                                        if(depthlen==0)
                                                        {
                                                                break;
                                                        }
                                                }
                                                
                                                cv::Mat depth(cv::Size(640, 480), CV_16UC1, sockDataDepth);

                                                sprintf(depth_name, "%d%s", ++depthnumb, ".png");
                                                cv::imwrite( depthstr+depth_name, depth);
       
                                                
                                                /***********  判断是否传输完毕 **********/
                                                if(!(rgblen+depthlen))
                                                {
                                                        is_connect[fd]=0;       //设置标志，连接终了
                                                        close(fd);
                                                        cout<<"传输完毕！"<<endl;
                                                        break;
                                                }
                                        }
                                }
                        }                
                }             
        }
}














