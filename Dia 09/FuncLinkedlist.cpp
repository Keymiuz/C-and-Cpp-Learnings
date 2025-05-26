#include <stdio.h>
#include <stdlib.h> 

struct Node {
    int data;
    struct Node *next;
}; 


struct Node* create(int A[], int n) {
    struct Node *head = NULL;
    struct Node *t, *last;
    
    if (n <= 0) return NULL; 

    head = (struct Node *)malloc(sizeof(struct Node));
    head->data = A[0];
    head->next = NULL;
    last = head;

    for (int i = 1; i < n; i++) {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
    return head; 
}

struct Node* create2(int A[], int n) {
    struct Node *head = NULL;
    struct Node *t, *last;
    
    if (n <= 0) return NULL;

    head = (struct Node *)malloc(sizeof(struct Node));
    head->data = A[0];
    head->next = NULL;
    last = head;

    for (int i = 1; i < n; i++) {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
    return head; // Retorna o head da lista criada
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
struct Node * search(struct Node **headRef, int key) {
    struct Node *p = *headRef; 
    struct Node *q = NULL;    

    while (p != NULL) {
        if (key == p->data) {
            if (q != NULL) { 
                q->next = p->next; 
                p->next = *headRef; 
                *headRef = p;       
            }
            return p; 
        }
        q = p;
        p = p->next;
    }
    return NULL; 
}

void Insert(struct Node **headRef, int index, int x) {
    struct Node *t;
    struct Node *p = *headRef; // Ponteiro para percorrer
    int i;

    if (index < 0 || index > conta(*headRef)) { 
        printf("Índice inválido para inserção.\n");
        return;
    }
    
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;

    if (index == 0) { // Inserir no início
        t->next = *headRef;
        *headRef = t; // Atualiza o head
    } else { 
        for (i = 0; i < index - 1; i++) {
            p = p->next;
        }
        t->next = p->next;
        p->next = t;
    }
}

void InsertSorted(struct Node **headRef, int x) {
    struct Node *t, *p = *headRef, *q = NULL; 

    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    t->next = NULL;

    if (*headRef == NULL) { // Se a lista estiver vazia
        *headRef = t; // Atualiza o head
    } else {
        while (p != NULL && p->data < x) {
            q = p; 
            p = p->next;
        }
        if (p == *headRef) { // Inserir no início (novo elemento é o menor)
            t->next = *headRef;
            *headRef = t; // Atualiza o head
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

//Invert da lista
void Reverse(struct Node **headRef){
    struct Node *p = *headRef; 
    struct Node *q = NULL, *r = NULL;
    while(p!=NULL){
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    *headRef = q; 
}

// Função para liberar a memória da lista (boa prática)
void freeList(struct Node *head) {
    struct Node *current = head;
    struct Node *next_node;
    while (current != NULL) {
        next_node = current->next;
        free(current);
        current = next_node;
    }
}


int main() {
    struct Node *firstList = NULL;
    struct Node *secondList = NULL;
    struct Node *mergedResultList = NULL; // Usar uma variável local para o resultado da mesclagem

    int A[] = {3, 6, 7, 9}; 
    firstList = create(A, 4); // Crie a primeira lista

    int B[] = {1, 2, 4, 5};
    secondList = create2(B, 4); // Crie a segunda lista

    printf("Primeira Lista: ");
    Display(firstList);
    printf("\n");
    printf("Segunda Lista: ");
    Display(secondList);
    printf("\n");

    mergedResultList = sortedMerge(firstList, secondList);
    printf("Lista Mesclada e Ordenada (inicial): ");
    Display(mergedResultList);
    printf("\n");

    printf("Soma: %d\n", Soma(mergedResultList));
    printf("Quantidade de elementos: %d\n", conta(mergedResultList));
    printf("Maior elemento: %d\n", maior(mergedResultList));
    printf("Menor elemento: %d\n", menor(mergedResultList));
    printf("\n");
        
    struct Node *temp = search(&mergedResultList, 7); 
    if (temp != NULL) {
        printf("Elemento encontrado e movido para o início: %d\n", temp->data);
    } else {
        printf("Elemento não encontrado\n");
    }

    printf("Lista após busca (e possível reorganização): ");
    Display(mergedResultList);
    printf("\n");

    
    Insert(&mergedResultList, 0, 10);     
    Insert(&mergedResultList, 3, 1000);   
    InsertSorted(&mergedResultList, 5); 

    printf("Lista após inserções: ");
    Display(mergedResultList);
    printf("\n");

    
    mergeSort(&mergedResultList); 

    printf("Lista final ordenada: ");
    Display(mergedResultList);
    printf("\n");

    
    Reverse(&mergedResultList);

    printf("Lista invertida: ");
    Display(mergedResultList);
    printf("\n");
    return 0;
}