#include<iostream>
#include <iomanip>
using namespace std;

int main()
{
	int number=5;
	if(bool is_prime(number))
	cout<<number<<endl;
	return 0;
}
bool is_prime(int n){
	if(n==1)
	return false;
	for(int i=2;i*i<=n;i++){//检验到根号n就可以了 
		if(n%i==0)
		return false;
	}
	return true;
}
