#include <stdio.h>
#include <stdlib.h>

struct Array
{
    int A[10];
    int size;
    int length;
};

void Display(struct Array arr)
{
    int i;
    printf("\nElementos\n");
    for (i = 0; i < arr.length; i++)
        printf("%d ", arr.A[i]);
    printf("\n");
}

void Append(struct Array *arr, int x)
{
    if (arr->length < arr->size)
        arr->A[arr->length++] = x;
}

void Insert(struct Array *arr, int index, int x)
{
    int i;
    if (index >= 0 && index <= arr->length && arr->length < arr->size)
    {
        for (i = arr->length; i > index; i--)
            arr->A[i] = arr->A[i - 1];
        arr->A[index] = x;
        arr->length++;
    }
    else if (arr->length == arr->size)
    {
        printf("Erro: Array cheio, não é possível inserir.\n");
    }
    else
    {
        printf("Erro: Índice inválido para inserção.\n");
    }
}

int Delete(struct Array *arr, int index)
{
    int x = 0;
    int i;

    if (index >= 0 && index < arr->length)
    {
        x = arr->A[index];
        for (i = index; i < arr->length - 1; i++)
            arr->A[i] = arr->A[i + 1];
        arr->length--;
        return x;
    }
    return -1; // Retorna -1 para indicar que a exclusão falhou (índice inválido)
}

int main()
{
    struct Array arr = {{2, 3, 4, 5, 6}, 10, 5};

    Insert(&arr, 5, 10);

    printf("Elemento deletado: %d\n", Delete(&arr, 4));
    Display(arr);
    return 0;
}


// No Fim este arquivo acabou virando sobre todas as funções dos arrays, append, delete, como exibir tudo em display
// Linear search, etc