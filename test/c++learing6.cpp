#include<iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	char ch1='Z';
	cout<<ch1<<' '<<int(ch1)<<endl;
	cout<<9/5<<endl;
	cout<<9L/5L<<endl;
	cout<<9.0/5.0<<endl;
	cout<<9.0f/5.0f<<endl;
	cout<<9/5.0<<endl;
	cout<<9.0/5<<endl;
	int a=15,b=9,c;
	double d;
	c=a/b;
	d=double(a)/double(b);
	cout<<c<<' '<<double(c)<<endl;
	cout<<d<<' '<<int(d)<<endl;
	return 0;
}
