#include<iostream>
using namespace std;
int main()
{
	float x, y;
	cin >> x >> y;
	if ((x * x <= 1) && (y * y <= 1))
		cout << "yes";
	else
		cout << "no";
	return 0;
}