#include <stdio.h>
#include <stdlib.h> // Para usar malloc e free
#include <limits.h> // Para usar INT_MIN como valor de erro

// A struct que define a pilha
typedef struct {
    int topo;        // Índice do último elemento inserido
    unsigned capacidade; // Capacidade máxima da pilha
    int* array;      // Ponteiro para o array que armazenará os elementos
} Pilha;

/**
 * Função para criar e inicializar uma pilha com uma dada capacidade.
 * Ela aloca memória para a pilha e para o array interno.
 */
Pilha* criarPilha(unsigned capacidade) {
    // Aloca memória para a estrutura da pilha
    Pilha* pilha = (Pilha*) malloc(sizeof(Pilha));
    if (!pilha) { // Verifica se a alocação de memória falhou
        return NULL;
    }

    pilha->capacidade = capacidade;
    pilha->topo = -1; // -1 indica que a pilha começa vazia

    // Aloca memória para o array de elementos
    pilha->array = (int*) malloc(pilha->capacidade * sizeof(int));
    if (!pilha->array) { // Verifica se a alocação de memória falhou
        free(pilha); // Libera a memória da struct antes de sair
        return NULL;
    }
    
    return pilha;
}

/**
 * Função para verificar se a pilha está cheia.
 * Retorna 1 se estiver cheia, 0 caso contrário.
 */
int estaCheia(Pilha* pilha) {
    return pilha->topo == pilha->capacidade - 1;
}

/**
 * Função para verificar se a pilha está vazia.
 * Retorna 1 se estiver vazia, 0 caso contrário.
 */
int estaVazia(Pilha* pilha) {
    return pilha->topo == -1;
}

/**
 * Função para adicionar um elemento ao topo da pilha (push).
 */
void empilhar(Pilha* pilha, int elemento) {
    if (estaCheia(pilha)) {
        printf("Erro: A pilha está cheia (Stack Overflow)!\n");
        return;
    }
    pilha->topo++; // Incrementa o topo
    pilha->array[pilha->topo] = elemento; // Insere o elemento
    printf("Elemento '%d' empilhado.\n", elemento);
}

/**
 * Função para remover e retornar o elemento do topo da pilha (pop).
 */
int desempilhar(Pilha* pilha) {
    if (estaVazia(pilha)) {
        printf("Erro: A pilha está vazia (Stack Underflow)!\n");
        return INT_MIN; // Retorna um valor de erro (o menor inteiro possível)
    }
    int elementoRemovido = pilha->array[pilha->topo];
    pilha->topo--; // Decrementa o topo
    return elementoRemovido;
}

/**
 * Função para retornar o elemento do topo sem removê-lo (peek).
 */
int espiar(Pilha* pilha) {
    if (estaVazia(pilha)) {
        printf("A pilha está vazia.\n");
        return INT_MIN; // Retorna um valor de erro
    }
    return pilha->array[pilha->topo];
}

/**
 * Função para liberar a memória alocada para a pilha.
 */
void liberarPilha(Pilha* pilha) {
    if (pilha) {
        free(pilha->array); // Primeiro libera o array interno
        free(pilha);        // Depois libera a struct da pilha
    }
}


// --- Função Principal para Demonstração ---
int main() {
    printf("--- Testando a Pilha em C ---\n");
    
    // Cria uma pilha com capacidade para 5 elementos
    Pilha* pilha = criarPilha(5);
    if (!pilha) {
        printf("Falha ao alocar memória para a pilha.\n");
        return 1; // Termina o programa com erro
    }

    printf("A pilha está vazia? %s\n", estaVazia(pilha) ? "Sim" : "Não");

    empilhar(pilha, 10);
    empilhar(pilha, 20);
    empilhar(pilha, 30);

    printf("Elemento no topo: %d\n", espiar(pilha));
    printf("A pilha está cheia? %s\n", estaCheia(pilha) ? "Sim" : "Não");

    int elemento = desempilhar(pilha);
    printf("Elemento '%d' desempilhado.\n", elemento);
    printf("Novo elemento no topo: %d\n", espiar(pilha));

    empilhar(pilha, 40);
    empilhar(pilha, 50);
    empilhar(pilha, 60); // A pilha agora está cheia

    empilhar(pilha, 70); // Deve dar erro de Overflow

    // Esvaziando a pilha
    printf("\nEsvaziando a pilha:\n");
    while (!estaVazia(pilha)) {
        printf("Desempilhado: %d\n", desempilhar(pilha));
    }

    // Tentando desempilhar de uma pilha vazia
    desempilhar(pilha); // Deve dar erro de Underflow

    // Libera toda a memória alocada para a pilha
    liberarPilha(pilha);
    printf("\nMemória da pilha liberada.\n");

    return 0;
}