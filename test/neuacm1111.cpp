#include<iostream>
#include<stdio.h>
#include<stdint.h>
using namespace std;
int main(int argc, char const *argv[])
{
	freopen("/home/lianbo2006/Project/test/neuacm1111in.txt","r",stdin);
	freopen("/home/lianbo2006/Project/test/neuacm1111out.txt","w",stdout);
	int64_t a,b,c;
	while(cin>>a)
	{
	 cin>>b;
	 c=a*b;
	 cout<<c<<endl;
	}
	fclose(stdin);
               fclose(stdout);
               return 0;
}