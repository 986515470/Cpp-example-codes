#include<iostream>
using namespace std;
int main()
{
	int a[15] = { 15,14,13,12,11,10,9,8,7,6,5,4,3,2,1 }, i, l, h, m, n, f = 1;
	cin >> n;
	l = 0;
	h = 14;
	while (l <= h)
	{
		m = (l + h) / 2;
		if (n > a[m])
			h = m - 1;
		else if (n < a[m])
			l = m + 1;
		else if (n == a[m])
		{
			f = 0;
			cout << m;
			break;
		}
	}
	if (f)printf("-1\n");
	return 0;
}