#include <stdio.h>
#include <stdlib.h> 


struct Term
{
    int coeff; // Coeficiente do termo
    int exp;   // Expoente do termo
};

struct Poly
{
    int n;         // Número de termos no polinômio
    struct Term *terms; // Ponteiro para um array de termos
};


void create(struct Poly *p)
{
    int i;
    printf("Digite o numero de termos para o polinomio: ");
    scanf("%d", &p->n);

   
    p->terms = (struct Term *)malloc(p->n * sizeof(struct Term));

    // Verifica se a alocacao de memoria foi bem sucedida
    if (p->terms == NULL) {
        printf("Erro: Falha na alocacao de memoria!\n");
        p->n = 0; 
        return;
    }

    printf("Digite os termos (coeficiente expoente) em ordem decrescente de expoentes:\n");
    for (i = 0; i < p->n; i++)
    {
        printf("Termo %d: ", i + 1);
        scanf("%d %d", &p->terms[i].coeff, &p->terms[i].exp);
    }
}


void display(const struct Poly *p)
{
    int i;
    int primeiro_termo = 1; // Flag para tratar o sinal '+' corretamente

    if (p->n == 0) {
        printf("0\n"); 
        return;
    }

    for (i = 0; i < p->n; i++)
    {
        // Ignora termos com coeficiente zero, a menos que seja o único termo e o expoente seja 0
        if (p->terms[i].coeff == 0 && (p->n > 1 || p->terms[i].exp != 0)) {
            continue;
        }

        // Imprime o sinal '+' antes dos termos, exceto o primeiro termo não nulo
        if (!primeiro_termo && p->terms[i].coeff > 0) {
            printf("+");
        }

        // Trata a exibição do coeficiente (esconde 1 ou -1 se não for termo constante)
        if (p->terms[i].coeff != 1 && p->terms[i].coeff != -1 || p->terms[i].exp == 0) {
            printf("%d", p->terms[i].coeff);
        } else if (p->terms[i].coeff == -1) {
            printf("-");
        }

        // Trata a exibição da variável e expoente
        if (p->terms[i].exp > 1) {
            printf("x^%d", p->terms[i].exp);
        } else if (p->terms[i].exp == 1) {
            printf("x");
        } else if (p->terms[i].exp == 0 && (p->terms[i].coeff == 1 || p->terms[i].coeff == -1) && p->n == 1) {
             if (p->terms[i].coeff == 1) printf("1");
             if (p->terms[i].coeff == -1) printf("-1");
        }

        primeiro_termo = 0; 
    }

     // Se todos os termos eram zero e n > 0
    if (primeiro_termo && p->n > 0) {
         int todos_zero = 1;
         for(i=0; i < p->n; i++) {
             if (p->terms[i].coeff != 0) {
                 todos_zero = 0;
                 break;
             }
         }
         if (todos_zero) printf("0");
    }


    printf("\n");
}

// Função para somar dois polinômios
struct Poly *add(const struct Poly *p1, const struct Poly *p2)
{
    int i, j, k;
    struct Poly *sum;

    
    sum = (struct Poly *)malloc(sizeof(struct Poly));
     if (sum == NULL) {
        printf("Erro: Falha na alocacao de memoria para o polinomio soma!\n");
        return NULL;
    }

    sum->terms = (struct Term *)malloc((p1->n + p2->n) * sizeof(struct Term));
     if (sum->terms == NULL) {
         printf("Erro: Falha na alocacao de memoria para os termos da soma!\n");
         free(sum); // Libera a memória alocada para a estrutura
         return NULL;
    }


    i = 0; 
    j = 0; 
    k = 0; 

    // Mescla os termos de p1 e p2 com base nos expoentes (assumindo ordem decrescente)
    while (i < p1->n && j < p2->n)
    {
        if (p1->terms[i].exp > p2->terms[j].exp)
        {
            // Termo de p1 tem expoente maior, adiciona ele à soma
            sum->terms[k++] = p1->terms[i++];
        }
        else if (p1->terms[i].exp < p2->terms[j].exp)
        {
            // Termo de p2 tem expoente maior, adiciona ele à soma
            sum->terms[k++] = p2->terms[j++];
        }
        else
        {
            // Expoentes são iguais, soma os coeficientes
            sum->terms[k].exp = p1->terms[i].exp;
            sum->terms[k++].coeff = p1->terms[i++].coeff + p2->terms[j++].coeff;
        }
    }

   
    while (i < p1->n)
    {
        sum->terms[k++] = p1->terms[i++];
    }

    
    while (j < p2->n)
    {
        sum->terms[k++] = p2->terms[j++];
    }

    sum->n = k;

   
    return sum; 
}

int main()
{
    struct Poly p1, p2, *p3 = NULL; 

   
    printf("--- Criando Polinomio 1 ---\n");
    create(&p1);

  
    printf("\n--- Criando Polinomio 2 ---\n");
    create(&p2);

   
    printf("\n--- Somando Polinomios ---\n");
    p3 = add(&p1, &p2);


    printf("\n--- Polinomios ---\n");
    printf("Polinomio 1: ");
    display(&p1);

    printf("Polinomio 2: ");
    display(&p2);

    printf("\n--- Soma ---\n");
    printf("Soma: ");
    if (p3 != NULL) {
        display(p3);
    } else {
        printf("Erro ao calcular a soma.\n");
    }


   
    free(p1.terms);
    free(p2.terms);
    if (p3 != NULL) {
        free(p3->terms);
        free(p3);
    }

    return 0;
}