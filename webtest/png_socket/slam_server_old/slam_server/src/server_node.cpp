#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

#include "slamBase.h"


#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>


using namespace cv;


int main( int argc, char** argv )
{

      
         int server_sockfd;
        int client_sockfd;
        int len,rgblen,depthlen;

        struct sockaddr_in remote_addr;
        char buf[BUFSIZ];

        int test[BUFSIZ];

      //  ushort depthline[640*480];
      
      //  cv::Mat rgb,depth;

        memset(&remote_addr,0,sizeof(remote_addr));
        remote_addr.sin_family=AF_INET;
        remote_addr.sin_addr.s_addr=inet_addr("127.0.0.1");
        remote_addr.sin_port=htons(9001);
       if((client_sockfd=socket(PF_INET,SOCK_STREAM,0))<0)
        {
                perror("socket");
                return 1;
        }


        if(connect(client_sockfd,(struct sockaddr *)&remote_addr,sizeof(struct sockaddr))<0)
        {
                perror("connect");
                return 1;
        }

        cout<<"connected to server"<<endl;

     //   len=recv(client_sockfd,buf,BUFSIZ,0);
     //   cout<<buf<<endl;

      char rgb_name[13];
      char depth_name[13];
      int rgbnumb=0;
      int depthnumb=0;
       string rgbstr="../data/rgb_png/";
       string depthstr="../data/depth_png/";

while(1)
      {

        
           Mat rgb=Mat::zeros(480,640,CV_8UC3);
           int rgbSize=rgb.total()*rgb.elemSize();
           uchar sockDataRgb[rgbSize];
           for(int i=0;i<rgbSize;i+=rgblen)
             {
               if((rgblen=recv(client_sockfd,sockDataRgb+i,rgbSize-i,0))==-1)
                   cout<<"recv faild"<<endl;
             }
          int ptr=0;
          for(int i=0;i<rgb.rows;i++)
             for(int j=0;j<rgb.cols;j++)
             {
              rgb.at<cv::Vec3b>(i,j)=cv::Vec3b(sockDataRgb[ptr+0],sockDataRgb[ptr+1],sockDataRgb[ptr+2]);
              ptr=ptr+3;
             }
         sprintf(rgb_name, "%d%s", ++rgbnumb, ".png");
          cv::imwrite( rgbstr+rgb_name, rgb); 

    
          Mat depth1=Mat::zeros(480,640,CV_16UC1);
          int depthSize=depth1.total()*depth1.elemSize();
          ushort sockDataDepth[depthSize/depth1.elemSize()];
          for(int i=0;i<depthSize;i+=depthlen)
            {
                if((depthlen=recv(client_sockfd,sockDataDepth+i/2,depthSize-i,0))==-1)
                    cout<<"recv faild"<<endl;
            }
          Mat depth(Size(640, 480), CV_16UC1, sockDataDepth);

          sprintf(depth_name, "%d%s", ++depthnumb, ".png");
          cv::imwrite( depthstr+depth_name, depth);   




       }







}














