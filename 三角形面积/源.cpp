#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
int main()
{
	float x1, y1, x2, y2, x3, y3,s;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
	s =  sqrt((x1 * y2 + x2 * y3 + x3 * y1 - x3 * y2 - x2 * y1 - x1 * y3)* (x1 * y2 + x2 * y3 + x3 * y1 - x3 * y2 - x2 * y1 - x1 * y3))/2;
	cout << setiosflags(ios::fixed) << setprecision(2);
	cout << s;
	return 0;

}