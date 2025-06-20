#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct CircularQueue {
    int size;   
    int front;  
    int rear;   
    int *Q;     
};


// Inicializa a fila
void createQueue(struct CircularQueue *q, int size) {
    q->size = size + 1; 
    q->front = 0;
    q->rear = 0;
    q->Q = (int *)malloc(q->size * sizeof(int));
    if (q->Q == NULL) {
        printf("Erro: Falha na alocacao de memoria!\n");
        exit(EXIT_FAILURE);
    }
}

// Verifica se a fila está vazia
bool isEmpty(struct CircularQueue *q) {
    return q->front == q->rear;
}

// Verifica se a fila está cheia
bool isFull(struct CircularQueue *q) {
    return ((q->rear + 1) % q->size) == q->front;
}

// Adiciona um elemento à fila
void enqueue(struct CircularQueue *q, int value) {
    if (isFull(q)) {
        printf("Fila Cheia! Nao foi possivel adicionar %d.\n", value);
    } else {
        q->Q[q->rear] = value;
        q->rear = (q->rear + 1) % q->size; // movimento circular do rear
        printf("%d adicionado a fila.\n", value);
    }
}

// Remove e retorna um elemento da fila
int dequeue(struct CircularQueue *q) {
    int x = -1;
    if (isEmpty(q)) {
        printf("Fila Vazia! Nao ha elementos para remover.\n");
    } else {
        x = q->Q[q->front];
        q->front = (q->front + 1) % q->size; // Movimento circular do front
        printf("%d removido da fila.\n", x);
    }
    return x;
}

// Exibe todos os elementos da fila
void displayQueue(struct CircularQueue *q) {
    if (isEmpty(q)) {
        printf("A fila esta vazia. Nada para exibir.\n");
        return;
    }

    printf("Elementos na fila: [ ");
    int i = q->front;
    while (i != q->rear) { // Percorre do front até o rear (circularmente)
        printf("%d ", q->Q[i]);
        i = (i + 1) % q->size;
    }
    printf("]\n");
}

// Liberação de memória clássica
void destroyQueue(struct CircularQueue *q) {
    if (q->Q != NULL) {
        free(q->Q);
        q->Q = NULL;
        printf("Memoria da fila liberada.\n");
    }
}

int main() {
    struct CircularQueue myQueue;
    int choice, value, capacity;

    printf("Quantos elementos voce deseja que a fila armazene? ");
    scanf("%d", &capacity);

    createQueue(&myQueue, capacity);

    do {
        printf("\n--- Menu da Fila Circular ---\n");
        printf("1. Adicionar elemento\n");
        printf("2. Remover elemento\n");
        printf("3. Exibir fila\n");
        printf("4. Verificar se a fila esta vazia\n");
        printf("5. Verificar se a fila esta cheia\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Digite o valor para adicionar: ");
                scanf("%d", &value);
                enqueue(&myQueue, value);
                break;
            case 2:
                dequeue(&myQueue);
                break;
            case 3:
                displayQueue(&myQueue);
                break;
            case 4:
                if (isEmpty(&myQueue)) printf("A fila esta vazia.\n");
                else printf("A fila NAO esta vazia.\n");
                break;
            case 5:
                if (isFull(&myQueue)) printf("A fila esta cheia.\n");
                else printf("A fila NAO esta cheia.\n");
                break;
            case 0:
                printf("Saindo do programa.\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    } while (choice != 0);

    destroyQueue(&myQueue);
    return 0;
}


// A principal razão pela qual a fila circular é superior à fila linear é o reaproveitamento do espaço no array subjacente.
// Por exemplo, se a fila linear estiver cheia, não será possível enfileirar mais elementos, mesmo que existam espaços vazios no array.
// Porém, na fila circular, os espaços vazios no array subjacente são reaproveitados, permitindo que a fila continue funcionando mesmo quando está cheia.7



// Aqui, front e rear são inicializados em 0. Isso define o "ponto de partida" da nossa esteira circular. Quando front == rear, a fila está vazia.
// Quando rear == front + 1, a fila está cheia.
// Na fila linear, iniciar em -1 é uma convenção comum onde front e rear apontam para "nenhum elemento" quando a fila está vazia.


// Adicionei também a opção de exibir a fila, para que possamos ver os elementos que estão na fila (em formato de menu), mais tarde eu deixo esse código mais bonito.