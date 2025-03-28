#include <stdio.h>
#include <stdlib.h>

//estrutura dos nós
typedef struct noLSE{
    int info;
    struct noLSE* prox;
}NoLSE;

//descritor (criação de lista além dos nós)
typedef  struct linkedlist{
    NoLSE* primeiro;
    NoLSE* ultimo;
    int tam;
}LinkedList;

//função para inicializar lista
LinkedList* criarLista(LinkedList* lista){

    LinkedList* aux = (LinkedList*) malloc(sizeof(LinkedList));
    aux->primeiro = NULL;
    aux->ultimo = NULL;
    aux->tam = 0;

    return aux;
}
NoLSE* criarNo(int valor){
    NoLSE* aux = (NoLSE*) malloc(sizeof(NoLSE));
    aux->info = valor;
    aux->prox = NULL;
    return aux;
}


void inserirFinal(LinkedList* lista, int valor){
    NoLSE* novoNo = criarNo(valor);

    if(lista->tam == 0){
        lista->primeiro = novoNo;
        lista->ultimo = novoNo;
        lista->tam++;

    }else{
        lista->ultimo->prox = novoNo;
        lista->ultimo = novoNo;
        lista->tam++;
    }
}
void inserirInicio(LinkedList* lista, int valor){
    NoLSE* novoNo = criarNo(valor);

    if(lista->tam == 0){
        lista->primeiro = novoNo;
        lista->ultimo = novoNo;
        lista->tam++;
    }else{
        novoNo->prox = lista->primeiro;
        lista->primeiro = novoNo;
        lista->tam++;
    }
    printf("Inserção feita.\n");
}


int main(){

    LinkedList* lista;
    lista = criarLista(&lista);
    inserirInicio(lista, valor);




}