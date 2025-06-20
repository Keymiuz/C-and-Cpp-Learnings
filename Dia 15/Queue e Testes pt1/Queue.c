#include <stdio.h>
#include <stdlib.h> 
#include "Queue.h"  // Inclui as definições e protótipos

// Função para criar/inicializar a Fila
void criarFila(struct Fila *f, int tamanho)
{
    f->tamanho = tamanho;
    f->frente = 0; 
    f->tras = 0;   
    f->Q = (struct No **)malloc(f->tamanho * sizeof(struct No *));
    if (f->Q == NULL) {
        fprintf(stderr, "Erro: Falha na alocação de memória para o array da fila.\n");
        exit(EXIT_FAILURE);
    }
}

// Função para enfileirar um Nó
void enfileirar(struct Fila *f, struct No *x)
{
    if ((f->tras + 1) % f->tamanho == f->frente) // Condição de Cheia
    {
        printf("Fila esta Cheia\n");
    }
    else
    {
        f->tras = (f->tras + 1) % f->tamanho; // Avança 'tras' ANTES de adicionar
        f->Q[f->tras] = x;
    }
}

// Função para desenfileirar um Nó
struct No * desenfileirar(struct Fila *f)
{
    struct No* x = NULL;

    if (f->frente == f->tras) 
    {
        printf("Fila esta Vazia\n");
    }
    else
    {
        f->frente = (f->frente + 1) % f->tamanho; 
        x = f->Q[f->frente];
    }
    return x;
}

// Função para verificar se a Fila está vazia
int estaVazia(struct Fila *f) // <-- CORRIGIDO: Agora recebe um ponteiro
{
    return f->frente == f->tras; // <-- CORRIGIDO: Acessa via ponteiro
}

// Função para liberar a memória alocada para a fila
void destruirFila(struct Fila *f) {
    if (f->Q != NULL) {
        free(f->Q);
        f->Q = NULL;
    }
    f->frente = 0;
    f->tras = 0;
    f->tamanho = 0;
}