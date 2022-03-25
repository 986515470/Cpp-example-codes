#include <iostream>
using namespace std;
int main()
{
	int year;
	bool leap;
	cin >> year;
	if (year % 4 == 0)
	{
		if (year % 100 == 0)
		{
			if (year % 400 == 0)
				leap = true;
			else
				leap = false;
		}
		else
			leap = true;
	}
	else
		leap = false;
	if (leap)
		cout << " yes";
	else
		cout << " no";
	return 0;
}
