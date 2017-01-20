#include<iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	char ch;
	int i;
	ch='M';
	i=ch;
	cout<<"ch="<<ch<<endl;
	cout<<"i="<<i<<endl;
	cout.put(ch);
	cout<<endl;
	cout.put('!');
	cout<<"\n";
	cout.put('N');
	cout<<'\n';
	cout.put(i);
	cout<<endl;
	char alarm='\a';
	cout<<alarm;
	cout<<"\aEnter your password:______\b\b\b\b\b\b";
	long password;
	cin>>password;
	cout<<"\apassword verified!"<<endl;
	cout<<"let eat g\u00E2teau.\n";
	return 0;
}