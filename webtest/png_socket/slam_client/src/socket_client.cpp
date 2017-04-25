#include <string.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
#include "slamBase.h"
//socket相关
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

# define PORT 9082    //定义端口号
# define REMOTE_IP  "103.39.107.226"        //"127.0.0.1"    "172.17.0.2"   //定义远程ip

int key=0;
// 给定index，读取一帧数据
FRAME readFrame( int index, ParameterReader& pd );
// 度量运动的大小
double normofTransform( cv::Mat rvec, cv::Mat tvec );
// 检测两个帧，结果定义
enum CHECK_RESULT {NOT_MATCHED=0, TOO_FAR_AWAY, TOO_CLOSE, KEYFRAME}; 

// 函数声明
CHECK_RESULT checkKeyframes( FRAME& f1, FRAME& f2 );


int main( int argc, char** argv )
{   

    int server_sockfd;//服务器端套接字
	int client_sockfd;//客户端套接字
	int len,rgblen,depthlen,desplen,desprowslen,keypointlen;

    int chuanshu[BUFSIZ];//用于判断是否接收到数据，从而进入循环
	struct sockaddr_in my_addr;   //服务器网络地址结构体
	struct sockaddr_in remote_addr; //客户端网络地址结构体
	socklen_t sin_size;
	char buf[BUFSIZ];  //数据传送的缓冲区
    int  test[BUFSIZ];//测试数据运算
      //  ushort depthline[640*480];
       // cv::Mat image[BUFSIZ];
	memset(&my_addr,0,sizeof(my_addr)); //数据初始化--清零
	my_addr.sin_family=AF_INET; //设置为IP通信
	my_addr.sin_port=htons(PORT); //服务器端口号
	my_addr.sin_addr.s_addr=inet_addr(REMOTE_IP);//服务器IP地址--允许连接到所有本地地址上
	
	
	/*创建服务器端套接字--IPv4协议，面向连接通信，TCP协议*/
	if((client_sockfd=socket(AF_INET,SOCK_STREAM,0))<0)  //PF_INET是IPv4网络协议，SOCK_STREAM是TCP协议，0是传输协议（ip）编号
	{  
		perror("socket");
		return 1;
	}
 
 
	/************************   connect  ********************************/
    if(connect(client_sockfd,(struct sockaddr*)&my_addr,sizeof(my_addr))<0)
    {
        perror("connect");
        return 1;
    }
    else
    {
        cout<<"connect created !"<<endl;
    }

        /*将套接字绑定到服务器的网络地址上*/
/*	if (bind(server_sockfd,(struct sockaddr *)&my_addr,sizeof(struct sockaddr))<0)
	{
		perror("bind");
		return 1;
	}
*/
	/*监听连接请求--监听队列长度为5*/
	//listen(server_sockfd,5);



	
	//sin_size=sizeof(struct sockaddr_in);
	
	/*等待客户端连接请求到达*/
/*	if((client_sockfd=accept(server_sockfd,(struct sockaddr *)&remote_addr,&sin_size))<0)
	{
		perror("accept");
		return 1;
	}
	//printf("accept client %s/n",inet_ntoa(remote_addr.sin_addr));
	//len=send(client_sockfd,"Welcome to my server/n",21,0);//发送欢迎信息
*/
	
    ParameterReader pd;
    int startIndex  =   atoi( pd.getData( "start_index" ).c_str() );
    int endIndex    =   atoi( pd.getData( "end_index"   ).c_str() );

    // initialize
    cout<<"Initializing ..."<<endl;
    int currIndex = startIndex; // 当前索引为currIndex
    FRAME lastFrame = readFrame( currIndex, pd ); // 上一帧数据
    // 我们总是在比较currFrame和lastFrame
   // string detector = pd.getData( "detector" );
   // string descriptor = pd.getData( "descriptor" );
    CAMERA_INTRINSIC_PARAMETERS camera = getDefaultCamera();
    computeKeyPointsAndDesp( lastFrame );//计算关键点和特征描述子
   // PointCloud::Ptr cloud = image2PointCloud( lastFrame.rgb, lastFrame.depth, camera );
    
   
     //第一帧是关键帧，传输到server端

       cv::Mat firstrgb = lastFrame.rgb;            
       cv::Mat firstdepth = lastFrame.depth;
    

       firstrgb=(firstrgb.reshape(0,1));//to make it continuous
       firstdepth=(firstdepth.reshape(0,1));//to make it continuous
      

       int firstrgbSize=firstrgb.total()*firstrgb.elemSize();
       int firstdepthSize=firstdepth.total()*firstdepth.elemSize();   

       cout<<"send image:"<<endl;
      // len=send(client_sockfd,chuanshu,BUFSIZ,0);

       rgblen=send(client_sockfd,firstrgb.data,firstrgbSize,0);  //发送彩色图像
       depthlen=send(client_sockfd,firstdepth.data,firstdepthSize,0);  //发送深度图像
    

//////////////////////////////////////////////////////////////////////////////////


    int min_inliers = atoi( pd.getData("min_inliers").c_str() );
    double max_norm = atof( pd.getData("max_norm").c_str() );
    double keyframe_threshold = atof( pd.getData("keyframe_threshold").c_str() );
    for ( currIndex=startIndex+1; currIndex<endIndex; currIndex++ )
    {   
        cout<<"Reading files "<<currIndex<<endl;
        FRAME currFrame = readFrame( currIndex,pd ); // 读取currFrame

       
        computeKeyPointsAndDesp( currFrame);//计算关键点和特征描述子
        // 比较currFrame 和 lastFrame

      CHECK_RESULT result = checkKeyframes( lastFrame, currFrame); //匹配该帧与keyframes里最后一帧
        switch (result) // 根据匹配结果不同采取不同策略
                {
                    case NOT_MATCHED:
                        //没匹配上，直接跳过
                        cout<<RED"Not enough inliers."<<endl;
                        break;
                    case TOO_FAR_AWAY:
                        // 太近了，也直接跳
                         cout<<RED"Too far away, may be an error."<<endl;
                         break;
                    case TOO_CLOSE:
                       // 太远了，可能出错了
                        cout<<RESET"Too close, not a keyframe"<<endl;
                        break;
                    case KEYFRAME:
					    cout<<GREEN"This is a new keyframe"<<endl;
                       // 不远不近，刚好
                      /*用于关键帧的传输*/
                       cv::Mat rgb = currFrame.rgb;            
                       cv::Mat depth = currFrame.depth;
              
                       rgb=(rgb.reshape(0,1));//to make it continuous
                       depth=(depth.reshape(0,1));//to make it continuous
   
                       int rgbSize=rgb.total()*rgb.elemSize();
                       int depthSize=depth.total()*depth.elemSize();

                       cout<<"send image:"<<endl;
	
					   double t=(double)cvGetTickCount(); 


                     // len=send(client_sockfd,chuanshu,BUFSIZ,0);

					   rgblen=send(client_sockfd,rgb.data,rgbSize,0);  //发送彩色图像
					   depthlen=send(client_sockfd,depth.data,depthSize,0);  //发送深度图像 
					   
						cout<<rgblen<<endl;
						cout<<depthlen<<endl;
					   t = (double)cvGetTickCount() - t;
					   cout<<"runtime:"<<t/(cvGetTickFrequency()*1000)<<endl;
		
                       cout<<"send end"<<endl;
                       lastFrame = currFrame;
                 
                       break;
				}
    }

    close(client_sockfd);//关闭套接字

    std::cout<<"hello slam"<<std::endl;
    return 0;

}

FRAME readFrame( int index, ParameterReader& pd )
{
    FRAME f;
    string rgbDir   =   pd.getData("rgb_dir");
    string depthDir =   pd.getData("depth_dir");
    
    string rgbExt   =   pd.getData("rgb_extension");
    string depthExt =   pd.getData("depth_extension");

    stringstream ss;
    ss<<rgbDir<<index<<rgbExt;
    string filename;
    ss>>filename;
    f.rgb = cv::imread( filename );

    ss.clear();
    filename.clear();
    ss<<depthDir<<index<<depthExt;
    ss>>filename;

    f.depth = cv::imread( filename, -1 );
    return f;
}

double normofTransform( cv::Mat rvec, cv::Mat tvec )
{
    return fabs(min(cv::norm(rvec), 2*M_PI-cv::norm(rvec)))+ fabs(cv::norm(tvec));
}

CHECK_RESULT checkKeyframes( FRAME& f1, FRAME& f2)
{
    static ParameterReader pd;
    static int min_inliers = atoi( pd.getData("min_inliers").c_str() );
    static double max_norm = atof( pd.getData("max_norm").c_str() );
    static double keyframe_threshold = atof( pd.getData("keyframe_threshold").c_str() );
   // static double max_norm_lp = atof( pd.getData("max_norm_lp").c_str() );
    static CAMERA_INTRINSIC_PARAMETERS camera = getDefaultCamera();
    
    // 比较f1 和 f2
    RESULT_OF_PNP result = estimateMotion( f1, f2, camera );
    if ( result.inliers < min_inliers ) //inliers不够，放弃该帧
        return NOT_MATCHED;
    // 计算运动范围是否太大
    double norm = normofTransform(result.rvec, result.tvec);
   
    if ( norm >= max_norm )
       return TOO_FAR_AWAY;   // too far away, may be error
   

    if ( norm <= keyframe_threshold )
        return TOO_CLOSE;   // too adjacent frame 
   
    return KEYFRAME;
}



