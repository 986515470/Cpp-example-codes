#include <iostream>
#include<cmath>
#include <iomanip>
using namespace std;
int main()
{
	float r1, r2, R;
	cin >> r1 >> r2;
	R = 1 / (1 / r1 + 1 / r2);
	cout << setiosflags(ios::fixed) << setprecision(2);
	cout << R;
	return 0;
}
