#include<iostream>
using namespace std;
int ctof(int a)
{
    return a/5*9+32;
}
int main(int argc, char const *argv[])
{
	    int i;
    for(i = -100;i <= 150;i+=5)
    	cout<<"c="<<i<<"->f="<<ctof(i)<<endl;
    return 0;
}