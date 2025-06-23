#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *lchild;
    struct Node *rchild;
}*root = NULL; // não sei se da pra criar um novo node e atribuir ele o valor nulo com ponteiros, então fiz igual a aula        


void insert(int key) {
    struct Node *p, *r = NULL;
    struct Node *t = root;
    if (root == NULL) {
        p = (struct Node *)malloc(sizeof(struct Node));
        p->data = key;
        p->lchild = p->rchild = NULL;
        root = p;
        return;
    }
    while (t != NULL) {
        r = t;
        if (key < t->data) {
            t = t->lchild;
        } else if (key > t->data) {
            t = t->rchild;
        } else {
            return;
        }
    }
    p = (struct Node *)malloc(sizeof(struct Node));
    p->data = key;
    p->lchild = p->rchild = NULL;
    if (key < r->data) {
        r->lchild = p;
    } else {
        r->rchild = p;
    }
}


void inOrder(struct Node *p) {
    if (p) {
        inOrder(p->lchild);
        printf("%d ", p->data);
        inOrder(p->rchild);
    }
}

struct Node* Search(int key) {
    struct Node *t = root;
    while (t != NULL) {
        if (key == t->data) {
            return t;
        } else if (key < t->data) {
            t = t->lchild;
        } else {
            t = t->rchild;
        }
    }
    return NULL;
}


int main() {
    insert(10);
    insert(5);
    insert(20);
    insert(3);
    insert(7);
    insert(15);
    insert(25);
    inOrder(root);
    printf("\n");
    struct Node* t = Search(48);
    if (t) {
        printf("%d ", t->data);
    } else {
        printf("Não Encontrado\n");
    }
    return 0;
}

