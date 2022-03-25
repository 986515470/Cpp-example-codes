
#include <iostream>
using namespace std;
int64_t Fib(int n)
{
	if (n==0)
		return 0;
	else if (n == 1)
		return 1;
	else
		return Fib(n - 1) + Fib(n - 2);
}

int main(int argc, char const* argv[])
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << Fib(i) << endl;
	}

	return 0;
}
