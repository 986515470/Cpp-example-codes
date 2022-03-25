#include<iostream>
using namespace std;
int age(int n)
{
	int c;
		if (n == 1) c = 10;
		else c = age(n - 1) + 2;
	return c;
}
 
int main()
{  
	int n;
	cin >> n;
	cout << age(n) << endl;
	return 0;
}