#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
}*first=NULL;

void create(int A[], int n) {
    int i;
    struct Node *t, *last;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    last = first;

    for(i=1;i<n;i++){
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void Display(struct Node *p) {
    while(p!=NULL){
        printf("%d ", p->data);
        p = p->next;
    }
}  //forma iterativa

void RDisplay(struct Node *p) {
    if(p!=NULL){
        printf("%d ", p->data);
        RDisplay(p->next);
    }
}  //forma recursiva

int Soma(struct Node *p) {
    if(p==NULL)
        return 0;
    return Soma(p->next) + p->data;
}

int conta(struct Node *p) {
    int x = 0;
    while(p!=NULL){
        x++;
        p = p->next;
    }
    return x;
}

int maior(struct Node *p) {
    int max = -2147483648; 
    if (p != NULL) {
        max = p->data; // Inicializa com o primeiro elemento da lista
        p = p->next;   // Move para o próximo nó
    }

    while(p!=NULL){
        if (p->data > max) {
            max = p->data;
        }
        p = p->next;
    }
    return max;
}

int menor(struct Node *p) {
    int min = 214748364; 
    if (p != NULL) {
        min = p->data; 
        p = p->next;   
    }

    while(p!=NULL){
        if (p->data < min) { 
            min = p->data;   
        }
        p = p->next;
    }
    return min;   
}

struct Node * search(struct Node *p, int key) {
    struct Node *q = NULL;
    while(p!=NULL){
        if(key==p->data){
            q->next = p->next;
            p->next = first;
            first = p;
            return p;
        }
        q = p;
        p = p->next; // optimização para o caso de o elemento estar no primeiro nó(com busca linear por nós)
    }
    return NULL;
}

void Insert(struct Node *p, int index, int x){
    struct Node *t;
    int i;
    if(index<0 || index>conta(p))
        return;
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;

    if(index==0){
        t->next = first;
        first = t;
    }
    else{
        for(i=0;i<index-1;i++){
            p = p->next;
        }
        t->next = p->next;
        p->next = t;
    }
}

int main() {
    int A[] = {3,6,7};    
    create(A,3); // essa linha delimita todas as funções que serão usadas (para operações)
    printf("Soma: %d\n", Soma(first));
    printf("Quantidade de elementos: %d\n", conta(first));
    printf("Maior elemento: %d\n", maior(first));
    printf("Menor elemento: %d\n", menor(first));
        
    struct Node *temp = search(first, 7);// essa linha é a que faz a busca e procura o numero que eu inserir na segunda parte.    
    if(temp!=NULL){
        printf("Elemento encontrado: %d\n", temp->data);
    }
    else{
        printf("Elemento não encontrado\n");
    }
    Insert(first, 0, 10);
    Insert(first, 1, 1000);
    Display(first);

}


