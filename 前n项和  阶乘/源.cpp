#include<iostream>
using namespace std;
int main()
{
  long  long int  a, s, b; s = 0;
	cin >> a;
	for (int j = 1; j <= a; j++)
	{
		b = 1;
		for (int i = 1; i <= j; i++)
		{
			b *= i;
		}
		s += b;
	}
	cout << s;
}
