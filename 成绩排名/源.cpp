#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include <algorithm>
using namespace std;
const int N = 110;
struct node
{
	int id;
	string name;
	int grade[N];
	int sum;
}stu[N];
bool cmp(node a, node b)
{
	if (a.sum == b.sum)
		return a.id < b.id;
	return a.sum > b.sum;
}
int main()
{
	int n, m, num;
	cin.sync_with_stdio(false);
	while (cin >> n >> m) {
		for (int i = 0; i < n; i++) {
			cin >> stu[i].id >> stu[i].name;
			stu[i].sum = 0;
			for (int j = 0; j < m; j++) {
				cin >> stu[i].grade[j];
				stu[i].sum += stu[i].grade[j];
			}
		}
		sort(stu, stu + n, cmp);
		for (int i = 0; i < n; i++) {
			cout << stu[i].id << " " << stu[i].name;
			for (int j = 0; j < m; j++) {
				cout << " " << stu[i].grade[j];
			}
			if (i == 0) num = 1;
			else if (stu[i].sum != stu[i - 1].sum)
				num = i + 1;
			cout << " Sum = " << stu[i].sum << " Ranking = " << num << endl;
		}
	}
	return 0;
}