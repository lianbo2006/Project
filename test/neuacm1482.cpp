#include<iostream>
#include<stdio.h>
#include<stdint.h>
using namespace std;
int DELTA(uint64_t a,uint64_t b,uint64_t c)
{
    return b*b-4*a*c;
}
int main(int argc, char const *argv[])
{
            freopen("/home/lianbo2006/Project/test/neuacm1482in.txt","r",stdin);
            freopen("/home/lianbo2006/Project/test/neuacm1482out.txt","w",stdout);
            uint64_t a, b,c;
            int t;
            cin>>t;
            for (int i = 0; i < t; ++i)
                      {
                          cin>>a>>b>>c;
                          /*cout<<a<<' '<<b<<' '<<c<<endl;*/
                          if(a==0)
                          {
                            if(b==0)
                            {
                                if(c==0)
                                    cout<<"multiple solution"<<endl;
                                else 
                                    cout<<"no solution"<<endl;
                            }
                            else 
                                cout<<"one solution"<<endl;
                          }
                          else
                          {
                            if(DELTA(a, b, c)>0)
                            cout<<"multiple solution"<<endl;
                        else if(DELTA(a, b, c)==0)
                            cout<<"one solution"<<endl;
                        else
                            cout<<"no solution"<<endl;
                          }
                      }          
            fclose(stdin);
            fclose(stdout);
            return 0;
}