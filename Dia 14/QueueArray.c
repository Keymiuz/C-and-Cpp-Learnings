#include <stdio.h>
#include <stdlib.h>

struct Queue{
    int size;
    int front;
    int rear;
    int *Q;
};

void create(struct Queue *q, int size){
    q->size = size;
    q->front = q->rear = -1;
    q->Q = (int *)malloc(q->size * sizeof(int));
}

void enqueue(struct Queue *q, int x){
    if(q->rear == q->size-1)
        printf("Queue está cheia\n");
    else{
        q->rear++;
        q->Q[q->rear] = x;
    }
}

int dequeue(struct Queue *q){
    int x = -1;
    if(q->front == q->rear)
        printf("Queue está vazia\n");
    else{
        q->front++;
        x = q->Q[q->front];
    }
    return x;
}

int isEmpty(struct Queue *q){
    if(q->front == q->rear)
        return 1;
    else
        return 0;
}

int isFull(struct Queue *q){
    if(q->rear == q->size-1)
        return 1;
    else
        return 0;
}

void display(struct Queue *q){
    int i;
    for(i = q->front+1; i <= q->rear; i++)
        printf("%d ", q->Q[i]);
    printf("\n");
}

int main(){
    struct Queue q;
    create(&q, 5);
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    enqueue(&q, 50);
    display(&q);
    printf("%d\n", dequeue(&q));
    display(&q);
    return 0;
}


/// Drawbacks: Se a queue estiver preenchida até o final (mas os primeiros valores n estão preenchidos), não será possível enfileirar mais valores. 
/// Solução: Usar uma fila circular (Circular Queue), onde o final da fila se conecta ao início, formando um círculo.
/// 

