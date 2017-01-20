#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	/*int n;
	cin >> n;
	char a[6];
	for (int i = 1; i <= n; i++)
	{
		cin >> a;
		int b;
		b=strlen(a);
		if (b==5) cout << "3" << endl;
		else if ((a[0] == 'o'&&a[1] != 'n'&&a[2] == 'e') || (a[0] != 'o'&&a[1] == 'n'&&a[2] == 'e') || (a[0] == 'o'&&a[1] == 'n'&&a[2] != 'e') || (a[0] == 'o'&&a[1] == 'n'&&a[2] == 'e'))
			cout << "1" << endl;
		else cout << "2" << endl;
	}*/
		char a;
		cin >> a;
		cout << a << endl;
		cin >> a;
		cout << a << endl;
		char b[10];
		cin >> b;
		cout << b << endl;
		cout << strlen(b) << endl;
	//system("pause");
	return 0;
}