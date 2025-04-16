#include <stdio.h>

int main() {

    int array_2d[2][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}};

    printf("Valores desse Array em 2D:\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%d ", array_2d[i][j]);
        }
        printf("\n");
    }
    return 0;
}

// O endereço base de um array é atualizado quando o programa começa a rodar