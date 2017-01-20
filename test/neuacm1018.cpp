#include<iostream>
#include<stdio.h>
#include<cmath>
using namespace std;
int main(int argc, char const *argv[])
{
            freopen("/home/lianbo2006/Project/test/neuacm1018in.txt","r",stdin);
            freopen("/home/lianbo2006/Project/test/neuacm1018out.txt","w",stdout);
            int n,i,j,xi=1,yi=1,a,max=0;
            cin>>n;
            for(i=1;i<=n;i++)
            {
                for(j=1;j<=n;j++)
                {
                    cin>>a;
                    if(abs(a)>=abs(max))
                    {
                        max=a,xi=i,yi=j;
                    }
                }
            }
            cout<<max<<' '<<xi<<' '<<yi<<endl;
            fclose(stdin);
            fclose(stdout);
            return 0;
}