#include <stdio.h>
#include <stdlib.h> 

struct Node {
    int data;
    struct Node *next;
}*first = NULL; 

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
    struct Node *t, *q = NULL; // q é o ponteiro trailing

    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    t->next = NULL;

    if (first == NULL) { 
        first = t;
    } else {
       
        while (p != NULL && p->data < x) {
            q = p; // q acompanha p
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

    // fast avança dois nós, slow avança um nó
    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    // slow é o nó anterior ao ponto médio
    *frontRef = source;
    *backRef = slow->next;
    slow->next = NULL; // Quebra a lista em duas
}

struct Node *sortedMerge(struct Node *a, struct Node *b) {
    struct Node *result = NULL;

    // Casos base
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

    // Divide a lista em 'a' e 'b'
    splitList(head, &a, &b);

    mergeSort(&a);
    mergeSort(&b);

    *headRef = sortedMerge(a, b);
}



int main() {
    int A[] = {3, 6, 7, 2, 9, 1}; // Exemplo de array desordenado
    create(A, 6); 

    printf("Lista original: ");
    Display(first);

    printf("Soma: %d\n", Soma(first));
    printf("Quantidade de elementos: %d\n", conta(first));
    printf("Maior elemento: %d\n", maior(first));
    printf("Menor elemento: %d\n", menor(first));
        
    
    struct Node *temp = search(first, 7); 
    if (temp != NULL) {
        printf("Elemento encontrado e movido para o início: %d\n", temp->data);
    } else {
        printf("Elemento não encontrado\n");
    }

    printf("Lista após busca (e possível reorganização): ");
    Display(first);

    Insert(first, 0, 10);     // Inserção no início
    Insert(first, 3, 1000);   // Inserção na posição 3 (agora é a posição 3 na lista atual)
    InsertSorted(first, 5); 

    printf("Lista após inserções: ");
    Display(first);

    
    mergeSort(&first); 

    printf("Lista final ordenada: ");
    Display(first);

    return 0;
}



// todas as funções acima estão funcionando, inseridas e ordenadas, faltou só a de inverter a lista, que não consegui fazer.