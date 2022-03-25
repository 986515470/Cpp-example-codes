#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int x;
	int y = 1;
	cin >> x;
	int i = 1;
	while (i <=( x-1))
	{
		y=(y+1)* 2;
		i++;	
	}
	cout << y;
	return 0;                      
}