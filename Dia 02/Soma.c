#include <stdio.h>

int add(int a, int b) { //isto é chamado de função protótipo
    int c;
    c = a + b;
    return c;
}

int main() {             //função main ou função declarada 
    int x, y, z;
    x = 10;
    y = 5;
    z = add(x, y);
    printf("A soma e %d", z);

    return 0;
}