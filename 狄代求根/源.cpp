#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
int main()
{
	double x, y;
	cin >> x;
	y = sqrt (x);
	cout << setiosflags(ios::fixed) << setprecision(3);
	cout << y;
	
}