#include <iostream>
#include<cmath>
#include <iomanip>
using namespace std;
int main()
{
	double p(double x);
	double a, b;
	cin >> a >> b;
	double fa = p(a), fb = p(b), fm;
	cout << setiosflags(ios::fixed) << setprecision(3);
	while (b - a > 0.00001)
	{
		fm = p((a + b) / 2);
		if (fm == 0) break;
		if (fm * fa < 0) b = (a + b) / 2;
		else if (fm * fb < 0) a = (a + b) / 2;
	} ;
	cout << "x="<< (b + a) / 2;
	return 0;
}
double p(double x)
{
	double k;
	k = 2 * x * x * x - 4 * x * x + 3 * x - 6;
	return k;
}