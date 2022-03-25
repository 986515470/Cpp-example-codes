#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
int main()
{
	double PI = 3.1415;
	float r, h, C1, Sa, Sb, Va, Vb;
	cin >> r >> h;
	C1 = 2*PI * r;
	Sa = PI * r * r;
	Sb = 4*PI * r * r;
	Va =( PI *r*r*r*4)/3;
	Vb = PI * r * r * h;
	cout << setiosflags(ios::fixed) << setprecision(2);
	cout<<"C1=" << C1 << endl;
	cout<<"Sa=" << Sa << endl;
	cout<<"Sb=" << Sb << endl;
	cout<<"Va=" << Va << endl;
	cout<<"Vb="<< Vb << endl;
	return 0;
}
