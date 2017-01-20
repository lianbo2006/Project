#include<iostream>
#include<stdio.h>
#include <string>
#include <algorithm>
using namespace std;
int main(int argc, char const *argv[])
{
            freopen("/home/lianbo2006/Project/test/neuacm1109in.txt","r",stdin);
            freopen("/home/lianbo2006/Project/test/neuacm1109out.txt","w",stdout);
            string s,ss,s1;
            while(cin>>s)
            {
                int len=s.length();
                ss=s;

                reverse(s.begin(),s.end());
/*                for(int i=0;i<len;i++)
                {
                    s1=s.substr(i,1);
                    char(s1);
                    ss[i+1]=s1;


                }*/
/*                cout<<s<<endl;
                cout<<ss<<endl;
                cout<<char(s[1])<<endl;
                cout<<char(s[2])<<endl;*/

                if(ss==s)
                    cout<<"Yes"<<endl;
                else
                    cout<<"NO"<<endl;
             }
            fclose(stdin);
            fclose(stdout);
            return 0;
}