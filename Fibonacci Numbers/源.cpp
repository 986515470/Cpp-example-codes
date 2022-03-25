#include <iostream>
#include <cmath>
#include <string.h>
using namespace std;
void a(int n)
{
	int bbb[1000];
	int aaa[1000];
	memset(bbb, 0, sizeof(bbb));memset(aaa, 0, sizeof(aaa));
	bbb[0] = 1;
	aaa[0] = 1;
	int k = 999;
	int i = 1;
	int a, b;
	while (i < n)
	{	
		while (k >= 0)
		{
			if (bbb[k] != 0)
				break;
			k--;
		}
		a = k;
		k = 999;
		while (k >= 0)
		{
			if (aaa[k] != 0)
				break;
			k--;
		}
		b = k;
		int temp;
		if (a > b)
			temp = a;
		else
			temp = b;
		k = 0;
		while (k <= temp)
		{
			if (i % 2 != 0)
			{
				bbb[k] = bbb[k] + aaa[k];
				if (bbb[k] > 9)
				{
					bbb[k + 1]++;
					bbb[k] = bbb[k] - 10;
				}
			}
			else
			{
				aaa[k] = bbb[k] + aaa[k];
				if (aaa[k] > 9)
				{
					aaa[k + 1]++;
					aaa[k] = aaa[k] - 10;
				}
			}
			k++;
		}
		k = 999;
		i++;
	}
	if (n == 1)
		cout << 1;
	else if (n == 2)
		cout << 1;
	else
	{
		if (i % 2 != 0)
		{
			int m = 999;
			while (m >= 0)
			{
				if (bbb[m] != 0)
					break;
				m--;
			}
			while (m >= 0)
			{
				cout << bbb[m];
				m--;
			}
		}
		if (i % 2 == 0)
		{
			int m = 999;
			while (m >= 0)
			{
				if (aaa[m] != 0)
					break;
				m--;
			}
			while (m >= 0)
			{
				cout << aaa[m];
				m--;
			}
		}
	}

}
int main()
{
	int n;
	while (cin >> n)
	{
		a(n);
		cout << endl;
	}
	return 0;
}
