#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_RA 10
#define TAM_NOME 15

typedef struct aluno{
    char ra[TAM_RA];
    char nome [TAM_NOME];
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

void lerStr(char *str, int tam);
NoLSE* buscar(Lista* lista, char* ra);
void inserirTurma(Lista* lista);
void inserirOrdenado(Lista* lista, char* ra, char* novoNome, float media, int faltas);
void dividirTurma(Lista* listaOrig, Lista* listaAp, Lista* listaRp, Lista* listaRf);
void exibirTurma(Lista* lista);
void limparBuffer();
void inicializarLista(Lista* lista);
void liberarLista(Lista* lista);

void liberarLista(Lista* lista) {
    NoLSE* atual = lista->inicio;
    while(atual != NULL) {
        NoLSE* temp = atual;
        atual = atual->prox;
        free(temp);
    }
    lista->inicio = NULL;
    lista->fim = NULL;
    lista->tamanho = 0;
}
void inicializarLista(Lista* lista) {
    lista->inicio = NULL;
    lista->fim = NULL;
    lista->tamanho = 0;
}
void lerStr(char *str, int tam) {
    fgets(str, tam, stdin);
    int len = strlen(str);
    if (str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}
NoLSE* buscar(Lista* lista, char* ra){
    NoLSE* aux = lista->inicio;
    
    while(aux != NULL){
        if(strcmp(aux->dados.ra, ra) == 0){
            return aux;
        }
        aux = aux->prox;
    }
    return NULL;
}
void inserirTurma(Lista* lista) {
    char ra[TAM_RA];
    NoLSE* retorno;

    printf("Informe o RA do aluno a ser inserido: ");
    lerStr(ra, TAM_RA);
    retorno = buscar(lista, ra);
    
    if(retorno == NULL) {
        NoLSE* novoAluno = (NoLSE*) malloc(sizeof(NoLSE));
        novoAluno->prox = NULL;

        strcpy(novoAluno->dados.ra, ra);
        printf("Informe o nome do aluno: ");
        lerStr(novoAluno->dados.nome, TAM_NOME);
        printf("Informe a media do aluno: ");
        scanf("%f", &novoAluno->dados.media);
        printf("Informe as faltas do aluno: ");
        scanf("%d", &novoAluno->dados.faltas);
        limparBuffer();

        if(lista->tamanho == 0) {
            lista->inicio = novoAluno;
            lista->fim = novoAluno;
        } else {
            lista->fim->prox = novoAluno;
            lista->fim = novoAluno;
        }
        lista->tamanho++;
        printf("\nAluno inserido com sucesso!\n");
    } else {
        printf("\nErro: Aluno com RA %s ja cadastrado!\n", ra);
    }  
}
void inserirOrdenado(Lista* lista, char* ra, char* novoNome, float media, int faltas) {
    NoLSE* novoNo = (NoLSE*) malloc(sizeof(NoLSE));
    strcpy(novoNo->dados.ra, ra);
    strcpy(novoNo->dados.nome, novoNome);
    novoNo->dados.media = media;
    novoNo->dados.faltas = faltas;
    novoNo->prox = NULL;

    if(lista->inicio == NULL || strcmp(novoNome, lista->inicio->dados.nome) < 0) {
        novoNo->prox = lista->inicio;
        lista->inicio = novoNo;
        
        if(lista->fim == NULL) {
            lista->fim = novoNo;
        }
    } else {
        NoLSE* atual = lista->inicio;
        
        while(atual->prox != NULL && strcmp(novoNome, atual->prox->dados.nome) > 0) {
            atual = atual->prox;
        }
        
        novoNo->prox = atual->prox;
        atual->prox = novoNo;
        
        if(novoNo->prox == NULL) {
            lista->fim = novoNo;
        }
    }
    lista->tamanho++;
}
void dividirTurma(Lista* listaOrig, Lista* listaAp, Lista* listaRp, Lista* listaRf) {
    
    liberarLista(listaAp);
    liberarLista(listaRp);
    liberarLista(listaRf);

    NoLSE* aux = listaOrig->inicio;
    while(aux != NULL) {
        if(aux->dados.media >= 7.0 && aux->dados.faltas <= 18) {
            inserirOrdenado(listaAp, aux->dados.ra, aux->dados.nome, aux->dados.media, aux->dados.faltas);
        } else if(aux->dados.faltas > 18) {
            inserirOrdenado(listaRf, aux->dados.ra, aux->dados.nome, aux->dados.media, aux->dados.faltas);
        } else {
            inserirOrdenado(listaRp, aux->dados.ra, aux->dados.nome, aux->dados.media, aux->dados.faltas);
        }
        aux = aux->prox;
    }
}
void exibirTurma(Lista* lista) {
    if(lista == NULL || lista->inicio == NULL) {
        printf("Turma vazia ou inexistente.\n");
        return;
    }
    
    NoLSE* atual = lista->inicio;
    int cont = 1;
    
    while(atual != NULL) {
        printf("\nAluno %d:\n", cont++);
        printf("RA: %s\n", atual->dados.ra);
        printf("Nome: %s\n", atual->dados.nome);
        printf("Media: %.2f\n", atual->dados.media);
        printf("Faltas: %d\n", atual->dados.faltas);
        printf("Situacao: ");
        
        if(atual->dados.media >= 7.0 && atual->dados.faltas <= 18) {
            printf("APROVADO\n");
        } else if(atual->dados.faltas > 18) {
            printf("REPROVADO POR FALTA\n");
        } else {
            printf("REPROVADO POR NOTA\n");
        }
        
        atual = atual->prox;
    }
    printf("\nTotal de alunos: %d\n", lista->tamanho);
}

void limparBuffer() {
    int c;
    while((c = getchar()) != '\n' && c != EOF);
}

int main(){
    Lista turmaOrig, turmaAp, turmaRp, turmaRf;
    int opcao;

    inicializarLista(&turmaOrig);
    inicializarLista(&turmaAp);
    inicializarLista(&turmaRp);
    inicializarLista(&turmaRf);

    do {
        printf("1. Inserir aluno na turma original\n");
        printf("2. Dividir turma (AP, RP, RF)\n");
        printf("3. Exibir turma original\n");
        printf("4. Exibir turma AP (aprovados)\n");
        printf("5. Exibir turma RP (reprovados por nota)\n");
        printf("6. Exibir turma RF (reprovados por falta)\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        limparBuffer();

        switch(opcao) {
            case 1:
                inserirTurma(&turmaOrig);
                break;
            case 2:
                dividirTurma(&turmaOrig, &turmaAp, &turmaRp, &turmaRf);
                printf("Turma dividida com sucesso!\n");
                break;
            case 3:
                printf("\nTurma Original\n");
                exibirTurma(&turmaOrig);
                break;
            case 4:
                printf("\nTurma de Aprovados\n");
                exibirTurma(&turmaAp);
                break;
            case 5:
                printf("\nTurma RM (Reprovados por Media\n");
                exibirTurma(&turmaRp);
                break;
            case 6:
                printf("\nTurma RF (Reprovados por Falta)\n");
                exibirTurma(&turmaRf);
                break;
            case 0:
                printf("Encerrando o programa...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while(opcao != 0);

    return 0;
}