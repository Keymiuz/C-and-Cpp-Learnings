#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
}*first=NULL;

void create(int A[], int n) {
    struct Node *t, *last;
    int i;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->prev = first->next = NULL;
    last = first;
    for(i=1; i<n; i++){
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = last->next;
        t->prev = last;
        last->next = t;
        last = t;
    }
}

void Display(struct Node *p) {
    while(p != NULL){
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int Lenght(struct Node *p) {
    int len = 0;
    while(p != NULL){
        len++;
        p = p->next;
    }
    return len;
}

void Insert(struct Node *p, int index, int x) {
    struct Node *t;
    int i;

    if (index < 0 || index > Lenght(p)) return;

    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    t->prev = NULL;
    t->next = NULL;

    if (index == 0) {
        t->next = first;
        if (first) {
            first->prev = t;
        }
        first = t;
    } else {
        for (i = 0; i < index - 1; i++) {
            p = p->next;
        }
        t->next = p->next;
        t->prev = p;
        if (p->next) {
            p->next->prev = t;
        }
        p->next = t;
    }
}

int Delete(struct Node *p, int index) {
    int x = -1;
    int i;

    if (index < 1 || index > Lenght(p)) return -1;

    if (index == 1) {
        first = first->next;
        x = p->data;
        free(p);
        if (first) {
            first->prev = NULL;
        }
    } else {
        for (i = 0; i < index - 1; i++) {
            p = p->next;
        }
        p->prev->next = p->next;
        if (p->next) {
            p->next->prev = p->prev;
        }
        x = p->data;
        free(p);
    }
    return x;
}

void Reverse() {
    if (first == NULL || first->next == NULL) {
        return;
    }
    struct Node *p = first;
    struct Node *temp = NULL;
    while (p != NULL) {
        temp = p->next;
        p->next = p->prev;
        p->prev = temp;

        if (p->prev == NULL) {
            first = p;
        }
        p = p->prev;
    }
}

int main() {
    int A[] = {1, 2, 3, 4, 5};
    create(A, 5);
    printf("Lista Original: ");
    Display(first);
    printf("Tamanho é: %d\n", Lenght(first));
    int valor_a_inserir = 10;
    int posicao_de_insercao = 2;
    Insert(first, posicao_de_insercao, valor_a_inserir);
    printf("\nElemento inserido: %d na posição de índice %d\n", valor_a_inserir, posicao_de_insercao);
    printf("Lista após inserção: ");
    Display(first);
    int pos_delete = 3;
    printf("\nElemento deletado da posição %d: %d\n", pos_delete, Delete(first, pos_delete));
    printf("Lista após deletar o valor: ");
    Display(first);
    printf("Tamanho é: %d\n", Lenght(first));
    printf("\nInvertendo a lista...\n");
    Reverse();
    printf("Lista Invertida: ");
    Display(first);
    return 0;
}




// Diferente de uma linked list linear, a doubly (duplamente encadeada) possui um ponteiro prev que aponta para o nó anterior, você pode ir para frente ou para trás. 
// Cada nó sabe quem é o próximo e também quem é o anterior.

// A principal vantagem de uma doubly é que você pode percorrer a lista de frente para trás ou de trás para frente
// Em uma lista simples, se você tem um ponteiro para um nó que quer deletar, não é o suficiente. Você precisa encontrar o nó anterior a ele para poder "pular" o nó a ser deletado. 
// Isso exige percorrer a lista desde o começo. Em uma lista dupla, se você tem o nó p para deletar, você já tem acesso ao anterior através de p->prev. A operação é imediata, sem precisar de uma busca.


// A principal desvantagem é que você precisa de mais memória para armazenar o ponteiro prev    


// Um exemplo de uma doubly é o control z, que faz você ir e voltar na história de uma página web, ou em um delet que você tenha feito.
// Outro exemplo clássico é uma playlist musical: Os botões "Anterior" e "Próxima" em um player de música são uma aplicação direta de uma lista duplamente encadeada.
