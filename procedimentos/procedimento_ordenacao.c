/*Vamos considerar alguns casos para ordenação de LSEs. 
Ordenação de lista contendo números inteiros, ordenação por nome (Ordem alfabética e lexicográfica)*/

#include <stdio.h>
#include <stdlib.h>
#define TAM_RA 10
#define TAM_NOME 15

//estrutura padrão para nós
typedef struct noLSE{
    int info;
    struct noLSE* prox;
}NoLSE;

//estrutura padrão para listas
typedef struct lista{
    NoLSE* inicio;
    NoLSE* fim;
    int tamanho;
}Lista;

//possivel caso trabalhar com alunos e turmas
typedef struct aluno{
    char ra[TAM_RA];
    char nome[TAM_NOME];
    float media;
    int faltas;
}Aluno;

//utilização de descritor
void inserirOrdenadoCrescente(Lista* lista, int valor){
    NoLSE* atual;
    NoLSE* anterior; 

    //caso 1: lista vazia;
    if(lista->tamanho == 0){
        NoLSE* novoNo = (NoLSE*) malloc(sizeof(NoLSE));
        novoNo->info = valor;
        novoNo->prox = NULL;
        lista->inicio = novoNo;
        lista->fim = novoNo;
        lista->tamanho++;
    }
    //caso 2: lista nao vazia
    else {

        if(valor == lista->inicio->info){
            printf("\nValor repetido.\n");
        }
        else if (valor < lista->inicio->info){
            NoLSE* novoNo = (NoLSE*) malloc(sizeof(NoLSE));
            novoNo->info = valor;
            novoNo->prox = lista->inicio;
            lista->inicio = novoNo;
            lista->tamanho++;

        }   
        else {
            atual = lista->inicio;
            anterior = NULL;

            while(atual != NULL && atual->info < valor){
                anterior = atual;
                atual = atual->prox;
            }

            if(atual != NULL && atual->info == valor){
                printf("\nValor repetido.\n");
            }
            
            NoLSE* novoNo = (NoLSE*) malloc(sizeof(NoLSE));
            novoNo->info = valor;
            anterior->prox = novoNo;
            atual = atual->prox;

            if(atual == NULL){
                lista->fim = novoNo;
            }
        }
    }
    lista->tamanho++;
}

void inserirOrdenadoCrescente(NoLSE** lista, int valor){
    NoLSE* atual = (*lista), *anterior = NULL, *prox;
    NoLSE* novoNo;

    //caso 1: lista vazia;
    if((*lista) == NULL){
        novoNo = (NoLSE*)malloc(sizeof(NoLSE));
        novoNo->info = valor;
        novoNo->prox = NULL;
        (*lista) = novoNo;
    }

    //caso 2: lista não vazia;
    else {
        if((*lista)->info == valor){
            printf("\nValor repetido.\n");
        }
        else if(valor < (*lista)->info){
            novoNo = (NoLSE*)malloc(sizeof(NoLSE));
            novoNo->info = valor;
            novoNo->prox = (*lista);
            (*lista) = novoNo;
        }
        else {
            while(atual != NULL && (*lista)->info < valor){
                anterior = atual;
                atual = atual->prox;
            }
            if(valor == atual->info){
                printf("\nValor repetido.\n");
            }
            novoNo = (NoLSE*)malloc(sizeof(NoLSE));
            novoNo->info = valor;
            anterior->prox = novoNo;
            atual = atual->prox;
        }
    }
}

void somarDescritor(Lista* L1, Lista* L2){
    
}