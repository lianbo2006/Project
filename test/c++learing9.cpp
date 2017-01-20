#include<iostream>
#include <string>
#include <algorithm> 
using namespace std;
int main(int argc, char const *argv[])
{
           string a;
           a="hello12345";
           cout<<a<<endl;
           reverse(a.begin(),a.end());
           cout<<a<<endl;
           sort(a.begin(),a.end());
           cout<<a<<endl;
            return 0;
}