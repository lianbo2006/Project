#include<iostream>
#include<stdio.h>
#include <string>
#include <algorithm> 
using namespace std;
int main(int argc, char const *argv[])
{
            freopen("/home/lianbo2006/Project/test/neuacm1107in.txt","r",stdin);
            freopen("/home/lianbo2006/Project/test/neuacm1107out.txt","w",stdout);
            string a;
            int len;
            while(cin>>a)
            {
              /*len=a.length() ;
              for (int i = 0; i < len; ++i)
              {
                cout<<a[i]<<endl;
                }*/
              sort(a.begin(),a.end());
              cout<<a<<endl;
             }
            fclose(stdin);
            fclose(stdout);
            return 0;
}