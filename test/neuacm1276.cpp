#include<iostream>
#include<stdio.h>
#include <cmath>
#include<iomanip>
using namespace std;
int main(int argc, char const *argv[])
{
            freopen("/home/lianbo2006/Project/test/neuacm1276in.txt","r",stdin);
            freopen("/home/lianbo2006/Project/test/neuacm1276out.txt","w",stdout);
            int r,h,w;
            double x,R;
            while(cin>>r)
            {
              cin>>h>>w;
              x=pow(1.0*w,2.0)*pow(1.0*r,2.0)*2.0*h/9.8;
              R=sqrt(pow(1.0*r,2.0)+x);
              cout<<fixed<<setprecision(2)<<R<<endl;;
            }
            fclose(stdin);
            fclose(stdout);
            return 0;
}