#include <stdio.h>
#include <stdlib.h>

// Estrutura para um nó da árvore binária.
struct Node {
    struct Node *lchild;
    int data;
    struct Node *rchild;
};

// Estrutura para a Fila, usada na criação da árvore.
struct Queue {
    int size;
    int front;
    int rear;
    struct Node **Q;
};

void criarFila(struct Queue *q, int tamanho) {
    q->size = tamanho;
    q->front = q->rear = -1;
    q->Q = (struct Node **)malloc(q->size * sizeof(struct Node *));
}

void enfileirar(struct Queue *q, struct Node *x) {
    if (q->rear == q->size - 1) {
        printf("A fila está cheia!\n");
    } else {
        q->rear++;
        q->Q[q->rear] = x;
    }
}

struct Node* desenfileirar(struct Queue *q) {
    struct Node* x = NULL;
    if (q->front != q->rear) {
        q->front++;
        x = q->Q[q->front];
    }
    return x;
}

int estaVazia(struct Queue q) {
    return q.front == q.rear;
}

// Ponteiro global para a raiz da árvore.
struct Node *raiz = NULL;

// Cria a árvore binária de forma iterativa, usando uma fila.
void criarArvore() {
    struct Node *ponteiroAuxiliar, *novoNo;
    int valor;
    struct Queue fila;
    criarFila(&fila, 100);

    printf("Digite o valor para a raiz da árvore: ");
    scanf("%d", &valor);

    raiz = (struct Node *)malloc(sizeof(struct Node));
    raiz->data = valor;
    raiz->lchild = raiz->rchild = NULL;
    enfileirar(&fila, raiz);

    // Processa cada nó na fila para adicionar seus filhos.
    while (!estaVazia(fila)) {
        ponteiroAuxiliar = desenfileirar(&fila);

        printf("Digite o filho à esquerda de %d (ou -1 se não houver): ", ponteiroAuxiliar->data);
        scanf("%d", &valor);
        if (valor != -1) {
            novoNo = (struct Node *)malloc(sizeof(struct Node));
            novoNo->data = valor;
            novoNo->lchild = novoNo->rchild = NULL;
            ponteiroAuxiliar->lchild = novoNo;
            enfileirar(&fila, novoNo);
        }

        printf("Digite o filho à direita de %d (ou -1 se não houver): ", ponteiroAuxiliar->data);
        scanf("%d", &valor);
        if (valor != -1) {
            novoNo = (struct Node *)malloc(sizeof(struct Node));
            novoNo->data = valor;
            novoNo->lchild = novoNo->rchild = NULL;
            ponteiroAuxiliar->rchild = novoNo;
            enfileirar(&fila, novoNo);
        }
    }
}

// Conta o número total de nós na árvore (recursivamente).
int contarNos(struct Node *no) {
    if (no != NULL) {
        return contarNos(no->lchild) + contarNos(no->rchild) + 1;
    }
    return 0;
}

// Calcula a altura da árvore (recursivamente).
int calcularAltura(struct Node *no) {
    int alturaEsquerda = 0, alturaDireita = 0;
    if (no == NULL) {
        return 0;
    }

    alturaEsquerda = calcularAltura(no->lchild);
    alturaDireita = calcularAltura(no->rchild);

    // A altura é a da maior subárvore + 1.
    if (alturaEsquerda > alturaDireita) {
        return alturaEsquerda + 1;
    } else {
        return alturaDireita + 1;
    }
}

int main() {
    criarArvore();

    printf("\n--- Resultados ---\n");
    printf("O número total de nós na árvore é: %d\n", contarNos(raiz));
    printf("A altura da árvore é: %d\n", calcularAltura(raiz));

    printf("\nPressione Enter para fechar o programa...");
    getchar(); // Limpa o buffer de entrada (o Enter do último scanf)
    getchar(); // Espera que o usuário pressione Enter novamente

    return 0;
}