#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


int backtracking(int num, int cap, int valor[], int peso[])
{
  int aux1, aux2;

  if(num < 0)
    return 0;
  else if(peso[num] > cap)
    return backtracking( num-1,cap, valor, peso);
  else {
    aux1 = backtracking(num-1,cap, valor, peso);
    aux2 = valor[num] + backtracking( num-1,cap - peso[num], valor, peso);

    if(aux1 > aux2)
      return aux1;

    return aux2;
  }

}

int main(void)
{

    int capMoch;
    int n, i;
    
    scanf("%d", &capMoch);
    scanf("%d", &n);

    int valorEle[n];
    int pesoEle[n];

    for (i = 0; i < n; i++)
    {
        scanf("%d %d", &pesoEle[i], &valorEle[i]);
    }

    printf("%d",backtracking( n-1, capMoch, valorEle, pesoEle));

}