#include<iostream>
#include <iomanip>
using namespace std;
double fact(int n)
{
	double j=1;
	for (int i = 1; i <= n; i++)
		j = j*i;
	//cout << j << endl;
	return j;
}
double mypow(double x, int n)
{
	double x1=x;
	for (int i = 2; i <= n; i++)
		x1 = x1*x;
	//cout << fixed << setprecision(4) << x1 << endl;
	return x1;
}
int main()
{
	double x;
	int n;
	cin >> x;
	cin >> n;
	double s=0;
	for (int a = 1; a <= n; a++)
	{
		int b;
		if (a % 2 == 0) b = -1;
		else b = 1;
		double p = mypow(x, a), q = fact(a);
		s = s + b*(p/q);
	}
	cout << fixed << setprecision(4) << s <<endl;
	cout.unsetf(ios::fixed);
	cout << setprecision(4) << s;
	system("pause");
	return 0;
}