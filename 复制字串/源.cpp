#include <iostream>
using namespace std;

int main()
{
	char s[10000] = { 0 }; int n, m, i;
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cin >> s[i];
	}
	cin >> m;

	for (i = m - 1; i < n; i++)
	{
		cout << s[i];
	}
}
