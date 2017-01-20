#include<stdio.h>
#include<iostream>
using namespace std;
char s[10][3][4] = {
					{" _ ",
					 "| |",
					 "|_|"},
					{"   ",
					 "  |",
					 "  |"},
					{" _ ",
					 " _|",
					 "|_ "},
					{" _ ",
					 " _|",
					 " _|"},
					{"   ",
					 "|_|",
					 "  |"},
					{" _ ",
					 "|_ ",
					 " _|"},
					{" _ ",
					 "|_ ",
					 "|_|"},
					{" _ ",
					 "  |",
					 "  |"},
					{" _ ",
					 "|_|",
					 "|_|"},
					{" _ ",
					 "|_|",
					 " _|"}
};
int main(int argc, char const *argv[])
{
	freopen("/home/lianbo2006/Project/test/neuacm1004in.txt","r",stdin);
	freopen("/home/lianbo2006/Project/test/neuacm1004out.txt","w",stdout);
	int a,b,c,d;
	while(cin>>a>>b>>c>>d)
	{
		for(int i = 0;i < 3;i++)
			{
				cout<<s[a][i]<<s[b][i]<<s[c][i]<<s[d][i]<<endl;
			}
	}
	fclose(stdin);
               fclose(stdout);
               return 0;
}