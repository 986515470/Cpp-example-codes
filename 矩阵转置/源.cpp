#include<iostream>
using namespace std;
int main()
{
	int a[3][3] = {}, i, j;
	int b[3][3];
	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
		cin >> a[i][j];	
	for (i = 0; i <= 2; i++)
	{	for (j = 0; j <= 2; j++)
			b[j][i] = a[i][j];
	}
	for (i = 0; i <= 2; i++)
	{
		for (j = 0; j <= 2; j++)
			cout << b[i][j] << " "<< endl;
	}
	return 0;
}