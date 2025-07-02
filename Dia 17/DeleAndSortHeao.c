#include <stdio.h>
#include <stdlib.h>

void maxHeapify(int A[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && A[left] > A[largest]) {
        largest = left;
    }

    if (right < n && A[right] > A[largest]) {
        largest = right;
    }

    if (largest != i) {
        int temp = A[i];
        A[i] = A[largest];
        A[largest] = temp;
        maxHeapify(A, n, largest);
    }
}

void buildMaxHeap(int A[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        maxHeapify(A, n, i);
    }
}

void HeapSort(int A[], int n) {
    buildMaxHeap(A, n);

    for (int i = n - 1; i > 0; i--) {
        int temp = A[0];
        A[0] = A[i];
        A[i] = temp;
        maxHeapify(A, i, 0);
    }
}

int main() {
    int A[] = {10, 20, 30, 25, 5, 40, 45};
    int n = sizeof(A) / sizeof(A[0]);

    printf("Array original: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
    HeapSort(A, n);
    printf("Array ordenado: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
    return 0;
}