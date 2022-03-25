#include <stdio.h>
#include <string.h>
int main() {
    char a[100][100];
    char lin;
    int i, j, n, m, ii, jj;
    int count = 1;
    for (int k = 0; k >= 0; k++)
    {
        memset(a, '0', sizeof(a));
        scanf("%d%d", &n, &m);
        if (n == 0 && m == 0) return 0;
        else
        {
            for (i = 1; i <= n; i++)
                for (j = 1; j <= m; j++)
                {
                    scanf(" %c", &lin);
                    if (lin == '*')
                    {
                        a[i][j] = '*';
                        for (ii = i - 1; ii <= i + 1; ii++) {
                            for (jj = j - 1; jj <= j + 1; jj++) {
                                if (a[ii][jj] != '*') a[ii][jj]++;
                            }
                        }
                    }
                }
            printf("Field #%d:\n", count++);
            for (i = 1; i <= n; i++)
            {
                for (j = 1; j <= m; j++)
                {
                    printf("%c", a[i][j]);
                }
                printf("\n");
            }
        }
    }
    return 0;
}