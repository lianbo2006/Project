#include<iostream>
#include <string>
#include<stdio.h>
#include <algorithm> 
using namespace std;
int main(int argc, char const *argv[])
{
	freopen("/home/lianbo2006/Project/test/c++learing10in.txt","r",stdin);
	freopen("/home/lianbo2006/Project/test/c++learing10out.txt","w",stdout);
	string a,b;
	getline(cin,a);
	getline(cin>>ws,b);
	cout<<a<<endl;
	cout<<b;
	fclose(stdin);
                fclose(stdout);
	return 0;
}