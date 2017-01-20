#include<iostream>
#include<iomanip>
#include<cmath>
#include <stdio.h>
using namespace std;
double distance(int x,int y,int x1,int y1,int x2,int y2)
{
	int a,b,c;
	double d;
	a=y2-y1;
	b=-x2+x1;
	c=x2*y1-y2*x1;
	d=abs(a*x+b*y+c)/sqrt(a*a+b*b);
	return d;
}
int main(int argc, char const *argv[])
{
	freopen("/home/lianbo2006/Project/test/neuacm1389in.txt","r",stdin);
	freopen("/home/lianbo2006/Project/test/neuacm1389out.txt","w",stdout);
	int x,y,r,x1,y1,x2,y2;
	while(cin>>x)
	{
		cin>>y>>r>>x1>>y1>>x2>>y2;
		if (distance(x,y,x1,y1,x2,y2) < r)
			cout<<2<<endl;
		else if (distance(x,y,x1,y1,x2,y2)==r)
			cout<<1<<endl;
		else
			cout<<0<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}