#include <stdio.h>
#include <stdlib.h>

struct Element {
    int i;
    int j;
    int x;
};

struct Sparse {
    int m;
    int n;
    int num;
    struct Element *ele;
};

void create(struct Sparse *s) {
    printf("Informe as dimensoes da matriz (linhas colunas): ");
    scanf("%d%d", &s->m, &s->n);
    printf("Quantos elementos nao sao zeros? ");
    scanf("%d", &s->num);

    s->ele = (struct Element *)malloc((size_t)s->num * sizeof(struct Element));

    printf("Digite os elementos nao zero (linha coluna valor):\n");
    for (int i = 0; i < s->num; i++) {
        scanf("%d%d%d", &s->ele[i].i, &s->ele[i].j, &s->ele[i].x);
        s->ele[i].i--;
        s->ele[i].j--;
    }
}

void Display(struct Sparse s) {
    int k = 0;
    for (int i = 0; i < s.m; i++) {
        for (int j = 0; j < s.n; j++) {
            if (k < s.num && i == s.ele[k].i && j == s.ele[k].j) {
                printf("%d ", s.ele[k++].x);
            } else {
                printf("0 ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

struct Sparse* add(const struct Sparse* s1, const struct Sparse* s2) {
    if (s1->m != s2->m || s1->n != s2->n) {
        printf("Erro: As dimensoes das matrizes nao sao compativeis para adicao.\n");
        return NULL;
    }

    struct Sparse* s3 = (struct Sparse*)malloc(sizeof(struct Sparse));
    s3->m = s1->m;
    s3->n = s1->n;
    s3->ele = (struct Element*)malloc((size_t)(s1->num + s2->num) * sizeof(struct Element));

    int i = 0, j = 0, k = 0;

    while (i < s1->num && j < s2->num) {
        if (s1->ele[i].i < s2->ele[j].i || (s1->ele[i].i == s2->ele[j].i && s1->ele[i].j < s2->ele[j].j)) {
            s3->ele[k++] = s1->ele[i++];
        } else if (s1->ele[i].i > s2->ele[j].i || (s1->ele[i].i == s2->ele[j].i && s1->ele[i].j > s2->ele[j].j)) {
            s3->ele[k++] = s2->ele[j++];
        } else {
            int sum = s1->ele[i].x + s2->ele[j].x;
            if (sum != 0) {
                s3->ele[k].i = s1->ele[i].i;
                s3->ele[k].j = s1->ele[i].j;
                s3->ele[k].x = sum;
                k++;
            }
            i++;
            j++;
        }
    }

    while (i < s1->num) {
        s3->ele[k++] = s1->ele[i++];
    }

    while (j < s2->num) {
        s3->ele[k++] = s2->ele[j++];
    }

    s3->num = k;

     if (s3->num > 0) {
        s3->ele = (struct Element*)realloc(s3->ele, (size_t)s3->num * sizeof(struct Element));
     } else {
         free(s3->ele);
         s3->ele = NULL;
     }

    return s3;
}

int main() {
    struct Sparse s1, s2, *s3 = NULL;

    printf("Criando a primeira matriz:\n");
    create(&s1);

    printf("\nCriando a segunda matriz:\n");
    create(&s2);

    s3 = add(&s1, &s2);

    printf("\nPrimeira Matriz:\n");
    Display(s1);

    printf("Segunda Matriz:\n");
    Display(s2);

    if (s3 != NULL) {
        printf("Matriz Soma:\n");
        Display(*s3);

        free(s3->ele);
        free(s3);
    }

    free(s1.ele);
    free(s2.ele);

    return 0;
}