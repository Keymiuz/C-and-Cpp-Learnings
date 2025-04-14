#include <stdio.h>
#include <stdlib.h>

struct Rectangle {      
    int length;
    int breadth;
};  // o código é feito em C, por isso precisa do struc, em c++ eu não precisaria declarar um struc, só chamar a variavel já seria bom

int main() {
    struct Rectangle *P;
    P = (struct Rectangle *)malloc(sizeof(struct Rectangle)); /// se o código for em C++ eu posso só dar "new Rectangle KKKKKKKK"
    P->length = 10;
    P->breadth = 5;

    
    printf("Length: %d\n", P->length);
    printf("Breadth: %d\n", P->breadth);

    
    free(P); // É importante liberar a memória alocada dinamicamente, por isso já estou começando a usar, ainda não vou atribuir valores nulos depois, mesmo o chat recomendando
    // pq não vi necessidade em um código tão básico
    return 0;
}