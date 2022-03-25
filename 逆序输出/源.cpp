#include<iostream>
using namespace std;
int main()
{
	int n, a, b, c, d, e;
	cin >> n;
	if (n > 9999)
		cout << 5 << endl;
	else if (n > 999)
		cout << 4 << endl;
	else if (n > 99)
		cout << 3 << endl;
	else if (n > 9)
		cout << 2 << endl;
	else
		cout << 1 << endl;
	a = n % 10000 % 1000 % 100 % 10;
	b = n % 10000 % 1000 % 100 / 10;
	c = n % 10000 % 1000 / 100;
	d = n % 10000 / 1000;
	e = n / 10000;
	if (e != 0)
	{
		
		cout << e << " " << d << " " << c << " " << b << " " << a << endl;
		cout << a << b << c << d << e << endl;
	}
	else if (d != 0)
	{
		
		cout << d << " " << c << " " << b << " " << a << endl;
		cout << a << b << c << d << endl;
	}
	else if (c != 0)
	{
		
		cout << c << " " << b << " " << a << endl;
		cout << a << b << c << endl;
	}
	else if (b != 0)
	{
		
		cout << b << " " << a << endl;
		cout << a << b << endl;
	}
	else
	{
		cout << a << endl;
		cout << a << endl;
	}
	return 0;
}
