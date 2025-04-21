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

int main()
{
    struct Array arr = {{23, 3, 4, 14, 25}, 10, 5};

    printf("%d\n", Get(arr, 0));
    printf("%d\n", Max(arr));
    printf("%d\n", Sum(arr));
    printf("%.2f\n", Avg(arr));

    Set(&arr,0,15);
    printf("%d\n", Get(arr, 0));
    Display(arr);
    return 0;
}
