#define TAM 300

typedef struct Fila{
    
	int vetor[TAM];
	int qtd;

} Fila;

Fila *createFila();
void insertFila(Fila *fila, int valor);
void removeFila(Fila *fila, int valor);
int buscaLinearFila(Fila *fila, int valor);
void destroyFila(Fila *fila);