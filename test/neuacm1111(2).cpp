#include<iostream>
#include<stdio.h>
#include<iomanip>
using namespace std;
int main(int argc, char const *argv[])
{
	freopen("/home/lianbo2006/Project/test/neuacm1111in.txt","r",stdin);
	freopen("/home/lianbo2006/Project/test/neuacm1111out.txt","w",stdout);
	double a,b,c;
	while(cin>>a)
	{
	 cin>>b;
	 c=a*b;
	 cout<<fixed<<setprecision(0)<<c<<endl;
	}
	fclose(stdin);
               fclose(stdout);
               return 0;
}