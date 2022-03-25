#include<iostream>
#include<iomanip>
using namespace std;
int main()
{

    int m, n, r;
    cin >> m >> n >> r;
    double a[100][100], b[100][100], c[100][100];
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < r; j++)
            cin >> b[i][j];
    for (int i = 0; i < m; i++)
        for (int j = 0; j < r; j++)
            for (int k = 0; k < n; k++)
                c[i][j] = c[i][j] + a[i][k] * b[k][j];
    for (int i = 0; i < m; i++)
    {
        {

            for (int j = 0; j < r; j++)
                cout << setiosflags(ios::fixed) << setprecision(2) << c[i][j] << "\t";
        }
        cout << endl;
    }
    return 0;
}