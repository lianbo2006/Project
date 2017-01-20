#include<iostream>
#include<stdio.h>
using namespace std;
int a[6]={0};
int b[6]={0};
void search(int k)
{
	if(k==6)
	{
	for (int i = 1; i <=5; i++)
	{
		cout<<b[i];	
	}
	cout<<endl;
	return ;
	}
	for (int i = 1; i <= 5; i++)
	{
		if(a[i]==0)
		{
			b[k]=i;
			a[i]=1;
			search(k+1);
			a[i]=0;
		}
	}
}
int main(int argc, char const *argv[])
{
	freopen("/home/lianbo2006/Project/test/neuacm1229out.txt","w",stdout);
	// int a[6]=0;
	// int b[6]=0;
	search(1);
	fclose(stdout);
	return 0;
}