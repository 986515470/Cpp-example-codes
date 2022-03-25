#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int k ,n;
	cin >> n; 
		cout << n;
	k = n % 7;
	    if (k == 1)  cout << "天后星期四";
		if (k == 2) cout << "天后星期五";
		if (k == 3)  cout << "天后星期六";
		if (k == 4)  cout << "天后星期日";
		if (k == 5)  cout << "天后星期一";
		if (k == 6)  cout << "天后星期二";
		if (k == 0)  cout << "天后星期三";

		return 0;
}