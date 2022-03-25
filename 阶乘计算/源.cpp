#include<iostream>
using namespace std;
long fac(int);
int main()
{
	int n;
	long long int y;
	cin >> n;
	cout << n << "!=";
	y = fac(n);
	cout << y << endl;
	return 0;
}
long fac(int n)
{
	long long int f;
	if (n == 1) f = 1;
	else f = fac(n - 1) * n;
	return f;
}