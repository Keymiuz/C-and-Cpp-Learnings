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
    for(i=1;i<n;i++){
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = last->next;
        t->prev = last;
        last->next = t;
        last = t;
    }
}   

void Display(struct Node *p) {
    while(p!=NULL){
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}   

int Lenght(struct Node *p) {
    int len = 0;
    while(p!=NULL){
        len++;
        p = p->next;
    }
    return len;
}

void Insert(struct Node *p, int index, int x) {
    struct Node *t;
    int i;
    if(index < 0 || index > Lenght(p)) return;
    if(index == 0){
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = x;
        if(first==NULL){
            first = t;
            first->next = first->prev = NULL;
        }else{
            while(p->next!=first) p = p->next;
            p->next = t;
            t->next = first;
            t->prev = p;
            first = t;
        }   
    }else{
        for(i=0;i<index-1;i++) p = p->next;
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = x;
        t->next = p->next;
        t->prev = p;
        p->next = t;
    }
}

int Delete(struct Node *p, int index) {
    struct Node *q;
    int i;
    int x;
    if(index < 0 || index > Lenght(p)) return -1;
    if(index == 1){
        while(p->next!=first) p = p->next;
        x = first->data;
        if(p==first){
            first = NULL;
            free(first);
        }else{
            p->next = first->next;
            free(first);
            first = p->next;
            first->prev = NULL;
        }
    }else{
        for(i=0;i<index-2;i++) p = p->next;
        q = p->next;    
        p->next = q->next;
        q->next->prev = p;
        x = q->data;
        free(q);
    }
    return x;
}

int main() {
    int A[] = {1, 2, 3, 4, 5};
    create(A, 5);
    Display(first);
    printf("Tamanho é: %d\n", Lenght(first));

    int valor_a_inserir = 10; // valor a inserir
    int posicao_de_insercao = 2; // posicao de insercao

    Insert(first, posicao_de_insercao, valor_a_inserir); // inserindo o valor
    printf("Elemento inserido: %d na posição: %d\n", valor_a_inserir, posicao_de_insercao);
    Display(first);
    printf("Elemento deletado: %d\n", Delete(first, 2)); // deletando o valor
    Display(first);
    printf("Tamanho é: %d\n", Lenght(first)); // comprimento

    return 0;
} 