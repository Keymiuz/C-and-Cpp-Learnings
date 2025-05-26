#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum TipoMatriz {
    TRIANGULAR_INFERIOR,
    TRIANGULAR_SUPERIOR
};

struct MatrizTriangular {
    int *valores;
    int dimensao;
    enum TipoMatriz tipo;
};


void inicializar(struct MatrizTriangular *m, int n, enum TipoMatriz tipo) {
    m->dimensao = n;
    m->tipo = tipo;
    m->valores = (int *)malloc(n * (n + 1) / 2 * sizeof(int));
}


int calcularIndice(struct MatrizTriangular *m, int i, int j) {
    if (m->tipo == TRIANGULAR_INFERIOR) {
        // Somente se i >= j
        return i >= j ? m->dimensao * (j - 1) + (j - 2) * (j - 1) / 2 + i - j : -1;
    } else {
        // TRIANGULAR SUPERIOR: Somente se i <= j
        return i <= j ? m->dimensao * (i - 1) + (i - 2) * (i - 1) / 2 + j - i : -1;
    }
}


void definir(struct MatrizTriangular *m, int i, int j, int valor) {
    int indice = calcularIndice(m, i, j);
    if (indice != -1) {
        m->valores[indice] = valor;
    }
}


int obter(struct MatrizTriangular *m, int i, int j) {
    int indice = calcularIndice(m, i, j);
    if (indice != -1) {
        return m->valores[indice];
    }
    return 0;
}

void exibir(struct MatrizTriangular *m) {
    int i, j;
    for (i = 1; i <= m->dimensao; i++) {
        for (j = 1; j <= m->dimensao; j++) {
            printf("%d ", obter(m, i, j));
        }
        printf("\n");
    }
}


void destruir(struct MatrizTriangular *m) {
    free(m->valores);
} //liberação de memória padrão fifa


int main() {
    struct MatrizTriangular matriz;
    int n, tipo, i, j, valor;

    printf("Informe a dimensão da matriz: ");
    scanf("%d", &n);

    printf("Tipo da matriz:\n");
    printf("1 - Triangular Inferior\n");
    printf("2 - Triangular Superior\n");
    printf("Escolha (1 ou 2): ");
    scanf("%d", &tipo);

    inicializar(&matriz, n, tipo == 1 ? TRIANGULAR_INFERIOR : TRIANGULAR_SUPERIOR);

    printf("Digite os elementos da matriz:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &valor);
            definir(&matriz, i, j, valor);
        }
    }

    printf("\nMatriz resultante:\n");
    exibir(&matriz);

    destruir(&matriz);
    return 0;
}



