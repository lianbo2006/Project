#include<iostream>
#define Months 12
using namespace std;
int main(int argc, char const *argv[])
{
	const int Toes=10;
	//Toes=11;
	cout<<"Months="<<Months<<endl;
	cout<<"Toes ="<<Toes<<endl;
	double a=1.0e6;
	cout<<"a ="<<a<<endl;
	cout.setf(ios_base::fixed,ios_base::floatfield);
	cout<<"a ="<<a<<endl;
	const float b=1.0e7F;
	cout<<"b="<<b<<endl;
	//precision problem
	float c=2.34E+22f;
	float d=c+1.0f;
	cout<<"c="<<c<<endl;
	cout<<"d="<<d<<endl;
	cout<<"c-d="<<c-d<<endl;
                 return 0;
}