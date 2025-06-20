#include <stdio.h>
#include <stdlib.h>

struct CircularQueue{
    int size;
    int front;
    int rear;
    int *Q;
};

void createCircularQueue(struct CircularQueue *q, int size){
    q->size = size;
    q->front = 0;
    q->rear = 0;
    q->Q = (int *)malloc(q->size * sizeof(int));
    if (q->Q == NULL) {
        printf("Falha na alocacao de memoria!\n");
        exit(1);
    }
}

void enqueueCircularQueue(struct CircularQueue *q, int x){
    if(((q->rear + 1) % q->size) == q->front)
        printf("Circular Queue está cheia\n");
    else{
        q->Q[q->rear] = x;
        q->rear = (q->rear + 1) % q->size;
    }
}

int dequeueCircularQueue(struct CircularQueue *q){
    int x = -1;
    if(q->front == q->rear)
        printf("Circular Queue está vazia\n");
    else{
        x = q->Q[q->front];
        q->front = (q->front + 1) % q->size;
    }
    return x;
}

void displayCircularQueue(struct CircularQueue *q){
    if (q->front == q->rear) {
        printf("Circular Queue está vazia\n");
        return;
    }

    int i = q->front;
    while (i != q->rear) {
        printf("%d ", q->Q[i]);
        i = (i + 1) % q->size;
    }
    printf("\n");
}

int main(){
    struct CircularQueue q;
    createCircularQueue(&q, 5); 

    // Enfileirar o primeiro elemento
    printf("Tentando enfileirar 10...\n");
    enqueueCircularQueue(&q, 10); 
    printf("Elementos apos 10: ");
    displayCircularQueue(&q); 

    // Enfileirar mais elementos e fazendo alguns testes
    printf("Tentando enfileirar 20...\n");
    enqueueCircularQueue(&q, 20); 
    printf("Elementos apos 20: ");
    displayCircularQueue(&q); 

    printf("Tentando enfileirar 30...\n");
    enqueueCircularQueue(&q, 30); 
    printf("Elementos apos 30: ");
    displayCircularQueue(&q); 

    printf("Tentando enfileirar 40...\n");
    enqueueCircularQueue(&q, 40); 
    printf("Elementos apos 40: ");
    displayCircularQueue(&q); 

    printf("Tentando enfileirar 50 (fila cheia)...\n");
    enqueueCircularQueue(&q, 50); 
    printf("Elementos apos 50: ");
    displayCircularQueue(&q); 

    free(q.Q);
    return 0;
}


// A principal razão pela qual a fila circular é superior à fila linear é o reaproveitamento do espaço no array subjacente.
// Por exemplo, se a fila linear estiver cheia, não será possível enfileirar mais elementos, mesmo que existam espaços vazios no array.
// Porém, na fila circular, os espaços vazios no array subjacente são reaproveitados, permitindo que a fila continue funcionando mesmo quando está cheia.7



// Aqui, front e rear são inicializados em 0. Isso define o "ponto de partida" da nossa esteira circular. Quando front == rear, a fila está vazia.
// Quando rear == front + 1, a fila está cheia.
// Na fila linear, iniciar em -1 é uma convenção comum onde front e rear apontam para "nenhum elemento" quando a fila está vazia.