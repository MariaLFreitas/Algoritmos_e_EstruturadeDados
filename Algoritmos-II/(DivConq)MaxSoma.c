#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int somaMax(int vet[], int ini, int fim)
{
    int meio;
    meio = (int)(ini + fim) / 2;

    if (ini < 0 || ini > fim)
    {
        return 0;
    }
    else if (ini == fim)
    {
        if (vet[ini] >= 0)
        {
            return vet[ini];
        }
    }
    else
    {
        if (vet[meio] >= 0)
        {
            return vet[meio] + somaMax(vet, ini, meio - 1) + somaMax(vet, meio + 1, fim);
        }
        else
        {
            return somaMax(vet, ini, meio - 1) + somaMax(vet, meio + 1, fim);
        }
    }
    return 0;
}
int main(void)
{

    int qtd, i, result;

    scanf("%d", &qtd);

    int vet[qtd];

    for (i = 0; i <= qtd; i++)
    {
        scanf("%d", &vet[i]);
    }

    result = somaMax(vet, 0, qtd - 1);
    printf("%d", result);

    return 0;
}