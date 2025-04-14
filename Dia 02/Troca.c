#include <stdio.h> 

void trocarValores(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int x = 5, y = 10;
    printf("Antes da troca: x = %d, y = %d\n", x, y); 
    trocarValores(&x, &y);
    printf("Depois da troca: x = %d, y = %d\n", x, y); 
    return 0;
}


//isto é considerado um "call by address", onde o endereço da variável é passado para a função, permitindo que a função altere o valor original da variável.
// Isso é útil quando você deseja que a função modifique os valores de variáveis fora de seu escopo local, como no exemplo acima.
