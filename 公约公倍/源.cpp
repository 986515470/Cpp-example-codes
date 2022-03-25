#include<iostream>
using namespace std;
int max(int a, int b)
{
	if (a < b) 
	{ int c = a; a = b; b = c; }
	int d;
	do 
	{ d = a % b; a = b; b = d; } 
	while (d != 0); return(a);
}
int min(int a, int b, int c)
{
	return(a * b / c);
}
int main()
{
	int m, n; cin >> m >> n; cout << max(m, n) << ' ' << min(m, n, max(m, n)); return 0;
}
