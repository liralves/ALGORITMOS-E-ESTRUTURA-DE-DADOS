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

void removerInicioDescritor(Lista* lista, int valor){
    NoLSE* aux;

    if(lista->tam == 0){
        printf("\nLitsa vazia.\n");
    }
    else{
        aux = lista->inicio;
        lista->inicio = lista->inicio->prox;
        free(aux);
        lista->tam--;

        if(lista->inicio == NULL){
            lista->fim = NULL;
        }
    }
}
void removerInicio(NoLSE** lista){
    NoLSE* aux;

    if(*lista == NULL){
        printf("\nLista vazia.\n");
        return;
    }
    else{
        aux = (*lista);
        (*lista) = (*lista)->prox;
        free(aux);
    }
}

void removerFinalDescritor(Lista* lista){
    NoLSE* aux = lista->fim;;
    NoLSE* anterior = lista->inicio;

    //caso 1: lista vazia;
    if(lista->tam == 0){
        return;
    }
    //caso 1.1: lista com apenas um nó;
    if(lista->inicio == lista->fim){
        lista->inicio = NULL;
        lista->fim = NULL;
    }
    //caso 2: remoção no final e atualiza o penultimo para o último;
    else{
        while(anterior->prox != lista->fim){
            anterior = anterior->prox;
        }
        anterior->prox = NULL;
        lista->fim = anterior;
    }
    free(aux);
    lista->tam--;
}
void removerFinal(NoLSE** lista){
    NoLSE* aux = (*lista);
    NoLSE* anterior = NULL;

    if(*lista == NULL){
        return;
    }

    if(aux->prox == NULL){
        (*lista) = NULL;
    }
    else{
        while(aux->prox != NULL){
            anterior = aux;
            aux = aux->prox;
        }
        anterior->prox = NULL;
    }
    free(aux);
}

NoLSE* buscarDescritor(Lista *lista, int valor){
    NoLSE* aux;
    if(lista->tam == 0){
        printf("\nLista vazia.\n");
        return NULL;
    }

    aux = lista->inicio;
    while(aux != NULL){
        if(aux->info == valor){
            return aux;
        }
        aux = aux->prox;
    }
    return NULL;
}
NoLSE* buscar(NoLSE* lista, int valor){

    if(lista == NULL){
        printf("\nLista vazia.\n");
        return NULL;
    }

    while(lista != NULL){
        if(lista->info == valor){
            return lista;
        }
        lista = lista->prox;
    }
    return NULL;
}