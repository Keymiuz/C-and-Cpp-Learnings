#include <stdio.h>
#include <stdlib.h>

// Estrutura para um nó da árvore
typedef struct Node {
    struct Node* lchild;
    int data;
    struct Node* rchild;
} Node;

typedef struct Tree {
    Node* root;
} Tree;

typedef struct QueueNode {
    Node* data;
    struct QueueNode* next;
} QueueNode;

typedef struct Queue {
    QueueNode* front;
    QueueNode* rear;
} Queue;

Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}

void enqueue(Queue* q, Node* data) {
    QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
    newNode->data = data;
    newNode->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = newNode;
        return;
    }
    q->rear->next = newNode;
    q->rear = newNode;
}

Node* dequeue(Queue* q) {
    if (q->front == NULL) return NULL;
    QueueNode* temp = q->front;
    Node* data = temp->data;
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);
    return data;
}

int isQueueEmpty(Queue* q) {
    return q->front == NULL;
}


typedef struct StackNode {
    void* data; // Usando void* para ser genérico (armazenará Node* ou long int)
    struct StackNode* next;
} StackNode;

typedef struct Stack {
    StackNode* top;
} Stack;

Stack* createStack() {
    Stack* stk = (Stack*)malloc(sizeof(Stack));
    stk->top = NULL;
    return stk;
}

void push(Stack* stk, void* data) {
    StackNode* newNode = (StackNode*)malloc(sizeof(StackNode));
    newNode->data = data;
    newNode->next = stk->top;
    stk->top = newNode;
}

void* pop(Stack* stk) {
    if (stk->top == NULL) return NULL;
    StackNode* temp = stk->top;
    void* data = temp->data;
    stk->top = stk->top->next;
    free(temp);
    return data;
}

int isStackEmpty(Stack* stk) {
    return stk->top == NULL;
}


// Função auxiliar para criar um novo nó
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->lchild = NULL;
    newNode->rchild = NULL;
    return newNode;
}

// Inicializa a árvore (equivalente ao construtor)
void initTree(Tree* t) {
    t->root = NULL;
}

// Função recursiva auxiliar para liberar a memória da árvore
void _freeTreeRecursive(Node* p) {
    if (p) {
        _freeTreeRecursive(p->lchild);
        _freeTreeRecursive(p->rchild);
        free(p);
    }
}

// Libera toda a memória alocada pela árvore (equivalente ao destrutor)
void freeTree(Tree* t) {
    _freeTreeRecursive(t->root);
    t->root = NULL;
}

void CreateTree(Tree* bt) {
    Node* p;
    Node* t;
    int x;
    Queue* q = createQueue();

    printf("Enter root data: ");
    fflush(stdout);
    scanf("%d", &x);

    bt->root = createNode(x);
    enqueue(q, bt->root);

    while (!isQueueEmpty(q)) {
        p = dequeue(q);

        printf("Enter left child data of %d (-1 for no child): ", p->data);
        fflush(stdout);
        scanf("%d", &x);
        if (x != -1) {
            t = createNode(x);
            p->lchild = t;
            enqueue(q, t);
        }

        printf("Enter right child data of %d (-1 for no child): ", p->data);
        fflush(stdout);
        scanf("%d", &x);
        if (x != -1) {
            t = createNode(x);
            p->rchild = t;
            enqueue(q, t);
        }
    }
    free(q); // Liberar a memória da fila
}

// Funções de Travessia Recursiva
void _Preorder(Node* p) {
    if (p) {
        printf("%d, ", p->data);
        fflush(stdout);
        _Preorder(p->lchild);
        _Preorder(p->rchild);
    }
}
void Preorder(Tree* bt) { _Preorder(bt->root); }

void _Inorder(Node* p) {
    if (p) {
        _Inorder(p->lchild);
        printf("%d, ", p->data);
        fflush(stdout);
        _Inorder(p->rchild);
    }
}
void Inorder(Tree* bt) { _Inorder(bt->root); }

void _Postorder(Node* p) {
    if (p) {
        _Postorder(p->lchild);
        _Postorder(p->rchild);
        printf("%d, ", p->data);
        fflush(stdout);
    }
}
void Postorder(Tree* bt) { _Postorder(bt->root); }

void Levelorder(Tree* bt) {
    if (bt->root == NULL) return;

    Queue* q = createQueue();
    Node* p = bt->root;

    printf("%d, ", p->data);
    fflush(stdout);
    enqueue(q, p);

    while (!isQueueEmpty(q)) {
        p = dequeue(q);
        if (p->lchild) {
            printf("%d, ", p->lchild->data);
            fflush(stdout);
            enqueue(q, p->lchild);
        }
        if (p->rchild) {
            printf("%d, ", p->rchild->data);
            fflush(stdout);
            enqueue(q, p->rchild);
        }
    }
    free(q);
}

int _Height(Node* p) {
    if (p == NULL) {
        return 0;
    }
    int l = _Height(p->lchild);
    int r = _Height(p->rchild);
    return (l > r ? l : r) + 1;
}
int Height(Tree* bt) { return _Height(bt->root); }


// Funções de Travessia Iterativa
void iterativePreorder(Tree* bt) {
    Stack* stk = createStack();
    Node* p = bt->root;
    while (p != NULL || !isStackEmpty(stk)) {
        if (p != NULL) {
            printf("%d, ", p->data);
            fflush(stdout);
            push(stk, p);
            p = p->lchild;
        } else {
            p = (Node*)pop(stk);
            p = p->rchild;
        }
    }
    printf("\n");
    free(stk);
}

void iterativeInorder(Tree* bt) {
    Stack* stk = createStack();
    Node* p = bt->root;
    while (p != NULL || !isStackEmpty(stk)) {
        if (p != NULL) {
            push(stk, p);
            p = p->lchild;
        } else {
            p = (Node*)pop(stk);
            printf("%d, ", p->data);
            fflush(stdout);
            p = p->rchild;
        }
    }
    printf("\n");
    free(stk);
}

void iterativePostorder(Tree* bt) {
    Stack* stk = createStack();
    Node* p = bt->root;
    long int temp;
    while (p != NULL || !isStackEmpty(stk)) {
        if (p != NULL) {
            // Usa o casting para long int para empilhar o ponteiro
            push(stk, (void*)p);
            p = p->lchild;
        } else {
            temp = (long int)pop(stk);
            if (temp > 0) {
                push(stk, (void*)(-temp));
                p = ((Node*)temp)->rchild;
            } else {
                printf("%d, ", ((Node*)(-1 * temp))->data);
                fflush(stdout);
                p = NULL;
            }
        }
    }
    printf("\n");
    free(stk);
}


int main() {
    Tree bt;
    initTree(&bt);

    CreateTree(&bt);
    printf("\n");

    printf("Preorder: ");
    Preorder(&bt);
    printf("\n");

    printf("Inorder: ");
    Inorder(&bt);
    printf("\n");

    printf("Postorder: ");
    Postorder(&bt);
    printf("\n");

    printf("Levelorder: ");
    Levelorder(&bt);
    printf("\n");

    printf("Height: %d\n", Height(&bt));

    printf("Iterative Preorder: ");
    iterativePreorder(&bt);

    printf("Iterative Inorder: ");
    iterativeInorder(&bt);

    printf("Iterative Postorder: ");
    iterativePostorder(&bt);

    // Essencial: Liberar toda a memória alocada para os nós da árvore
    freeTree(&bt);

    return 0;
}

