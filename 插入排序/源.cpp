#include<iostream>
#include<iomanip>
using namespace std;

int main() {
	int a[10]; int i, j, k;

	for (i = 0; i < 10; i++)
		cin >> a[i];
	for (i = 1; i <= 9; i++)
		for (j = 0; j < 10 - i; j++)
			if (a[j] > a[j + 1]) {
				k = a[j];
				a[j] = a[j + 1];
				a[j + 1] = k;
			}
	for (i = 0; i < 10; i++)
		cout << a[i] << endl;
	return 0;
}