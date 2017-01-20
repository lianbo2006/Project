#include<iostream>
#include<stdio.h>
#include <string>
#include <algorithm> 
using namespace std;
int main(int argc, char const *argv[])
{
            freopen("/home/lianbo2006/Project/test/neuacm1481in.txt","r",stdin);
            freopen("/home/lianbo2006/Project/test/neuacm1481out.txt","w",stdout);
            string a,b;
            while(cin>>a)
            {
                b="";
               for (int i = 0; a[i]!='\0'; ++i)
               {
                   if(a[i]>='0'&&a[i]<='9')
                   {
                    b=b+a[i];
                   }
               }
               sort(b.begin(),b.end());
               cout<<b<<endl;
            }
            fclose(stdin);
            fclose(stdout);
            return 0;
}