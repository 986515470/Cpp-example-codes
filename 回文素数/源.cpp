#include<iostream>
using namespace std;
bool sushu(int n)
{
	bool su = true;
	if (n <= 1)
		return false;
	for (int i = 2; i <= n / 2; i++)
		if (n % i == 0)
		{
			su = false;
			break;
		}
	return su;
}
bool huiwen(int n)
{
	int m = 0;
	int k = n;
	while (k)
	{
		int r = k % 10;
		m = m * 10 + r;
		k = k / 10;
	}
	if (m == n)
		return true;
	else
		return false;
}
int main()
{
	int a, b, count;
	while (cin >> a >> b)
	{
		count = 0;
		if (a == 0 && b == 0)break;
		for (int i = a; i <= b; i++)
			if (huiwen(i) && sushu(i))
				count++;
		cout << count << endl;
	}
	return 0;
}