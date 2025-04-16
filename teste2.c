#include <stdio.h>

void foo (int n, int sum) {
    int k = 0, j = 0;

    if (n == 0) return; // Correção: Usar == para comparação

    k = n % 10;
    j = n / 10;

    sum = sum + k;

    foo (j, sum);

    printf("%d", k); // Correção: Usar aspas duplas para string
}

int main () {
    int a = 2048, sum = 0;
    foo (a, sum);
    printf("%d\n", sum);
    return 0; // Boa prática adicionar return 0;
}