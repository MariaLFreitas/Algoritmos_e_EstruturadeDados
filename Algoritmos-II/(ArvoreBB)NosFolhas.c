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

void nosFolha(No *arvore)
{
    int cont = 0;
    if (arvore != NULL)
    {
        if (arvore->esq == NULL && arvore->dir == NULL){
            //printf(" %d", arvore->item);
            cont = cont + 1;
        }
        else
        {
            nosFolha(arvore->esq);
            nosFolha(arvore->dir);
        }
    }
     printf("%d",cont);
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
int main()
{
    int qtdN, i, valor;
    scanf("%d", &qtdN);
    No *arvore;
    scanf("%d", &valor);
    arvore = cria(valor);

    for (i = 0; i <= qtdN; i++)
    {
        scanf("%d", &valor);
        insere(arvore, valor);
    }

    nosFolha(arvore);

    return 0;
}


// #include <stdio.h>
// #include <string.h>
// #include <math.h>
// #include <stdlib.h>

// typedef struct No No;

// struct No
// {
//     int item;
//     No *dir;
//     No *esq;
// };

// No *cria(int chave)
// {
//     No *no = (No *)malloc(sizeof(No));
//     no->item = chave;
//     no->esq = NULL;
//     no->dir = NULL;

//     return no;
// }

// int libera(No *no)
// {
//     if (no != NULL)
//     {
//         free(no);
//         return 1;
//     }
//     return 0;
// }
// No *procura(No *arvore, int valor)
// {
//     if (arvore != NULL)
//         if (arvore->item == valor)
//             return arvore;
//         else if (valor < arvore->item)
//             return procura(arvore->esq, valor);
//         else
//             return procura(arvore->dir, valor);
//     else
//         return NULL;
// }

// void nosFolha(No *arvore)
// {
//     if (arvore != NULL)
//     {
//         if (arvore->esq == NULL && arvore->dir == NULL)
//             printf(" %d", arvore->item);
//         else
//         {
//             nosFolha(arvore->esq);
//             nosFolha(arvore->dir);
//         }
//     }
// }

// No *insere(No *arvore, int valor)
// {
//     if (arvore == NULL)
//         arvore = cria(valor);
//     else if (valor < arvore->item)
//         arvore->esq = insere(arvore->esq, valor);
//     else
//         arvore->dir = insere(arvore->dir, valor);

//     return arvore;
// }
// int main()
// {
//     int qtdN, i, valor;
//     scanf("%d", &qtdN);
//     No *arvore;
//     scanf("%d", &valor);
//     arvore = cria(valor);

//     for (i = 0; i <= qtdN; i++)
//     {
//         scanf("%d", &valor);
//         insere(arvore, valor);
//     }

//     nosFolha(arvore);

//     return 0;
// }