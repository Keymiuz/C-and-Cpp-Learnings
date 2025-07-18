#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void printArray(int A[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}

void Merge(int A[], int l, int mid, int h) {
    int i = l, j = mid + 1, k = 0;
    int size = h - l + 1;

    int *temp_array = (int *)malloc(size * sizeof(int));
    if (temp_array == NULL) {
        printf("Erro na alocação de memória!\n");
        return;
    }

    while (i <= mid && j <= h) {
        if (A[i] < A[j])
            temp_array[k++] = A[i++];
        else
            temp_array[k++] = A[j++];
    }

    while (i <= mid) temp_array[k++] = A[i++];
    while (j <= h) temp_array[k++] = A[j++];

    for (i = l, k = 0; i <= h; i++, k++) {
        A[i] = temp_array[k];
    }
    
    free(temp_array);
}

void MergeSort(int A[], int l, int h) {
    int mid;
    if (l < h) {
        mid = (l + h) / 2;
        MergeSort(A, l, mid);
        MergeSort(A, mid + 1, h);
        Merge(A, l, mid, h);
    }
}

void mergeSortedArrays(int A[], int B[], int C[], int n, int m) {
    int i = 0, j = 0, k = 0;
    
    while (i < n && j < m) {
        if (A[i] < B[j])
            C[k++] = A[i++];
        else
            C[k++] = B[j++];
    }
    
    while (i < n) C[k++] = A[i++];
    while (j < m) C[k++] = B[j++];
}

int main() {
    int A[] = {11, 13, 7, 12, 16, 9, 24, 5, 10, 3};
    int B[] = {12, 77, 31, 20, 11, 26, 4, 8, 100, 1};
    int n = 10;
    int m = 10;
    int C[n + m];

    printf("Array A original: ");
    printArray(A, n);
    
    printf("Array B original: ");
    printArray(B, m);
    
    MergeSort(A, 0, n - 1);
    MergeSort(B, 0, m - 1);

    printf("\nArray A ordenado: ");
    printArray(A, n);

    printf("Array B ordenado: ");
    printArray(B, m);

    mergeSortedArrays(A, B, C, n, m);
    
    printf("\nArrays A e B combinados e ordenados: ");
    printArray(C, n + m);

    return 0;
}