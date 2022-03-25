#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
int main()
{
	double x1,x2;
	 char a;
	 cin >> x1 >> x2 >> a;
	 cout << setiosflags(ios::fixed) << setprecision(2);
	 if ((a != '+') && (a != '-') && (a != '*') && (a != '/'))
		 cout << "Invalid operator!";
	 else
		 if (a == '+')		
	    cout << x1+x2;
	  if (a == '-') 	
	     cout << x1-x2;
	  if (a == '*') 
	     cout << x1*x2;
	  if (a == '/') 
	    if (x2 == 0) 
			cout << "Divided by zero!";
	  else			
			cout << x1 / x2;  
	  return 0;
}                  