#include<iostream>
#include<stdio.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int s=0,a;
	char c;
	freopen("/home/lianbo2006/Project/test/neuacm1048in.txt","r",stdin);
	freopen("/home/lianbo2006/Project/test/neuacm1048out.txt","w",stdout);
	cin.get(c);
	while(c!=EOF)
	{
		if(c=='-')
		{
			cin>>a;
			s-=a;
		}
		else if(c >='0'&&c<='9')
		{
			ungetc(c,stdin);
			cin>>a;
			s+=a;
		}
		else if(c=='\n')
		{
			cin.get(c);
			if(c=='\n')
			{
				cout<<s<<endl;
				break;
			}
			else
			{
			cout<<s<<endl;
			s=0;
			ungetc(c,stdin);
			}
		}
		cin.get(c);
	}
	fclose(stdin);
                fclose(stdout);
                return 0;
}