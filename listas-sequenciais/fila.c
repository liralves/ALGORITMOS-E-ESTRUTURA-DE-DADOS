#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

Fila *createFila(){
    Fila *fila = (Fila*)malloc(sizeof(Fila));
    if(fila == NULL)
        return NULL;
            
    fila->qtd = 0; //fila com tam 0
    fila->vetor[fila->qtd] = 0; //atributos com valor 0
    return fila;
}

void insertFila(Fila *fila, int valor){
    if(fila->qtd == TAM) //verifica se a fila está cheia 
        return NULL; 
    
    fila->vetor[fila->qtd] = valor; //se não, aloca o valor para a posicao atual do vetor
    (fila->qtd)++; //incrementa o tamanho do vetor
}

void removeFila(Fila *fila, int valor){
    if(fila == NULL)
        return NULL;
    
    int pos = buscaLinearFila(fila, valor); //recebe a posição onde se encontra o valor a ser removido 
    if(pos != -1){ // se for diferente de -1 existe o valor
        while(pos < fila->qtd){ // enquanto a posição atual for menor que o tamanho atual
            fila->vetor[pos] = fila->vetor[++pos]; // o vetor na posição atual recebe o posição seguinte
        }
        // esse laço remove o elemento e reorganiza o vetor 
        (fila->qtd)--; // decrementa o tamanho do vetor
    }
}

int buscaLinearFila(Fila *fila, int valor){
    for(int i = 0; i < (fila->qtd); i++){
        if(fila->vetor[i] == valor){
            return i;
        }
    }
    return -1;
}

void destroyFila(Fila *fila){
    free(fila->vetor);
    free(fila);
}
