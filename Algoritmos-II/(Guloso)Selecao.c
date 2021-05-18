#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct
{
    int inicio;
    int fim;
} Horarios;

// void insercao (Horarios *vet, int tam){
//     int i, j;
//     Horarios aux;

//     for (i=1; i<tam; i++){
//         aux = vet[i];
//         for(j = i; (j>0 && aux.fim <= vet[j - 1].fim); j--){

//             vet[j] = vet[j - 1];
//         }
//         vet[j] = aux;
//        printf("\nvet: %d",vet[j].inicio );
//     }

// }

int crescente( const void *a, const void *b){
    if((*(Horarios*)a).fim == (*(Horarios*)b).fim){
        return 0;
    }
    else{
        if((*(Horarios*)a).fim < (*(Horarios*)b).fim){
            return -1;
        }
        else
            return 1;
    }
}
void aulasPossiveis(Horarios *vet, int tam)
{
    int fim;
    int aux[tam];
    int i = 0;

    if (tam > 0)
    {
        aux[i] = i;
        fim = vet[i].fim;
        for (i = 1; i < tam; i++)
        {
            if (vet[i].inicio > fim)
            {
                fim = vet[i].fim;
                aux[i] = i;
            }
            else
            {
                aux[i] = -1;
            }
        }
        printf("Aulas alocadas:");
        for (i = 0; i < tam; i++)
        {
            if (aux[i] != -1)
            {
                printf(" %d", aux[i]);
            }
        }
    }
    // if (tam == 0)
    // {
    //     return 0;
    // }
    // else
    // {
    //     return -1;
    // }
}

int main(void)
{
    int n;
    Horarios *horarios;
    int i;

    scanf("%d", &n);
    horarios = malloc(n * sizeof(Horarios));

    for (i = 0; i <= n; i++)
    {
        scanf("%d %d", &horarios[i].inicio, &horarios[i].fim);
    }

    qsort(horarios, n, sizeof(Horarios),crescente);
    aulasPossiveis(horarios, n);

    return 0;
}