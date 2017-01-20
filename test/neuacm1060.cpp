#include<iostream>
#include <stdio.h>
using namespace std;
int main(int argc, char const *argv[])
{
	freopen("/home/lianbo2006/Project/test/neuacm1260in.txt","r",stdin);
	freopen("/home/lianbo2006/Project/test/neuacm1260out.txt","w",stdout);
	int a,b,c;
	while(cin>>hex>>a)
	{
		cin>>hex>>b;
		c=a+b;
		//cout.setf(ios::uppercase);//大写输出进制数
		cout<<hex<<c<<endl;
	}
                fclose(stdin);
	fclose(stdout);
	return 0;
}