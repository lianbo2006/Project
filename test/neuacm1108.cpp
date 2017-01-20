#include<iostream>
#include<stdio.h>
using namespace std;
double ZRD(double a,double b ,double c)
{
    return -a*a+b*b+c*c;
}
int main(int argc, char const *argv[])
{
            freopen("/home/lianbo2006/Project/test/neuacm1108in.txt","r",stdin);
            freopen("/home/lianbo2006/Project/test/neuacm1108out.txt","w",stdout);
            double a,b,c,d;
            while(cin>>a)
            {
                cin>>b;
                if(a<b)
                {
                    d=a;
                    a=b;
                    b=d;
                }
                cin>>c;
                if(a<c)
                {
                    d=a;
                    a=c;
                    c=d;
                }
                if(b<c)
                {
                    d=b;
                    b= c;
                    c=d;
                }
                if(a>=(b+c)||b<=(a-c))
                {
                    cout<<'N'<<endl;
                    cout<<endl;
                }
                else if(ZRD(a,b,c)==0)
                {
                    cout<<'Z'<<endl;
                    cout<<endl;
                }
                else if(ZRD(a,b,c)>0)
                {
                    cout<<'R'<<endl;
                    cout<<endl;
                }
                else
                {
                    cout<<'D'<<endl;
                    cout<<endl;
                }
            }
            fclose(stdin);
            fclose(stdout);
            return 0;
}