#include<iostream>
#include <iomanip>
using namespace std;
double mypow(double x, int n)
{
	double x1=x;
	for (int i = 1; i < n; i++)
		x1 *= x;
	return x1;
}
int main(int argc, char const *argv[])
{
	int n;
	double p,m;
	while(cin>>n)
	{
		n=double(n);
		m=mypow(2,n-1);
		p=1-1/m;
		cout << fixed << setprecision(6) << p <<endl;
	}
	return 0;
}