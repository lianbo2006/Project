#include<iostream>
#include<stdio.h>
using namespace std;
int lcm(int a,int b)
{
  int  m=a,n=b,r;
  while((r=m%n)!=0)
  {
    m=n;
    n=r;
  }
  return a*b/n;
}
int main(int argc, char const *argv[])
{
            freopen("/home/lianbo2006/Project/test/neuacm1129in.txt","r",stdin);
            freopen("/home/lianbo2006/Project/test/neuacm1129out.txt","w",stdout);
            int a,b,c,flag=0;
            while(cin>>a)
            {
             cin>>b;
             for (int i = 1; i <= a/2; ++i)
             {
               c=a-i;
               if(lcm(i,c)==b)
                {
                  cout<<i<<' '<<c<<endl;
                  flag=1;
                  break;
                }
             }
             if(flag==0)
              cout<<"No answer"<<endl;
            flag=0;
             }
            fclose(stdin);
            fclose(stdout);
            return 0;
}