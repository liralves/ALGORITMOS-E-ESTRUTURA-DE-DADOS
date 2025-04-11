#include <stdio.h>
#include <stdlib.h>

typedef struct noDEQUE{
    int info;
    struct noDEQUE *ant;
    struct noDEQUE *prox;
}NoDEQUE;

typedef struct lista{
    NoDEQUE *inicio;
    NoDEQUE *fim;
    int tamanho;
}Lista;