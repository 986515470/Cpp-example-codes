#include<iostream>
using namespace std;
int main()
{
	void xuanchuzuixiao(int* p1, int* p2);
	int *point1, *point2 ,*point3,a,b,c,d,e,f;
	cin >> a >> b >> c;
	point1 = &a;
	point2 = &b;
	point3 = &c;
	if (a > b) xuanchuzuixiao(point1, point2);
	if (a > c)  xuanchuzuixiao(point1, point3);
	if(b>c)  xuanchuzuixiao(point2, point3);
	
	cout << *point1<<" "<< *point2<<" " << *point3;
	return 0;
}
void  xuanchuzuixiao(int* p1, int* p2)
{
	int temp;
	temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}
