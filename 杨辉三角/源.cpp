//c”Ô—‘
#include<stdio.h>
int main()
{
	int A[100][100];
	int n, i, j;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		A[i][i] = 1;
		A[i][0] = 1;
	}
	for (i = 2; i < n; i++)
	{
		for (j = 1; j < i; j++)
		{
			A[i][j] = A[i - 1][j] + A[i - 1][j - 1];
		}
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j <= i; j++)
		{
			printf("%d", A[i][j]);
			if (j != i)
			{
				printf(" ");
			}
		}
		printf("\n");
	}
	return(0);
}
