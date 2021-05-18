#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int **matriz(int l, int c)
{
    int i = 0;
    int **matriz = (int **)malloc(sizeof(int *) * l);
    for (i = 0; i < l; i++)
        matriz[i] = (int *)malloc(sizeof(int) * c);
    return matriz;
}
int mochila(int **m, int n, int cap, int vE[], int pE[])
{
    int i, j, k;
    for (i = 0; i < n; i++)
        m[i][i] = 0;

    for (j = 1; j <= n; j++)
    {
        for (k = 1; k <= cap; k++)
        {
            if (pE[j - 1] <= k)
            {
                if ((vE[j - 1] + m[j - 1][k - pE[j - 1]]) > m[j - 1][k])
                {
                    m[j][k] = vE[j - 1] + m[j - 1][k - pE[j - 1]];
                }
                else
                {
                    m[j][k] = m[j - 1][k];
                }
            }
            else
            {
                m[j][k] = m[j - 1][k];
            }
        }
    }

    return m[n][cap];
}

int main(void)
{

    int capMoch;
    int n, i;
    
    scanf("%d", &capMoch);
    scanf("%d", &n);

    int **m = matriz(n + 1, capMoch + 1);

    int valorEle[n];
    int pesoEle[n];
    //int maxM;

    for (i = 0; i <= n; i++)
    {
        scanf("%d %d", &pesoEle[i], &valorEle[i]);
    }

    printf("%d",mochila(m, n, capMoch, valorEle, pesoEle));

}