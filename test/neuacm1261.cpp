#include<iostream>
#include <stdio.h>
using namespace std;
int main(int argc, char const *argv[])
{
	freopen("/home/lianbo2006/Project/test/neuacm1261in.txt","r",stdin);
	freopen("/home/lianbo2006/Project/test/neuacm1261out.txt","w",stdout);
	int n,a;
	while(cin>>n)
	{
	for (int i = 0; i <n; i++)
	{
		cin>>a;
		char b=char(a);
		cout<<b;
	}
	cout<<endl;
	}
                fclose(stdin);
	fclose(stdout);
	return 0;
}