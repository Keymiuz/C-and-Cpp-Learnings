#include <stdio.h>
#include <stdlib.h> 
#include "Queue.h" // Inclui o cabeçalho da Fila

// Variável global para a raiz da árvore
struct No *raiz = NULL;

// Função para criar a Árvore Binária
void criarArvore()
{
    struct No *p, *t;
    int x;
    struct Fila f; 
    criarFila(&f, 100); 

    printf("Entre com o valor da raiz: ");
    scanf("%d", &x);

    raiz = (struct No *)malloc(sizeof(struct No));
    if (raiz == NULL) {
        fprintf(stderr, "Erro: Falha na alocação de memória para o nó raiz.\n");
        exit(EXIT_FAILURE);
    }
    raiz->dado = x;
    raiz->filhoEsquerdo = raiz->filhoDireito = NULL;
    enfileirar(&f, raiz);

    while (!estaVazia(&f)) 
    {
        p = desenfileirar(&f);

        
        if (p == NULL) {
            printf("Erro: Desenfileirou um ponteiro NULL. Abortando criacao da arvore.\n");
            break; // Sai do loop para evitar segfault
        }

        printf("Entre com o valor do filho esquerdo de %d (-1 para nenhum): ", p->dado);
        scanf("%d", &x);
        if (x != -1)
        {
            t = (struct No *)malloc(sizeof(struct No));
            if (t == NULL) {
                fprintf(stderr, "Erro: Falha na alocação de memória para o filho esquerdo.\n");
                exit(EXIT_FAILURE);
            }
            t->dado = x;
            t->filhoEsquerdo = t->filhoDireito = NULL;
            p->filhoEsquerdo = t;
            enfileirar(&f, t);
        }

        printf("Entre com o valor do filho direito de %d (-1 para nenhum): ", p->dado);
        scanf("%d", &x);
        if (x != -1)
        {
            t = (struct No *)malloc(sizeof(struct No));
            if (t == NULL) {
                fprintf(stderr, "Erro: Falha na alocação de memória para o filho direito.\n");
                exit(EXIT_FAILURE);
            }
            t->dado = x;
            t->filhoEsquerdo = t->filhoDireito = NULL;
            p->filhoDireito = t;
            enfileirar(&f, t);
        }
    }
    destruirFila(&f); 
}

// Travessia Preordem
void Preordem(struct No *p)
{
    if (p)
    {
        printf("%d ", p->dado);
        Preordem(p->filhoEsquerdo);
        Preordem(p->filhoDireito);
    }
}

// Travessia Emordem
void Emordem(struct No *p)
{
    if (p)
    {
        Emordem(p->filhoEsquerdo);
        printf("%d ", p->dado);
        Emordem(p->filhoDireito);
    }
}

// Travessia Posordem
void Posordem(struct No *p)
{
    if (p)
    {
        Posordem(p->filhoEsquerdo);
        Posordem(p->filhoDireito);
        printf("%d ", p->dado);
    }
}

// Função para liberar todos os nós da árvore e evitar vazamentos de memória
void liberarArvore(struct No* no) {
    if (no == NULL) {
        return;
    }
    liberarArvore(no->filhoEsquerdo);
    liberarArvore(no->filhoDireito);
    free(no);
}

int main()
{
    criarArvore();

    printf("\nTravessia Preordem: ");
    Preordem(raiz);
    printf("\n");
    
    printf("Travessia Emordem: ");
    Emordem(raiz);
    printf("\n");

    printf("Travessia Posordem: ");
    Posordem(raiz);
    printf("\n");

    // Libera a memória de todos os nós da árvore ao final
    liberarArvore(raiz);
    raiz = NULL; // Evita ponteiro pendurado para o que foi liberado

    return 0;
}