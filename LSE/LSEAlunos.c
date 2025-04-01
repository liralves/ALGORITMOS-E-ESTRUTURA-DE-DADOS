#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct aluno{
    char ra[15];
    char nome [15];
    float media;
    int faltas;
}Aluno;
typedef struct noLSE{
    Aluno dados;
    struct noLSE* prox;
}NoLSE; 
typedef struct lista{
    NoLSE* inicio;
    NoLSE* fim;
    int tamanho;
}Lista;


void lerStr(char *str, int tam) {
    fgets(str, tam, stdin);
    int len = strlen(str);
    if (str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}
NoLSE* buscar(Lista* lista, char ra){
    NoLSE* aux = lista->inicio;
    
    while(aux != NULL){
        if(strcmp(aux->ra, ra) == 0){
            return aux;
        }
        aux = aux->prox;
    }
    return NULL;
}
void inserirTurma(Lista* lista){
    char ra[10];
    NoLSE* retorno;

    //verifica se o RA é repetido ou não
    printf("Informe o RA do aluno a ser inserido: \n");
    lerStr(ra, 10);
    retorno = buscar(lista, ra);
    
    //caso não for repetid
    if(retorno == NULL){
        NoLSE* novoAluno = (NoLSE*) malloc(sizeof(NoLSE));
        novoAluno->prox = NULL;

        //preencher nó (aluno);
        strcpy(novoAluno->ra, ra);
        printf("\nInforme o nome do aluno:\n");
        lerStr(novoAluno->nome, 10);
        printf("\nInforme a media do aluno:\n");
        scanf("%f", &novoAluno->media);
        printf("\nInforme as faltas do aluno:\n");
        scanf("%d", &novoAluno->faltas);

        //inserir o aluno na ultima posição da lista;
        if(lista->tamanho == 0){
            lista->inicio = novoAluno;
            lista->fim = novoAluno;
            lista->tamanho++;
        }
        else{
            lista->fim->prox = novoAluno;
            lista->fim = novoAluno;
        }
        (lista->tamanho++);
        printf("Inserção realizada.\n");
    }else{
        printf("Aluno já está cadastrado na turma.\n");
    }  
}

void dividirTurma(Lista* listaOrig, Lista* listaAp, Lista* listaRp, Lista* listaRf){
    NoLSE* aux = listaOrig->inicio;
    while(aux != NULL){
        if(aux->dados->media >= 7){
            inserirOrdenado(listaAp, aux->dados->ra, aux->dados->nome, aux->dados->media, aux->dados->faltas);
        }else if(aux->dados->faltas > 18){
            inserirOrdenado(listaRf, aux->dados->nome, aux->dados->media, aux->dados->faltas);
        }else{
            inserirOrdenado(listaRp, aux->dados->ra, aux->dados->nome, aux->dados->media, aux->dados->faltas);
        }
        aux = aux->prox;
    }
}


int main(){

}