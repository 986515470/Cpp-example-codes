#include <iostream>
#include <stdio.h>
using namespace std;
int a[100];
void pailie(int b[],int k,int m)
{
    if(k == m){
        for(int i = 0;i <= m;i++)
            printf("   %d",b[i]);
        printf("\n");
        }
    else
        for(int i = k; i <= m;i++)
    {
        swap(b[k],b[i]);
        pailie(b,k+1,m);
        swap(b[k],b[i]);
    }
}
 
int main()
{
    int n;
    cin >>  n;
    for(int i = 0; i < n;i++)
    {
        a[i] = i+1;
    }
    pailie(a,0,n-1);
    return 0;
}