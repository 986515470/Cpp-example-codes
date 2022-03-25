#include<iostream>
#include<string>
using namespace std;
struct xuefen
{
	int num;
	int score1;
	int score2;
};
void input(xuefen* a, int n)
{
	for (int i = 0; i < n; i++)
		cin >> a[i].num >> a[i].score1 >> a[i].score2;
}
void fenshuxiangjia(xuefen* a, int n)
{
	int k = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i].score1 >= 60 || a[i].score2 >= 60)
			k = k + a[i].num;
		else k = k + 0;
	}
	cout << k;
}
int main()
{
	int n;
	cin >> n;
	xuefen a[100];
	input(a, n);
	fenshuxiangjia(a, n);
	return 0;
}