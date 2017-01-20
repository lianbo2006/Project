#include<stdio.h>
/*#include<iostream>
std namespace std;*/
int main(int argc, char const *argv[])
{
	/*freopen("/home/lianbo2006/Project/test/neuacm1162in.txt","r",stdin);
	freopen("/home/lianbo2006/Project/test/neuacm1162out.txt","w",stdout);*/
	int n;
	int a[1000005]={0};
	for (int i = 0; i <=1000; ++i)
	{
		for (int j = i; j <= 1000; ++j)
		{
			if ((i*i+j*j)>1000000) break;
			a[i*i+j*j]++;
		}
	}
	while(scanf("%d",&n)!=EOF)
	{
		if(a[n]!=0)
		{
			printf("%d\n",a[n]);
		}
		else
		{
			printf("No Solution!\n");
		}

	}
/*	fclose(stdin);
	fclose(stdout);*/
	 return 0;
}