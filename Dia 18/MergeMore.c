#include <stdio.h>
#include <stdlib.h>

void printArray(int A[], int n) {
    for (int i = 0; i < n; i++) {
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

// Função para fazer merge de dois arrays ordenados
void mergeTwoArrays(int A[], int B[], int C[], int n, int m) {
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

// Função para fazer merge de múltiplos arrays ordenados
void mergeMultipleArrays(int* arrays[], int sizes[], int num_arrays, int result[], int result_size) {
    // Se tivermos apenas um array, copiamos para o resultado
    if (num_arrays == 1) {
        for (int i = 0; i < sizes[0]; i++) {
            result[i] = arrays[0][i];
        }
        return;
    }
    
    // Se tivermos dois arrays, usamos a função mergeTwoArrays
    if (num_arrays == 2) {
        mergeTwoArrays(arrays[0], arrays[1], result, sizes[0], sizes[1]);
        return;
    }
    
    // Se tivermos mais de dois arrays, dividimos o problema (não entendi exatamente por que a divisão)
    int mid = num_arrays / 2;
    
    // Calcula o tamanho da divisão
    int left_size = 0;
    for (int i = 0; i < mid; i++) {
        left_size += sizes[i];
    }
    // Alocamento de memória
    int* left = (int*)malloc(left_size * sizeof(int));
    if (!left) {
        printf("Erro na alocação de memória!\n");
        return;
    }
    
    mergeMultipleArrays(arrays, sizes, mid, left, left_size);
    
    int right_size = result_size - left_size;
    
    int* right = (int*)malloc(right_size * sizeof(int));
    if (!right) {
        free(left);
        printf("Erro na alocação de memória!\n");
        return;
    }
    mergeMultipleArrays(arrays + mid, sizes + mid, num_arrays - mid, right, right_size);
    //fazendo o merge das duas metades
    mergeTwoArrays(left, right, result, left_size, right_size);
    
    free(left);
    free(right);
}

int main() {
    int A[] = {11, 13, 7, 12, 16};
    int B[] = {9, 24, 5, 10, 3};
    int C[] = {12, 77, 31, 20, 11};
    int D[] = {26, 4, 8, 100, 1};
    
    // Tamanhos dos arrays (calculados pela divisão que eu ainda não entendi kkkk)
    int nA = sizeof(A) / sizeof(A[0]);
    int nB = sizeof(B) / sizeof(B[0]);
    int nC = sizeof(C) / sizeof(C[0]);
    int nD = sizeof(D) / sizeof(D[0]);
    
    // Array de ponteiros para os arrays
    int* arrays[] = {A, B, C, D};
    // Array com os tamanhos de cada array
    int sizes[] = {nA, nB, nC, nD};
    // Número de arrays
    int num_arrays = sizeof(arrays) / sizeof(arrays[0]);
    
    // Calcula o tamanho total do array resultante
    int total_size = 0;
    for (int i = 0; i < num_arrays; i++) {
        total_size += sizes[i];
    }
    // Novo array para o resultado
    int* result = (int*)malloc(total_size * sizeof(int));
    if (!result) {
        printf("Erro na alocação de memória!\n");
        return 1;
    }
    
    printf("Arrays originais:\n");
    for (int i = 0; i < num_arrays; i++) {
        printf("Array %d: ", i + 1);
        printArray(arrays[i], sizes[i]);
    }
    
    // Ordena cada array individualmente
    for (int i = 0; i < num_arrays; i++) {
        MergeSort(arrays[i], 0, sizes[i] - 1);
    }
    
    printf("\nArrays ordenados individualmente:\n");
    for (int i = 0; i < num_arrays; i++) {
        printf("Array %d ordenado: ", i + 1);
        printArray(arrays[i], sizes[i]);
    }
    mergeMultipleArrays(arrays, sizes, num_arrays, result, total_size);
    printf("\nTodos os arrays combinados e ordenados:\n");
    printArray(result, total_size);
    free(result);
    return 0;
}
