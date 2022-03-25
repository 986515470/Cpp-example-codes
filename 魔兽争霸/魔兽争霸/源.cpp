#include <iostream>
using namespace std;
int main()
{
	int a;
	double  b,c,d,e,f,g;
	cin >> a;
	while (a != 0)
	{
		cin >> b >> c >> d >> e >> f>>g;
		if (((b - d) / (c - e) == (f - d) / (g - e) && (b - d)/ (c - e) == (f - b) / (g - c)) && (((g >= e) && (g <= c)) || ((g <= e) && (g >= c))))
			cout << "yes";
		else
			cout << "no";
		a--;
	}
}
