#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct no No;

struct no
{
    int item;
    No *dir;
    No *esq;
};

No *cria(int chave)
{
    No *no = (No *)malloc(sizeof(No));
    no->item = chave;
    no->esq = NULL;
    no->dir = NULL;

    return no;
}

No *insere(No *arvore, int valor)
{
    if (arvore == NULL)
        arvore = cria(valor);
    else if (valor < arvore->item)
        arvore->esq = insere(arvore->esq, valor);
    else
        arvore->dir = insere(arvore->dir, valor);

    return arvore;
}

int alturaA(No *arvore)
{
    int ladoE;
    int ladoD;

    if (arvore != NULL)
    {
        ladoE = alturaA(arvore->esq);
        ladoD = alturaA(arvore->dir);

        if (ladoE > ladoD)
            return ladoE + 1;
        else
            return ladoD + 1;
    }

    return 0;
}

int main()
{
    int qtdN, i, valor, aux;
    scanf("%d", &qtdN);
    No *arvore;
    scanf("%d", &valor);
    arvore = cria(valor);

    for (i = 0; i < qtdN; i++)
    {
        scanf("%d", &valor);
        insere(arvore, valor);
    }
    aux = alturaA(arvore);
    printf("%d", aux - 1);
    return 0;
}
