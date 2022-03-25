#include<iostream>
using namespace std;
int main()
{
	int a[3][3] = {}, i, j, n, k;
	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
		{
			cin >> a[i][j];
		}
	n = a[0][0] + a[1][1] + a[2][2];
	k = a[0][2] + a[1][1] + a[2][0];
	cout << n << " " << k;
	return 0;

}