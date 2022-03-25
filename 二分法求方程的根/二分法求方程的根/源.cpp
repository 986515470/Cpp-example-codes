#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
int main()
{
    double a, b, c, fa, fb, fc;

    do
    {
        cin >> b >> c;
        fb = 2 * b * b * b - 4 * b * b + 3 * b - 6;
        fc = 2 * c * c * c - 4 * c * c + 3 * c - 6;
    } while (fb * fc >= 0);

    do
    {
        a = (b + c) / 2;
        fa = 2 * a * a * a - 4 * a * a + 3 * a - 6;
        if (fa * fb < 0)
        {
            c = a;
            fc = fa;
        }
        else
        {
            b = a;
            fb = fa;
        }
    } while (fabs(fa) >= 1e-5);
    cout << setiosflags(ios::fixed) << setprecision(3) << "x=" << a;
    return 0;
}