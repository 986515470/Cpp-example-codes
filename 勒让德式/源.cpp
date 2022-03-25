 #include <iostream>
#include<cmath>
#include <stdio.h>
using namespace std;
 double Leg(double n, double x)
 {
	     double ans;
	    if (n == 0)
		     ans = 1;
	     else if (n == 1)
		     ans = x;
	     else ans = ((2 * n - 1) * x * Leg(n - 1, x) - (n - 1) * Leg(n - 2, x)) / n;
	     return ans;
	 }

 int main()
 {	     int n;
	     double x;
	   cin>>n;
	     for (x = -1; x <= 1.02; x = x + 0.02)
		    {
		        double leg;
		         leg = Leg(n, x);
		         printf("%.4lf\n", leg);
		     }
	     return 0;
	 }