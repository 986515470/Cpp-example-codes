#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
int main()
{
	int n;
double PI,k=1.0;
	int j;
	cin >> n;
	for (j = 1; j <= n; j++)
	{
		
		if (j % 2 != 0)
			k = k * (j + 1) / j;
		else
			k = k * j / (j + 1);
	}
	cout << setiosflags(ios::fixed) << setprecision(10) << "PI=" << 2 * k << endl;
	return 0;
}