#include <iostream>
using namespace std;
int main()
{
	int a[10];
	for (int i = 0; i < 10; i++)
	 cin >> a[i];
	cout << endl;
	int i, j, k, l;
	for (i = 0; i <10;i++)
	{
		k = i;
		for (j = i + 1; j < 10;j++)
		{
			if (a[j] > a[k])
				k = j;
		}
		 l = a[i];
		a[i] = a[k];
		a[k] = l;
	}
	for (int i = 0; i < 10; i++)
		cout << a[i] << " ";
	return 0;
}
