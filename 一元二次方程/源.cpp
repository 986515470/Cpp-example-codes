#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
int main()
{
     double a,b,c,d,x,k;
	cin >> x >> a >> b >> c>> d;
		k = a*x*x*x + b*x*x + c*x + d;
		cout << setiosflags(ios::fixed) << setprecision(5);
		cout  << k << endl;
	return 0;
}
