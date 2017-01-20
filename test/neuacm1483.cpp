#include<iostream>
#include<stdio.h>
#include<stdint.h>
using namespace std;
int main(int argc, char const *argv[])
{
            freopen("/home/lianbo2006/Project/test/neuacm1483in.txt","r",stdin);
            freopen("/home/lianbo2006/Project/test/neuacm1483out.txt","w",stdout);
            int a,n;
            cin>>a;
            for (int i = 0; i < a; ++i)
            {
              cin>>n;
              int b[2*n+1],c[2*n+1];
              for (int i = 0; i < n; ++i)
              {
                cin>>b[i];
                b[n+i]=b[i];
              }
              c[0]=1;
              int ans=1;
              for (int i = 1; i < 2*n; ++i)
              {
                if(b[i]>b[i-1])
                  c[i]=c[i-1]+1;
                else c[i]=1;
                ans=max(ans, c[i]);
              }
              cout<<ans<<endl;
            }
            fclose(stdin);
            fclose(stdout);
            return 0;
}