typedef struct noLSE{
    int info;
    struct noLSE* prox;
}NoLSE;

void somar(NoLSE* lista1, NoLSE* lista2, NoLSE* lresult);
void inserirInicio(NoLSE** lista, int valor);
void removerInicio(NoLSE** lista, int valor);
void inserirFinal(NoLSE** lista, int valor);
void removerFinal(NoLSE** lista, int valor);
NoLSE* busca(NoLSE* lista, int valor);