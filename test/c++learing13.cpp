#include <stdio.h>
int main(int argc, char const *argv[])
{
	int a=1,b=2,c=2,t;
	while(a<b<c)
	{
		t=a;a=b;b=t;
		c--;
		printf("%d,%d,%d\n",a,b,c);
	}
	// printf("%d,%d,%d\n",a,b,c);
	return 0;
}
