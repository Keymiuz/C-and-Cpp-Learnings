#include <stdio.h>

int main(){
    int A[5];
    int i;


    
    for (i = 0; i < 5; i++)
        A[i] = i * 1;       // Inicializando o array com alguns valores
    
        

    for (i=0;i<5;i++)
        printf("%d \n", A[i]); // mesmo método, mas agora para printar
}