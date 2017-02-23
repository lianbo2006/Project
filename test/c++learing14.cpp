#include <stdio.h>
int fun()
{
	static int s=0;
	s+=1;
	return s;
}
int main(int argc, char *argv[])
{
	int n,i=0;
	while(argv[1][i]!='\0')
	{
		n=fun();i++;
	}
	printf("%d\n",n*argc );
	return 0;
}
