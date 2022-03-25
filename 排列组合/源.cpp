
#include<iostream>  
#include<iomanip>  
using namespace std;
int main()
{
	enum color { red, yellow, blue, white, black }; 
	color paixu ;    
	int i, j, k, n = 0, loop;  
	for (i = red; i <= black; i++)  
	{for (j = red; j <= black; j++)  
		{if (i != j)  
			{for (k = red; k <= black; k++)  
				{if (k != i && k != j) 
					{n = n + 1;  
						cout << setw(3) << n;
						for (loop = 1; loop <= 3; loop++)
						{switch (loop)
							{case 1:paixu = color(i); break; 
							case 2:paixu = color(j); break;
							case 3:paixu = color(k); break;
							default:break;	}
							switch (paixu)   
							{
							case red:cout  <<"       red"; break;
							case yellow:cout  << "       yellow"; break;
							case blue:cout  << "       blue"; break;
							case white:cout  << "       white"; break;
							case black:cout << "       black"; break;
							default:break;
							}}cout << endl;
					}
				}
			}
		}
	}
	return 0;
}