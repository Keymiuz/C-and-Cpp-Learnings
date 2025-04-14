#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int A[5]={2,4,6,8,10};
    int *p;
    p=A;

    for(int i=0;i<5;i++)
        std::cout << A[i] << std::endl;

    printf("Usando ponteiro: ");
    for(int i=0; i<5; i++) {
        printf("%d ", *(p + i));
    }
    return 0;
}