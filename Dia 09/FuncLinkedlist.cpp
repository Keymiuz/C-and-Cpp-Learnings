#include <stdio.h>
#include <stdlib.h> 

struct Node {
    int data;
    struct Node *next;
}*first = NULL, *second = NULL, *third = NULL; 

void create(int A[], int n) {
    int i;
    struct Node *t, *last;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    last = first;

    for (i = 1; i < n; i++) {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void create2(int A[], int n) {
    int i;
    struct Node *t, *last;
    second = (struct Node *)malloc(sizeof(struct Node));
    second->data = A[0];
    second->next = NULL;
    last = second;

    for (i = 1; i < n; i++) {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

// Função para exibir a lista encadeada (forma iterativa)
void Display(struct Node *p) {
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n"); 
}

// Função para exibir a lista encadeada (forma recursiva)
void RDisplay(struct Node *p) {
    if (p != NULL) {
        printf("%d ", p->data);
        RDisplay(p->next);
    }
}

int Soma(struct Node *p) {
    if (p == NULL)
        return 0;
    return Soma(p->next) + p->data;
}

int conta(struct Node *p) {
    int x = 0;
    while (p != NULL) {
        x++;
        p = p->next;
    }
    return x;
}

int maior(struct Node *p) {
    // Inicializa max com o menor valor possível para int
    int max = -2147483648; 
    if (p != NULL) {
        max = p->data; 
        p = p->next;   
    }

    while (p != NULL) {
        if (p->data > max) {
            max = p->data;
        }
        p = p->next;
    }
    return max;
}

int menor(struct Node *p) {
    int min = 2147483647; 
    if (p != NULL) {
        min = p->data; 
        p = p->next;   
    }

    while (p != NULL) {
        if (p->data < min) { 
            min = p->data;   
        }
        p = p->next;
    }
    return min;   
}

// Função de busca linear e otimização (Move-To-Front/Transpose)
struct Node * search(struct Node *p, int key) {
    struct Node *q = NULL; // Ponteiro para o nó anterior
    while (p != NULL) {
        if (key == p->data) {
            if (q != NULL) { 
                q->next = p->next;
                p->next = first;
                first = p;
            }
            return p;
        }
        q = p;
        p = p->next;
    }
    return NULL; 
}

void Insert(struct Node *p, int index, int x) {
    struct Node *t;
    int i;

    
    if (index < 0 || index > conta(p)) { 
        printf("Índice inválido para inserção.\n");
        return;
    }
    
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;

    if (index == 0) { 
        t->next = first;
        first = t;
    } else { 
        for (i = 0; i < index - 1; i++) {
            p = p->next;
        }
        t->next = p->next;
        p->next = t;
    }
}

void InsertSorted(struct Node *p, int x) {
    struct Node *t, *q = NULL; 

    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    t->next = NULL;

    if (first == NULL) { 
        first = t;
    } else {
        
        while (p != NULL && p->data < x) {
            q = p; 
            p = p->next;
        }
        if (p == first) { 
            t->next = first;
            first = t;
        } else { 
            t->next = q->next;
            q->next = t;
        }
    }
}

void splitList(struct Node *source, struct Node **frontRef, struct Node **backRef) {
    struct Node *fast;
    struct Node *slow;
    slow = source;
    fast = source->next;

    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    *frontRef = source;
    *backRef = slow->next;
    slow->next = NULL;
}

struct Node *sortedMerge(struct Node *a, struct Node *b) {
    struct Node *result = NULL;

    if (a == NULL) return b;
    if (b == NULL) return a;

    if (a->data <= b->data) {
        result = a;
        result->next = sortedMerge(a->next, b);
    } else {
        result = b;
        result->next = sortedMerge(a, b->next);
    }
    return result;
}

void mergeSort(struct Node **headRef) {
    struct Node *head = *headRef;
    struct Node *a;
    struct Node *b;

    if ((head == NULL) || (head->next == NULL)) {
        return;
    }

    splitList(head, &a, &b);

    mergeSort(&a);
    mergeSort(&b);

    *headRef = sortedMerge(a, b);
}

void Reverse(struct Node *p){
    struct Node *q = NULL, *r = NULL;
    while(p!=NULL){
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    first = q;
}


int main() {
    int A[] = {3, 6, 7, 9}; // Exemplo de array desordenado
    create(A, 4); 
    int B[] = {1, 2, 4, 5};
    create2(B, 4);

    printf("Primeira Lista: ");
    Display(first);
    printf("\n\n");
    printf("Segunda Lista: ");
    Display(second);
    printf("\n\n");

    struct Node *third = NULL;
    third = sortedMerge(first, second);
    printf("Lista Mesclada e Ordenada: ");
    Display(third);
    printf("\n\n");

    printf("Soma: %d\n", Soma(third));
    printf("Quantidade de elementos: %d\n", conta(third));
    printf("Maior elemento: %d\n", maior(third));
    printf("Menor elemento: %d\n", menor(third));
        
    
    struct Node *temp = search(third, 7); 
    if (temp != NULL) {
        printf("Elemento encontrado e movido para o início: %d\n", temp->data);
    } else {
        printf("Elemento não encontrado\n");
    }

    printf("Lista após busca (e possível reorganização): ");
    Display(first);

    Insert(first, 0, 10);     
    Insert(first, 3, 1000);   
    InsertSorted(first, 5); 

    printf("Lista após inserções: ");
    Display(first);

    mergeSort(&first); 

    printf("Lista final ordenada: ");
    Display(first);

    Reverse(first);

    printf("Lista invertida: ");
    Display(first);
    
}