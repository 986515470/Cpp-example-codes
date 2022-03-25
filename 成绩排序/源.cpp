#include <iostream>
#include <algorithm>
using namespace std;
struct stu
{
	int num;
	char name[10];
	int sum;
}s[100];
bool cmp(stu x, stu z)
{
	if (x.sum > z.sum) {
		return 1;
	}
	else if (x.sum == z.sum) {
		return x.num < z.num;
	}
	else {
		return 0;
	}
}
int main()
{
	int n, i;
	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> s[i].num >> s[i].name >> s[i].sum;
	}
	sort(s, s + n, cmp);
	for (i = 0; i < n; i++) {
		cout << s[i].name << endl;
	}
	return 0;
}