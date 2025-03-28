#include <stdio.h>
#include <stdlib.h>
#include "LSE03.h"

void somar(NoLSE* lista1, NoLSE* lista2, NoLSE** lresultado){
    NoLSE* aux1 = lista1;
    NoLSE* aux2 = lista2;
    NoLSE* auxR = *lresultado;
    NoLSE* ultimoNo = NULL;

    while(aux1 != NULL && aux2 != NULL){
        int soma = aux1->info + aux2->info;
        NoLSE* novoNo = (NoLSE*) malloc(sizeof(NoLSE));
        novoNo->info = soma;
        novoNo->prox = NULL;

        if(auxR == NULL){
            auxR = novoNo;
            ultimoNo = novoNo;
        }else{
            ultimoNo->prox = novoNo;
            ultimoNo = novoNo;
            
        }
        aux1 = aux1->prox;
        aux2 = aux2->prox;
    }
}
