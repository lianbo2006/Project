#include<iostream>
#include <stdio.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int months[3]={1,2};
	for (int i = 0; i < 3; ++i)
	{
		cout<<months[i]<<endl;
	}
	cout<<sizeof months<<" "<<sizeof months[1]<<endl;
	int count=sizeof months/sizeof  (int);
	cout<<"count="<<count<<endl;
	int a[2]={0};
	int b[2]={1};
	int c[]={1,2};
	for (int i = 0; i <2; ++i)
	{
		cout<<"a["<<i<<"]="<<a[i]<<endl;
		cout<<"b["<<i<<"]="<<b[i]<<endl;
		cout<<"c["<<i<<"]="<<c[i]<<endl;
	}
	freopen("/home/lianbo2006/Project/test/neuacm1260in.txt","r",stdin);
	int f,g,h;
	while(cin>>hex>>f)
	{
		cin>>hex>>g;
		h=f+g;
		cout.setf(ios::uppercase);//大写输出进制数
		cout<<hex<<h<<endl;
		cout.unsetf(ios::uppercase);
		cout<<hex<<h<<endl;
	}
                fclose(stdin);
                 return 0;
}