#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int n, x, y,k,d;
	cin >> n >> x >> y;
	if((y%x)== 0) k = y / x;
	else if(y% x != 0) k = y / x + 1;
	d = n - k;
	cout << d;
	return 0;
}