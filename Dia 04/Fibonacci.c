#include <stdio.h>

long long int fib_iterativo(int n) {
    if (n <= 1) {
        return n;
    }
    long long int a = 0;
    long long int b = 1;
    long long int temp;
    for (int i = 2; i <= n; i++) {
        temp = a + b;
        a = b;
        b = temp;
    }
    return b;
}

int main() {
    long long int resultado = fib_iterativo(56);
    printf("%lld\n", resultado); // Use %lld para imprimir long long int
    return 0;
}


// a versão antiga que eu tinha feito demorava muito pra rodar o código, então decidi
// fazer esta versão iterativa com um long long int, capaz de armazenar um valor maior
// sem dar overflow de inteiro (eu também tinha feito uma versão que isso acontecia e me voltava um valor negativo KKKKKKKKKK)



// por isso aprendi sobre o long long int (que deixa também o código mais rápido e fluido com iteratividade (loop n e calculo Bottom-Up )) 