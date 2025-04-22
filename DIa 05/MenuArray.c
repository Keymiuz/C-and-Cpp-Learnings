// Menu de Array usando C
#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura Array
struct Array {
    int *A;
    int size;
    int length;
};

// Função para exibir os elementos do array
void Display(struct Array arr) {
    int i;
    printf("\nElementos são:\n");
    for (i = 0; i < arr.length; i++) {
        printf("%d ", arr.A[i]);
    }
    printf("\n");
}

// Função para adicionar um elemento ao final do array
void Append(struct Array *arr, int x) {
    if (arr->length < arr->size) {
        arr->A[arr->length++] = x;
    } else {
        printf("Array cheio! Não é possível adicionar.\n");
    }
}

// Função para inserir um elemento em uma posição específica
void Insert(struct Array *arr, int index, int x) {
    int i;
    if (index >= 0 && index <= arr->length) {
        for (i = arr->length; i > index; i--) {
            arr->A[i] = arr->A[i - 1];
        }
        arr->A[index] = x;
        arr->length++;
    } else {
        printf("Índice inválido!\n");
    }
}

// Função para deletar um elemento de uma posição específica
int Delete(struct Array *arr, int index) {
    int x = 0;
    int i;

    if (index >= 0 && index < arr->length) {
        x = arr->A[index];
        for (i = index; i < arr->length - 1; i++) {
            arr->A[i] = arr->A[i + 1];
        }
        arr->length--;
        return x;
    }
    printf("Índice inválido! Nenhum elemento deletado.\n");
    return 0;
}

// Função auxiliar para trocar dois inteiros
void swap(int *x, int *y) {
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

// Função para busca linear
int LinearSearch(struct Array *arr, int key) {
    int i;
    for (i = 0; i < arr->length; i++) {
        if (key == arr->A[i]) {
            swap(&arr->A[i], &arr->A[0]);
            return i;
        }
    }
    return -1;
}

// Função para busca binária
int BinarySearch(struct Array arr, int key) {
    int l, mid, h;
    l = 0;
    h = arr.length - 1;

    while (l <= h) {
        mid = (l + h) / 2;
        if (key == arr.A[mid]) {
            return mid;
        } else if (key < arr.A[mid]) {
            h = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return -1;
}

// Função recursiva para busca binária
int RBinSearch(int a[], int l, int h, int key) {
    int mid;
    if (l <= h) {
        mid = (l + h) / 2;
        if (key == a[mid]) {
            return mid;
        } else if (key < a[mid]) {
            return RBinSearch(a, l, mid - 1, key);
        } else {
            return RBinSearch(a, mid + 1, h, key);
        }
    }
    return -1;
}

// Função para obter o elemento em um determinado índice
int Get(struct Array arr, int index) {
    if (index >= 0 && index < arr.length) {
        return arr.A[index];
    }
    return -1;
}

// Função para definir o valor de um elemento em um determinado índice
void Set(struct Array *arr, int index, int x) {
    if (index >= 0 && index < arr->length) {
        arr->A[index] = x;
    } else {
        printf("Índice inválido!\n");
    }
}

// Função para encontrar o elemento máximo no array
int Max(struct Array arr) {
    int max = arr.A[0];
    int i;
    for (i = 1; i < arr.length; i++) {
        if (arr.A[i] > max) {
            max = arr.A[i];
        }
    }
    return max;
}

// Função para encontrar o elemento mínimo no array
int Min(struct Array arr) {
    int min = arr.A[0];
    int i;
    for (i = 1; i < arr.length; i++) {
        if (arr.A[i] < min) {
            min = arr.A[i];
        }
    }
    return min;
}

// Função para calcular a soma dos elementos do array
int Sum(struct Array arr) {
    int s = 0;
    int i;
    for (i = 0; i < arr.length; i++) {
        s += arr.A[i];
    }
    return s;
}

// Função para calcular a média dos elementos do array
float Avg(struct Array arr) {
    if (arr.length > 0) {
        return (float)Sum(arr) / (float)arr.length;
    } else {
        return 0;
    }
}

// Função para inverter a ordem dos elementos do array
void Reverse(struct Array *arr) {
    int *B;
    int i, j;
    B = (int *)malloc((size_t)arr->length * sizeof(int));
    if (B == NULL) return;
    for (i = arr->length - 1, j = 0; i >= 0; i--, j++) {
        B[j] = arr->A[i];
    }
    for (i = 0; i < arr->length; i++) {
        arr->A[i] = B[i];
    }
    free(B);
}

// Função para inverter a ordem dos elementos do array (sem array auxiliar)
void Reverse2(struct Array *arr) {
    int i, j;
    for (i = 0, j = arr->length - 1; i < j; i++, j--) {
        swap(&arr->A[i], &arr->A[j]);
    }
}

// Função para inserir um elemento em um array ordenado
void InsertSort(struct Array *arr, int x) {
    int i = arr->length - 1;
    if (arr->length == arr->size) return;
    while (i >= 0 && arr->A[i] > x) {
        arr->A[i + 1] = arr->A[i];
        i--;
    }
    arr->A[i + 1] = x;
    arr->length++;
}

// Função para verificar se o array está ordenado
int isSorted(struct Array arr) {
    int i;
    for (i = 0; i < arr.length - 1; i++) {
        if (arr.A[i] > arr.A[i + 1]) {
            return 0;
        }
    }
    return 1;
}

// Função para rearranjar o array (negativos antes dos não negativos)
void Rearrange(struct Array *arr) {
    int i = 0, j = arr->length - 1;
    while (i < j) {
        while (i < arr->length && arr->A[i] < 0) i++;
        while (j >= 0 && arr->A[j] >= 0) j--;
        if (i < j) swap(&arr->A[i], &arr->A[j]);
    }
}

// Função para fazer o merge de dois arrays ordenados
struct Array *Merge(struct Array *arr1, struct Array *arr2) {
    int i = 0, j = 0, k = 0;
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));
    if (arr3 == NULL) return NULL;
    arr3->A = (int *)malloc((size_t)(arr1->length + arr2->length) * sizeof(int));
    if (arr3->A == NULL) {
        free(arr3);
        return NULL;
    }
    while (i < arr1->length && j < arr2->length) {
        if (arr1->A[i] < arr2->A[j]) {
            arr3->A[k++] = arr1->A[i++];
        } else {
            arr3->A[k++] = arr2->A[j++];
        }
    }
    for (; i < arr1->length; i++) arr3->A[k++] = arr1->A[i];
    for (; j < arr2->length; j++) arr3->A[k++] = arr2->A[j];
    arr3->length = arr1->length + arr2->length;
    arr3->size = arr1->length + arr2->length;
    return arr3;
}

// Função para fazer a união de dois arrays ordenados
struct Array *Union(struct Array *arr1, struct Array *arr2) {
    int i = 0, j = 0, k = 0;
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));
    if (arr3 == NULL) return NULL;
    arr3->A = (int *)malloc((size_t)(arr1->length + arr2->length) * sizeof(int));
    if (arr3->A == NULL) {
        free(arr3);
        return NULL;
    }
    while (i < arr1->length && j < arr2->length) {
        if (arr1->A[i] < arr2->A[j]) {
            arr3->A[k++] = arr1->A[i++];
        } else if (arr2->A[j] < arr1->A[i]) {
            arr3->A[k++] = arr2->A[j++];
        } else {
            arr3->A[k++] = arr1->A[i++];
            j++;
        }
    }
    for (; i < arr1->length; i++) arr3->A[k++] = arr1->A[i];
    for (; j < arr2->length; j++) arr3->A[k++] = arr2->A[j];
    arr3->length = k;
    arr3->size = k;
    return arr3;
}

// Função para fazer a interseção de dois arrays ordenados
struct Array *Intersection(struct Array *arr1, struct Array *arr2) {
    int i = 0, j = 0, k = 0;
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));
    if (arr3 == NULL) return NULL;
    arr3->A = (int *)malloc((size_t)(arr1->length < arr2->length ? arr1->length : arr2->length) * sizeof(int));
    if (arr3->A == NULL) {
        free(arr3);
        return NULL;
    }
    while (i < arr1->length && j < arr2->length) {
        if (arr1->A[i] < arr2->A[j]) {
            i++;
        } else if (arr2->A[j] < arr1->A[i]) {
            j++;
        } else if (arr1->A[i] == arr2->A[j]) {
            arr3->A[k++] = arr1->A[i++];
            j++;
        }
    }
    arr3->length = k;
    arr3->size = k;
    return arr3;
}

// Função para encontrar a diferença entre dois arrays ordenados
struct Array *Difference(struct Array *arr1, struct Array *arr2) {
    int i = 0, j = 0, k = 0;
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));
    if (arr3 == NULL) return NULL;
    arr3->A = (int *)malloc((size_t)arr1->length * sizeof(int));
    if (arr3->A == NULL) {
        free(arr3);
        return NULL;
    }
    while (i < arr1->length && j < arr2->length) {
        if (arr1->A[i] < arr2->A[j]) {
            arr3->A[k++] = arr1->A[i++];
        } else if (arr2->A[j] < arr1->A[i]) {
            j++;
        } else {
            i++;
            j++;
        }
    }
    for (; i < arr1->length; i++) arr3->A[k++] = arr1->A[i];
    arr3->length = k;
    arr3->size = k;
    return arr3;
}

int main() {
    struct Array arr1;
    int ch, x, index;

    printf("Digite o Tamanho do Array: ");
    scanf("%d", &arr1.size);
    arr1.A = (int *)malloc((size_t)arr1.size * sizeof(int));
    arr1.length = 0;

    do {
        printf("\n\nMenu\n");
        printf("1. Inserir\n");
        printf("2. Deletar\n");
        printf("3. Buscar\n");
        printf("4. Soma\n");
        printf("5. Exibir\n");
        printf("6. Sair\n");

        printf("Escolha: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Digite o elemento e o índice: ");
                scanf("%d%d", &x, &index);
                Insert(&arr1, index, x);
                break;
            case 2:
                printf("Digite o índice a ser deletado: ");
                scanf("%d", &index);
                x = Delete(&arr1, index);
                printf("Elemento deletado: %d\n", x);
                break;
            case 3:
                printf("Digite o elemento a ser buscado: ");
                scanf("%d", &x);
                index = LinearSearch(&arr1, x);
                if (index != -1) {
                    printf("Elemento encontrado no índice: %d\n", index);
                } else {
                    printf("Elemento não encontrado.\n");
                }
                break;
            case 4:
                printf("Soma dos elementos: %d\n", Sum(arr1));
                break;
            case 5:
                Display(arr1);
                break;
        }
    } while (ch != 6);

    free(arr1.A);
    return 0;
}