#include<iostream>
using namespace std;
int main()
{
	int a[10], i;
	for (i = 0; i <= 9; i++)
		cin >> a[i];
	for (i = 9; i >= 0; i--)
		cout << a[i] << " ";
	return 0;
}