#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


typedef struct GrafoMA GrafoMA;

struct GrafoMA{
   int V; 
   int A;
   int **mat;
};

static int** iniciar_MA(int n){
    int i, j;
    int **mat = (int**) malloc(n * sizeof(int*));

    for (i = 0; i < n; i++)
        mat[i] = (int*) malloc(n * sizeof(int));

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            mat[i][j] = 0;

    return mat;
}


static int valida_vertice(GrafoMA* G, int v){
    return (v >= 0) && (v < G->V);
}


GrafoMA* iniciar_grafoMA(int v){
    GrafoMA* G = (GrafoMA*) malloc(sizeof(GrafoMA));

    G->V = v;
    G->A = 0;
    G->mat = iniciar_MA(G->V);

    return G;
}


int aresta_existe(GrafoMA* G, int v1, int v2){
    return (G != NULL) && valida_vertice(G, v1) && valida_vertice(G, v2) && (G->mat[v1][v2] == 1);
}


void inserir_aresta(GrafoMA* G, int v1, int v2){
    if ((G != NULL) && (valida_vertice(G, v1)) && (valida_vertice(G, v2)) && (!aresta_existe(G, v1, v2))){
        G->mat[v1][v2] = G->mat[v2][v1] = 1;
        G->A++;
    }
}

void liberarGMA(GrafoMA* G){
    if (G != NULL){
        free(G->mat);
        free(G);
    }
}

void regular(GrafoMA *grafo, int tam){
    int i, j, aux=0;
    
    for(i=0;i<tam;i++){
        for(j=0;j<tam;j++){
             if(grafo->mat[i][j] == 0){
                    aux++;
            }
        }
    }
    
    if(aux == tam){
        printf("sim");
    }
    else{
        printf("nao");
    }
}

int main(void){
    int qtd,i,j, elem;
    scanf("%d",&qtd);
    
    GrafoMA *grafo;
    grafo = iniciar_grafoMA(qtd);
    
    for(i=0;i<qtd;i++){
        for(j=0;j<qtd;j++){
            scanf("%d",&elem);
            if(elem == 1){
                inserir_aresta(grafo, i, j);
            }
        }                                
    }
    regular(grafo,qtd);
    
    liberarGMA(grafo);
    
    return 0;
    
}