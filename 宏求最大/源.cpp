#include<iostream>
#include<iomanip>
using namespace std;
int max(int j, int n, int l)
{
	int z;
	if (j > n) z = j;
	else z = n;
	if (z > l)  z = z;
	else z = l;
	return(z);
}
int main()
{
	int x, y, z;
	double k, c;
	cin >> x >> y >> z;
	if (x > y) k = x;
	else k = y;
	if (k > z)  k = k;
	else k = z;
	cout << setiosflags(ios::fixed) << setprecision(3) << k << endl;
	c = max(x, y, z);
	cout << setiosflags(ios::fixed) << setprecision(3) << c << endl;
	return 0;

}