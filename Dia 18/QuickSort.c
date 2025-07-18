#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int A[], int l, int h) {
    int pivot = A[l];
    int i = l + 1;
    int j = h;

    while (i <= j) {
        while (i <= j && A[i] <= pivot) i++;
        while (i <= j && A[j] > pivot) j--;
        
        if (i < j) {
            swap(&A[i], &A[j]);
            i++;
            j--;
        }
    }
    
    swap(&A[l], &A[j]);
    return j;
}// neste código, o partition serve para encontrar o pivô e ordenar o array de forma que todos os elementos menores que o pivô 
// fiquem à esquerda e todos os elementos maiores que o pivô fiquem à direita (o pivô é o primeiro elemento do subarray)

void QuickSort(int A[],int l,int h) {
 int j;
 if(l<h) {
    j=partition(A,l,h);
    QuickSort(A,l,j-1);
    QuickSort(A,j+1,h);
 }
} // implementação do quicksort com recursão por divisão de subarrays com auxílio do pivô. 


void printArray(int A[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
}


void SelectionSort(int A[], int n) {
    int i, j, min;
    for (i = 0; i < n - 1; i++) {
        min = i;
        for (j = i + 1; j < n; j++) {
            if (A[j] < A[min]) {
                min = j;
            }
        }
        swap(&A[i], &A[min]);
    }
}

void BubbleSort(int A[], int n) {
    int i, j;
    int flag;
    for (i = 0; i < n - 1; i++) {
        flag = 0;
        for (j = 0; j < n - i - 1; j++) {
            if (A[j] > A[j + 1]) {
                swap(&A[j], &A[j + 1]);
                flag = 1;
            }
        }
        if (flag == 0) {
            break;
        }
    }
}

void InsertionSort(int A[], int n) {
    int i, j, key;
    for (i = 1; i < n; i++) {
        key = A[i];
        j = i - 1;
        while (j > -1 && A[j] > key) {
            A[j + 1] = A[j];
            j = j - 1;
        }
        A[j + 1] = key;
    }
}

int main(){
 int A[]={11,13,7,12,16,9,24,5,10,3},n=10,i;

 QuickSort(A, 0, n-1);

 for(i=0;i<n;i++){
 printf("%d ",A[i]);
 }
 printf("\n");
 return 0;
}
