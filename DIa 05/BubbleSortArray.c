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

int Get (struct Array arr, int index){
    if (index >= 0 && index < arr.length)
    return arr.A[index];
return -1;
}

void Set(struct Array *arr, int index, int x){
    if(index >= 0 && index < arr->length)
    arr->A[index]=x;
}

int Max (struct Array arr){
    int max=arr.A[0];
    int i;
    for(i = 1; i < arr.length;i++){
        if(arr.A[i]>max)
        max=arr.A[i];
    }
    return max;
}

int Min (struct Array arr){
    int min=arr.A[0];
    int i;
    for(i = 1; i < arr.length;i++){
        if(arr.A[i]<min)
        min=arr.A[i];
    }
    return min;
}

int Sum (struct Array arr){
    int s=0;
    int i;
    for(i = 0; i < arr.length;i++)
        s+=arr.A[i];
        return s;
}

float Avg (struct Array arr){
    return (float)Sum(arr)/arr.length;
}

void Swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void BubbleSort(struct Array *arr)
{
    int i, j, flag;

    for (i = 0; i < arr->length - 1; i++)
    {
        flag = 0;
        for (j = 0; j < arr->length - 1 - i; j++)
        {
            if (arr->A[j] > arr->A[j + 1])
            {
                Swap(&arr->A[j], &arr->A[j + 1]);
                flag = 1;
            }
        }
        if (flag == 0)
            break;
    }
}

int main()
{
    struct Array arr = {{23, 3, 4, 14, 25}, 10, 5};

    printf("Antes da ordenacao:\n");
    Display(arr);

    BubbleSort(&arr);

    printf("\nDepois da ordenacao (Bubble Sort):\n");
    Display(arr);

    return 0;
}



//implementação aprimorada do sort apresetado no curso com um método de swap 

//(eu tive que pesquisar e aprendi que no contexto de algoritmos de ordenação como o bubblesort, frequentemente precisamos trocar a posição de dois elementos dentro de um array)

//pense da seguinte forma: temos dois elemtos em ordem errada, então trocamos eles de ordem, e assim sucessivamente até o array estar correto (para arrays maiores lógico kkk)