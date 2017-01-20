#include <iostream>
#include<stdio.h>
using namespace std;
bool is_prime(int number)
{
    if(number==1)//1不是素数
        return false;
    if(number==2)//2是素数
        return true;
    for(int i=2;i*i<=number;i++)
        if(number%i==0)
            return false;//找到因子就返回false
      return true;
}
int main(int argc, char const *argv[])
{
    freopen("/home/lianbo2006/Project/test/neuacm1388in.txt","r",stdin);
    freopen("/home/lianbo2006/Project/test/neuacm1388out.txt","w",stdout);
    int m,k;
    while(cin>>m)
        {
            for(int i=2;i<=m;++i)
            {
                if(is_prime(i))
                    {
                        cout<<i;
                        k=i+1;
                        break;}
            }
                        for(int i=k;i<=m;++i)
            {
                if(is_prime(i))
                    cout<<' '<<i;
            }
            cout<<endl;
        }
    fclose(stdin);
    fclose(stdout);
    return 0;
}