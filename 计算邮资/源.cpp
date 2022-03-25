#include<iostream>
using namespace std;
int main()
{
	char t;
	int a, b;
	cin >> a;
	cin >> t;
	if (a <= 1000)
		if (t == 'n')
			b = 8;
		else
			b = 8 + 5;
	else
		if (t == 'n')
			if ((a - 1000) % 500 == 0)
				b = 8 + (a - 1000) / 500 * 4;
			else
				b = 8 + (a - 1000) / 500 * 4 + 4;
		else//当t！=‘n’时，开始加五元
			if ((a - 1000) % 500 == 0)
				b = 8 + (a - 1000) / 500 * 4 + 5;
			else
				b = 8 + (a - 1000) / 500 * 4 + 4 + 5;

	cout << b;
}