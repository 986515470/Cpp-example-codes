#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
int main()
{
	int n;
	double  k;
	double sn = 0;
	cin >> n;
	cout << "sn=";
	int i = 1;
	while (i <= n)
	{
		k =pow( -1,i-1) / i;
		i++;
		sn = k + sn;	
	}
	cout << setiosflags(ios::fixed) << setprecision(5);
	cout << sn;
	return 0;
}