#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int k ,n;
	cin >> n; 
		cout << n;
	k = n % 7;
	    if (k == 1)  cout << "���������";
		if (k == 2) cout << "���������";
		if (k == 3)  cout << "���������";
		if (k == 4)  cout << "���������";
		if (k == 5)  cout << "�������һ";
		if (k == 6)  cout << "������ڶ�";
		if (k == 0)  cout << "���������";

		return 0;
}