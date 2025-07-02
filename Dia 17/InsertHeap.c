#include <stdio.h>
#include <stdlib.h>

void InsertHeap(int A[], int n) {
    int i = n;
    int temp = A[n];
    while (i > 1 && temp > A[i / 2]) {
        A[i] = A[i / 2];
        i = i / 2;
    }
    A[i] = temp;
}

int main() {
    int A[] = {10, 20, 30, 25, 5, 40, 45};
    int n = sizeof(A) / sizeof(A[0]);
    for (int i = 1; i < n; i++) {
        InsertHeap(A, i);
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    return 0;
}

// o Heap começa do elemento 1
// A principal utilidade de uma heap não é estar ordenada, mas sim fornecer acesso muito rápido (em tempo O(1)) ao elemento máximo (ou mínimo, numa Min-Heap). 
// Para ordenar de fato os dados, você precisaria aplicar um algoritmo adicional, como o Heapsort, que extrai o elemento máximo repetidamente.