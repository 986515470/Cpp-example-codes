#include <iostream>
using namespace std;
int main() {
	int a, b[10], k, i;
	cin >> a;
	for (i = 1; ; i++)
	{
		b[i] = a % 8;
		a = a / 8;
		if (a == 0) break;
	}
	for (k = i; k >= 1; k--) {
		cout << b[k];
	}
	return 0;
}
