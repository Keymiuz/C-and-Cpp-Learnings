#include <stdio.h>
#include <stdlib.h>

struct Node {
    int exp, coeff;
    struct Node *next;
}*poly=NULL;

// Função auxiliar para calcular x^n de forma eficiente para inteiros
long long power(int base, int exp) {
    long long res = 1;
    for (int i = 0; i < exp; i++) {
        res *= base;
    }
    return res;
}

void createPolinomial() {
    struct Node *t, *last;
    int number, i;
    printf("Numero de termos: ");
    scanf("%d", &number);
    printf("Coeficientes e expoentes para cada termo:\n");
    
    for(i=0; i<number; i++) {
        t = (struct Node*)malloc(sizeof(struct Node));
        scanf("%d %d", &t->coeff, &t->exp);
        t->next = NULL;
        if(poly == NULL) {
            poly = last = t;
        } else {
            last->next = t;
            last = t;
        }
    }
}    

void Display(struct Node *p) {
    while(p!=NULL) {
        printf("%dx^%d + ", p->coeff, p->exp);
        p = p->next;
    }
    printf("\n");
}

long Eval(struct Node *p, int x) {
    long val = 0;
    while(p!=NULL) {
        // Usamos nossa função 'power' otimizada em vez de 'pow'
        val += p->coeff * power(x, p->exp); 
        p = p->next;
    }
    return val;
}

int main() {
    createPolinomial();
    Display(poly);
    printf("Valor de x: ");
    int x;
    scanf("%d", &x);
    printf("Valor do polinomio em x = %d: %ld\n", x, Eval(poly, x));
    return 0;
}