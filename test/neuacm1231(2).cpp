#include<iostream>
#include <iomanip>
#include<math.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int n;
	double p,m;
	while(cin>>n)
	{
		n=double(n);
		m=pow(2.0,n-1);
		p=1-1/m;
		cout << fixed << setprecision(6) << p <<endl;
	}
	return 0;
}