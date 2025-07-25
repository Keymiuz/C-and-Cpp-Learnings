#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Node {
    int exp, coeff;
    struct Node *next;
}*poly=NULL;

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
        val += p->coeff * pow(x, p->exp);
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


// representação de um polinômio com a lista encadeada 
// é uma lista encadeada onde cada nó contém o coeficiente e o expoente de um termo do polinômio



// Listas encadeadas são excelentes para representar estruturas de dados onde o número de elementos não é fixo ou onde há muitos "buracos" (termos com coeficiente zero) no polinômio.
// Por exemplo, se temos um polinômio de grau 1000, mas apenas os termos de grau 500 e 1000 são não nulos, uma lista encadeada é uma representação eficiente.



// Embora neste exemplo a inserção seja sempre no final (o que é simples com last apontando para o último nó), em cenários mais complexos (como adicionar dois polinômios, onde novos termos podem precisar ser inseridos em ordem)
//  listas encadeadas podem facilitar a inserção em qualquer posição sem a necessidade de "shiftar" elementos, como seria necessário em um array.