#include<iostream>
using namespace std;
int main()
{
	int x;
	char a;
	cin >> x;
	if (x < 60)
		a = 'E';
	else
		if (x >= 60)
			if (x >= 80)
				if ((x >= 80) && (x < 90))
					a = 'B';
				else a = 'A';
			else
				if ((x >= 60) && (x < 70))
					a = 'D';
				else a = 'C';
	cout << a;
	return 0;
}