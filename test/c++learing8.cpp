#include<iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int a[5]={1,2,3,4,5};
	for (int i = 0; i < 5; ++i)
	{
		/* code */
		cout<<a[i]<<' ';
	}
	cout<<endl;
	for (int i = 0; i < 5; i++)
	{
		/* code */
		cout<<a[i]<<' ';
	}
	cout<<endl;
	int i=0,b;
	b=i++;
	cout<<b<<endl;
	i=0;
	b=++i;
	cout<<b<<endl;
	return 0;
}