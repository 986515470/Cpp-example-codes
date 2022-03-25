#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
int main()
{
	float F, c;
	cin >> F;
	c = 5*(F - 32) / 9;
	cout << setiosflags(ios::fixed) << setprecision(2);
	cout << "c=" << c;
	return 0;
}