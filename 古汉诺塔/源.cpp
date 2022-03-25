#include <iostream>
using namespace std;
int l = 0,y=0;

void move(char A, int n, char C)
{
	l++;
	y++;
	cout<<y<<":" << A << "->" << C << endl;
}

void hanoi(int n, char A, char B, char C)
{

	if (n == 1)
		move(A, 1, C);
	else
	{
		hanoi(n - 1, A, C, B);
		move(A, n, C);
		hanoi(n - 1, B, A, C);
	}
}


int main(void)
{
	int n;
	cin >> n;
	hanoi(n, 'A', 'B', 'C');
	return 0;
}