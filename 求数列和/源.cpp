#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int a,b,n,j=0,i=0,k=0;
	cin >> a>>n;
	while (i <=(n-1))
	{
		b = a * pow(10, i);
		j = b + j;
		k = j + k;
		i++;

	}
	cout << k;
	return 0;
}