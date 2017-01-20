#include<iostream>
#include<stdio.h>
#include<stdint.h>
using namespace std;
int main(int argc, char const *argv[])
{
            freopen("/home/lianbo2006/Project/test/neuacm1221in.txt","r",stdin);
            freopen("/home/lianbo2006/Project/test/neuacm1221out.txt","w",stdout);
            uint64_t t,n,m,k,ans1,ans2;
            //double ans;
           cin>>t;
           /*cout<<t<<endl;*/
           for (int i = 0; i < t; ++i)
           {
             cin>>n>>m>>k;
             //ans=(1.0*n)/(1.0*m);
             ans1=n/m;
             cout<<ans1;
             if(k>0)
              cout<<'.';
            ans1=n%m;
            for (int i = 0; i < k; ++i)
            {
              ans1=ans1*10;
              ans2=ans1/m;
              cout<<ans2;
              ans1=ans1%m;
            }
            cout<<endl;
           }
            fclose(stdin);
            fclose(stdout);
            return 0;
}