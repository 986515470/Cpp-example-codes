#include<iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int exchange(char);
int slove(int, int);
int panduan(char);
int main() {
    char a[1000], b[100];
    int i, key1, key2, j;
    cin>>a;
    cin>>b;
    int max;
    key1 = strlen(a);
    key2 = strlen(b);
    int q[100], w[100];
    for (i = 0; i < key1; i++)
        q[i] = exchange(a[i]); 
    for (i = 0; i < key2; i++)
        w[i] = exchange(b[i]);
    if (key1 > key2) {
        for (i = key2; i < key1; i++)
            w[i] = w[i % key2];
    }
    int g[1000];
    for (i = 0; i < key1; i++)
    {
        if (exchange(a[i]) == -1) g[i] = a[i];
        else
        {
            g[i] = slove(q[i], w[i]) + panduan(a[i]);
        }
    }
    for (i = 0; i < key1; i++)
    {
        printf("%c", g[i]);
    }
    return 0;

}
int exchange(char a)
{
    if (a >= 'A' && a <= 'Z') return (int)a - 65;
    else if (a >= 'a' && a <= 'z')return (int)a - 97;
    else return -1;
}
int slove(int a, int b)
{
    if (a + b > 25) return a + b - 26;
    else return a + b;
}
int panduan(char a)
{
    if (a >= 'A' && a <= 'Z') return 65;
    else return 97;
}