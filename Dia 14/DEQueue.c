#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int front;
    int rear;
    int size;
    int* Q;
} DEQueue;

void create(DEQueue* deq, int size);
void destroy(DEQueue* deq);
void display(DEQueue* deq);
void enqueueFront(DEQueue* deq, int x);
void enqueueRear(DEQueue* deq, int x);
int dequeueFront(DEQueue* deq);
int dequeueRear(DEQueue* deq);
bool isEmpty(DEQueue* deq);
bool isFull(DEQueue* deq);

void create(DEQueue* deq, int size) {
    deq->size = size;
    deq->front = -1;
    deq->rear = -1;
    deq->Q = (int*)malloc(deq->size * sizeof(int));
}

void destroy(DEQueue* deq) {
    free(deq->Q);
}

bool isEmpty(DEQueue* deq) {
    if (deq->front == deq->rear) {
        return true;
    }
    return false;
}

bool isFull(DEQueue* deq) {
    if (deq->rear == deq->size - 1) {
        return true;
    }
    return false;
}

void enqueueFront(DEQueue* deq, int x) {
    if (deq->front == -1) {
        printf("DEQueue Overflow (Front)\n");
    } else {
        deq->Q[deq->front] = x;
        deq->front--;
    }
}

void enqueueRear(DEQueue* deq, int x) {
    if (isFull(deq)) {
        printf("DEQueue Overflow (Rear)\n");
    } else {
        deq->rear++;
        deq->Q[deq->rear] = x;
    }
}

int dequeueFront(DEQueue* deq) {
    int x = -1;
    if (isEmpty(deq)) {
        printf("DEQueue Underflow\n");
    } else {
        deq->front++;
        x = deq->Q[deq->front];
    }
    return x;
}

int dequeueRear(DEQueue* deq) {
    int x = -1;
    if (isEmpty(deq)) {
        printf("DEQueue Underflow\n");
    } else {
        x = deq->Q[deq->rear];
        deq->rear--;
    }
    return x;
}

void display(DEQueue* deq) {
    if (isEmpty(deq)) {
        printf("DEQueue is Empty\n");
        return;
    }
    for (int i = deq->front + 1; i <= deq->rear; i++) {
        printf("%d", deq->Q[i]);
        if (i < deq->rear) {
            printf(" <- ");
        }
    }
    printf("\n");
}

int main() {
    int A[] = {1, 3, 5, 7, 9};
    int B[] = {2, 4, 6, 8};
    int sizeA = sizeof(A) / sizeof(A[0]);
    int sizeB = sizeof(B) / sizeof(B[0]);

    DEQueue deq;
    create(&deq, sizeA);

    for (int i = 0; i < sizeA; i++) {
        enqueueRear(&deq, A[i]);
    }
    display(&deq);
    enqueueRear(&deq, 11);

    printf("\nDequeing from front...\n");
    for (int i = 0; i < sizeA; i++) {
        dequeueFront(&deq);
    }
    display(&deq);
    dequeueFront(&deq);

    printf("\nEnqueing to front...\n");
    for (int i = 0; i < sizeB; i++) {
        enqueueFront(&deq, B[i]);
    }
    display(&deq);
    enqueueFront(&deq, 10);
    display(&deq);
    enqueueFront(&deq, 12);

    printf("\nDequeing from rear...\n");
    for (int i = 0; i < sizeB; i++) {
        dequeueRear(&deq);
    }
    display(&deq);
    dequeueRear(&deq);
    display(&deq);
    dequeueRear(&deq);

    destroy(&deq);

    return 0;
}
