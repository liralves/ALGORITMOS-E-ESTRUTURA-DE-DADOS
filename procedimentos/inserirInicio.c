#include <stdio.h>
#include <stdlib.h>

typedef struct noLSE{
    int info;
    struct noLSE* prox;
}NoLSE;
typedef struct lista{
    NoLSE* inicio;
    NoLSE* fim;
    int tam;
}Lista;


void inserirInicioDescritor(Lista* lista, int valor){
    NoLSE* novoNo;

    if(lista->tam == 0){
        novoNo = (NoLSE*) malloc(sizeof(NoLSE));
        novoNo->info = valor;
        novoNo->prox = NULL;
        lista->inicio = novoNo;
        lista->fim = novoNo;
        lista->tam++;
    }
    else{
        novoNo->prox = lista->inicio;
        lista->inicio = novoNo;
        lista->tam++;
    }
    printf("Inserção realizada.\n");
}
void inserirInicio(NoLSE** lista, int valor){
    NoLSE* novoNo;

    if(lista == NULL){
        novoNo = (NoLSE*) malloc(sizeof(NoLSE));
        novoNo->info = valor;
        novoNo->prox = NULL;
        (*lista) = novoNo;
    }
    else{
        novoNo->prox = (*lista);
        (*lista) = novoNo;
    }
}

void inserirFinalDescritor(Lista* lista, int valor){
    NoLSE* novoNo;

    if(lista->tam == 0){
        novoNo = (NoLSE*) malloc(sizeof(NoLSE));
        novoNo->info = valor;
        novoNo->prox = NULL;
        lista->inicio = novoNo;
        lista->fim = novoNo;
        lista->tam++;
    }
    else{
        novoNo = (NoLSE*) malloc(sizeof(NoLSE));
        novoNo->info = valor;
        lista->fim->prox = novoNo;
        novoNo->prox = NULL;
        lista->tam++;
    }
}

void inserirFinal(NoLSE** lista, int valor){
    NoLSE* novoNo;
    NoLSE* aux = (*lista);
    NoLSE* anterior = NULL;

    if(*lista == NULL){
        novoNo = (NoLSE*) malloc(sizeof(NoLSE));
        novoNo->info = valor;
        novoNo->prox = NULL;
    }
    else{
        while(aux->prox != NULL){
            anterior = aux;
            aux = aux->prox;
        }
        aux->prox = novoNo;
        novoNo->prox = NULL;
    }
}