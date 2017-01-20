#include<iostream>
#include<stdio.h>
#include <algorithm>
using namespace std;
int main(int argc, char const *argv[])
{
            freopen("/home/lianbo2006/Project/test/neuacm1141in.txt","r",stdin);
            freopen("/home/lianbo2006/Project/test/neuacm1141out.txt","w",stdout);
            int a[100001],n;
            while(cin>>n)
            {
            for (int i = 0; i < n; ++i)
            {
              cin>>a[i];
            }
            sort(a,a+n);
            int l=0;
            for (int i=0;i<n;i++)
            {
            if (i==0||a[i]!=a[i-1]) 
            {
            if (l%2==1) 
            {
            cout<<a[i-1]<<endl;
            break;
            }
            l=1;
            }
            else l++;
            }
            }
            fclose(stdin);
            fclose(stdout);
            return 0;
}