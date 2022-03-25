#include<iostream>
#include<stdio.h>
#include<math.h>
#include<iomanip>
using namespace std;
int main()
{
	int n;
	double sum = 0.0;
	while (cin >> n && n != EOF)
	{
		if (n <= 70)
			sum += 0.1;
		else
			sum += ceil(1.0 * n / 70) * 0.1;
	}
	cout << fixed << setprecision(1) << sum << "Ԫ" << endl;
	return 0;
}