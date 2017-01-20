#include<iostream>
#include<iomanip>
#include<cmath>
#include <stdio.h>
using namespace std;
int main(int argc, char const *argv[])
{
	freopen("/home/lianbo2006/Project/test/neuacm1032in.txt","r",stdin);
	freopen("/home/lianbo2006/Project/test/neuacm1032out.txt","w",stdout);
	int n,s;
	while(cin>>n)
	{
			double a[n+2][3];
		for (int i = 0; i <=n+1; ++i)
		{
			for (int j = 0; j <=2; ++j)
			{
			cin>>a[i][j];
			}
		}
		double cen[3],dis,dis1;
		for (int i = 0; i <=2; ++i)
		{
			cen[i]=(a[n][i]+a[n+1][i])/2.0;
		}
		dis=pow(a[0][0]-cen[0],2)+pow(a[0][1]-cen[1],2)+pow(a[0][2]-cen[2],2);
		dis1=dis;
		s=0;
		for (int i = 1; i <=n-1; ++i)
		{
			dis=pow(a[i][0]-cen[0],2)+pow(a[i][1]-cen[1],2)+pow(a[i][2]-cen[2],2);
			if(dis<dis1)
			{
				s=i;
				dis1=dis;
			}
		}
	cout<<fixed<<setprecision(3)<<a[s][0]<<' '<<a[s][1]<<' '<<a[s][2]<<endl;
	cout.unsetf(ios::fixed);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}