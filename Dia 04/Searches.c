#include <stdio.h>
#include <stdlib.h> // Para usar EXIT_FAILURE e EXIT_SUCCESS

// Definição da estrutura Array
struct Array {
    int *A;     // Ponteiro para o array dinâmico
    int size;   // Tamanho máximo do array
    int length; // Número atual de elementos no array
};

// Função para criar um array dinamicamente
struct Array* createArray(int size) {
    struct Array* arr = (struct Array*)malloc(sizeof(struct Array));
    if (arr == NULL) {
        fprintf(stderr, "Erro ao alocar memória para o array.\n");
        exit(EXIT_FAILURE);
    }
    arr->A = (int*)malloc(size * sizeof(int));
    if (arr->A == NULL) {
        fprintf(stderr, "Erro ao alocar memória para os elementos do array.\n");
        free(arr);
        exit(EXIT_FAILURE);
    }
    arr->size = size;
    arr->length = 0;
    return arr;
}

// Função para liberar a memória alocada para o array
void freeArray(struct Array* arr) {
    free(arr->A);
    free(arr);
}

// Função de Busca Linear
int LinearSearch(struct Array arr, int key) {
    int i;
    for (i = 0; i < arr.length; i++) {
        if (key == arr.A[i]) {
            return i; // Retorna o índice onde a chave foi encontrada
        }
    }
    return -1; // Retorna -1 se a chave não for encontrada
}

// Função de Busca Binária (assume que o array está ordenado)
int BinarySearch(struct Array arr, int key) {
    int l, mid, h;
    l = 0;
    h = arr.length - 1;

    while (l <= h) {
        mid = l + (h - l) / 2; // Evita overflow para arrays grandes
        if (key == arr.A[mid]) {
            return mid; // Retorna o índice onde a chave foi encontrada
        } else if (key < arr.A[mid]) {
            h = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return -1; // Retorna -1 se a chave não for encontrada
}

// Função para exibir os elementos do array
void Display(struct Array arr) {
    if (arr.length == 0) {
        printf("O array está vazio.\n");
        return;
    }
    printf("Elementos do array são: ");
    for (int i = 0; i < arr.length; i++) {
        printf("%d ", arr.A[i]);
    }
    printf("\n");
}

// Função para inserir um elemento em um índice específico
int Insert(struct Array *arr, int index, int value) {
    if (index < 0 || index > arr->length || arr->length == arr->size) {
        return 0; // Falha na inserção: índice inválido ou array cheio
    }
    for (int i = arr->length; i > index; i--) {
        arr->A[i] = arr->A[i - 1]; // Desloca os elementos para a direita
    }
    arr->A[index] = value;
    arr->length++;
    return 1; // Sucesso na inserção
}

// Função para deletar um elemento de um índice específico
int Delete(struct Array *arr, int index) {
    if (index < 0 || index >= arr->length) {
        return 0; // Falha na deleção: índice inválido ou array vazio
    }
    for (int i = index; i < arr->length - 1; i++) {
        arr->A[i] = arr->A[i + 1]; // Desloca os elementos para a esquerda
    }
    arr->length--;
    return 1; // Sucesso na deleção
}

int main() {
    // Criando um array dinâmico com capacidade para 10 elementos
    struct Array* arr = createArray(10);

    
    Insert(arr, 0, 2);
    Insert(arr, 1, 3);
    Insert(arr, 2, 4);
    Insert(arr, 3, 5);
    Insert(arr, 4, 6);

    Display(*arr); // Exibindo os elementos do array

    printf("Busca Linear por 2 no índice: %d\n", LinearSearch(*arr, 2));
    printf("Busca Binária por 5 no índice: %d\n", BinarySearch(*arr, 5));

    Delete(arr, 2); // Deletando o elemento no índice 2 (valor 4)
    Display(*arr);

    Insert(arr, 2, 10); // Inserindo o valor 10 no índice 2
    Display(*arr);

    
    freeArray(arr);

    return 0;
}


// mais um caso de código que está sendo reaproveitado para vários motivos e comentários