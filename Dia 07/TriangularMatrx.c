#include <stdio.h>
#include <stdlib.h>

struct Matriz {
    int *valores;
    int dimensao;
};

void definir(struct Matriz *m, int i, int j, int valor) {
    if (i >= j) {
        m->valores[m->dimensao * (j - 1) + (j - 2) * (j - 1) / 2 + i - j] = valor;
    }
};
 
int obter(struct Matriz m, int i, int j) {
    if (i >= j) {
        return m.valores[m.dimensao * (j - 1) + (j - 2) * (j - 1) / 2 + i - j];
    } else {
        return 0;
    }
};

// Função para exibir a matriz completa (levando em consideração as dimensões)
void exibir(struct Matriz m) {
    int i, j;
    for (i = 1; i <= m.dimensao; i++) {
        for (j = 1; j <= m.dimensao; j++) {
            if (i >= j) {
                printf("%d ", m.valores[m.dimensao * (j - 1) + (j - 2) * (j - 1) / 2 + i - j]);
            } else {
                printf("0 ");
            }
        }
        printf("\n");
    }
};

int main() {
    struct Matriz matriz;
    int i, j, valor;

    printf("Informe a dimensão da matriz: ");
    scanf("%d", &matriz.dimensao);

    matriz.valores = (int *)malloc(matriz.dimensao * (matriz.dimensao + 1) / 2 * sizeof(int));

    printf("Digite os elementos da matriz:\n");
    for (i = 1; i <= matriz.dimensao; i++) {
        for (j = 1; j <= matriz.dimensao; j++) {
            scanf("%d", &valor);
            definir(&matriz, i, j, valor);
        }
    }

    printf("\nMatriz triangular inferior:\n");
    exibir(matriz);
    free(matriz.valores);
    return 0;
};



// Esse programa manipula uma matriz triangular inferior,
//  uma matriz quadrada onde apenas os elementos na diagonal principal ou abaixo dela são armazenados. 
// Os elementos acima da diagonal são sempre zero, ent, não são salvos na memória (para economizar espaço).

// Definir a quantidade de elementos: n + (n-1) + (n-2) + ... + 1 = n(n + 1) / 2
// Mapear a matriz por indice: indice = n * (j - 1) + (j - 2) * (j - 1) / 2 + (i - j);
// (j - 2) * (j - 1) / 2 conta quantos elementos existem antes da coluna j
// (i - j) identifica qual é o elemento da coluna j que estamos acessando
