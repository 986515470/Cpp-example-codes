#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

double ppt(double j, double k, double l)
{
	double z;
	z = (j + k + l) / 2;
	return z;
}

double mianji(double j, double k, double l)
{
	double s;
	double p;
	p = ppt(j, k, l);
	s = sqrt(p * (p - j) * (p - k) * (p - l));
	return s;
}
int main()
{
	double a, b, c;
	double s;
	cin >> a >> b >> c;
	s = mianji(a, b, c);
	cout << setiosflags(ios::fixed) << setprecision(3) << s;
	return 0;

}