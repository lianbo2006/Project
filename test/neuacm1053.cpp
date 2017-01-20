#include<iostream>
#include <stdint.h>
using namespace std;
int main(int argc, char const *argv[])
{
	uint8_t k;
	double s=1,n=2;
                 cin>>k;
                while(s<=k)
                 {
                 	s=s+(1/n);
                 	n+=1;
                 }
                 n=int(n-1);
                 cout<<n<<endl;
	return 0;
}