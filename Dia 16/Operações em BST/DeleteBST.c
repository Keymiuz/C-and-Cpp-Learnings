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
} //versão iterativa, um pouco mais complexa na minha opinião


struct Node *RInsert(struct Node *p, int key) {
    struct Node *t = NULL;
    if (p == NULL) {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = key;
        t->lchild = t->rchild = NULL;
        return t;
    }
    if (key < p->data) {
        p->lchild = RInsert(p->lchild, key);
    } else if (key > p->data) {
        p->rchild = RInsert(p->rchild, key);
    }
    return p;
} //versão recursiva, mais simples na minha opinião


void inOrder(struct Node *p) {
    if (p) {
        inOrder(p->lchild);
        printf("%d ", p->data);
        inOrder(p->rchild);
    }
}

int Height(struct Node *p) {
    int x;
    int y;
    if (p == NULL) {
        return 0;
    }
    x = Height(p->lchild);
    y = Height(p->rchild);
    return x > y ? x + 1 : y + 1;
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

struct Node *InPre(struct Node *p) {
    while (p && p->rchild != NULL) {
        p = p->rchild;
    }
    return p;
}

struct Node *InSucc(struct Node *p) {
    while (p && p->lchild != NULL) {
        p = p->lchild;
    }
    return p;
}

struct Node *Delete(struct Node *p, int key) {

    struct Node *q;
    if (p == NULL) {
        return NULL;
    }
    if(p->lchild == NULL && p->rchild == NULL){
        if(p == root){
            root = NULL;
        }
        free(p);
        return NULL;
    }
    if (key < p->data) {
        p->lchild = Delete(p->lchild, key);
    } else if (key > p->data) {
        p->rchild = Delete(p->rchild, key);
    } else {
        if (Height (p->lchild) > Height (p->rchild)) {
            q = InPre(p->lchild);
            p->data = q->data;
            p->lchild = Delete(p->lchild, q->data);
        } else {
            q = InSucc(p->rchild);
            p->data = q->data;
            p->rchild = Delete(p->rchild, q->data);
        }
    }
    return p;
}

int main() {
    root = RInsert(root, 10); // só o primeiro ponteiro precisa ser denifido na root diretamente (meio obvio mas bom anotar)
    RInsert(root, 5);
    RInsert(root, 20);
    RInsert(root, 3);
    RInsert(root, 7);
    RInsert(root, 15);
    RInsert(root, 25);
    inOrder(root);
    printf("\n");
    Delete(root, 20); // descobri que tenho que declarar as variáveis q vou usar pro delete (inPre, InSucc) ANTES! Se não o código não compila
    printf("\n");
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

