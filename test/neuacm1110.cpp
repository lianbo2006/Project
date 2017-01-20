#include<iostream>
#include<iomanip>
#include <stdio.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int a,n = 0;
	int sum = 0;
	double avg;
	while(scanf("%d%%",&a)!=EOF)
	{
		n++;
		sum += a;
	}
	avg = double(sum) / 100 / n;
	cout<<fixed<<setprecision(4)<<avg<<endl;
	return 0;
}