
#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

int main() {
    unsigned long i;
    unsigned long j;
    bool k = true;
    cin >> i >> j;
    do {
        unsigned long a = i;
        unsigned long b = j;
        if (i > j)
            swap(i, j);
        int max = 1;
        int currmax = max;
        cout << a;
        for (; i <= j; i++) {
            for (int x = i; x > 1; currmax++) {
                if (x % 2 == 1)
                    x = 3 * x + 1;
                else
                    x = x / 2;

            }
            if (currmax > max)
                max = currmax;
            currmax = 1;
        }

        cout << " " << b << " " << max;
        if (cin >> i >> j) {
            cout << endl;

        }
        else
            k = false;
    } while (k);

    return 0;
}

int swap(int i, int j) {

    unsigned long temp = i;
    i = j;
    j = temp;

}