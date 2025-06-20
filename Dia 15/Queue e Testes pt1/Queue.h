#ifndef QUEUE_H // Prevenção contra inclusões múltiplas
#define QUEUE_H

// Definição da estrutura do Nó da Árvore
struct No
{
    struct No *filhoEsquerdo;
    int dado;
    struct No *filhoDireito;
};

// Definição da estrutura da Fila
struct Fila
{
    int tamanho;
    int frente;
    int tras;
    struct No **Q; 
};

// Protótipos das funções da Fila
void criarFila(struct Fila *f, int tamanho);
void enfileirar(struct Fila *f, struct No *x);
struct No * desenfileirar(struct Fila *f);
int estaVazia(struct Fila *f); 
void destruirFila(struct Fila *f); 

#endif 