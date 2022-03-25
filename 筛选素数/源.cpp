
#include<iostream>
using namespace std;
int main( )

{
	int i, j, k, l, m, n;
	int a[10000];
	cin >> n;
	for (i = 2; i <= n; i++)
		a[i] = i;
	for (j = 2; j <= n; j++)
		for (l = j + 1; l <= n; l++)
			if (l % j == 0)
				a[l] = 0;
	for (m = 2; m <= n; m++)
		if (a[m] != 0)
			cout << a[m] << endl;
	return 0;
}
