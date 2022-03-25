#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
int main()
{
	int n;
	double x, rate, y;
	cin >> x >> rate >> n;
	y = x * pow(1 + rate, n);
	cout << setiosflags(ios::fixed) << setprecision(3);
	cout << y;
	return 0;
}