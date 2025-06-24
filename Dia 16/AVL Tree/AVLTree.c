#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    int height;
    struct Node *lchild;
    struct Node *rchild;
}*root = NULL;

int NodeHeight(struct Node *p) {
    int hl;
    int hr;
    hl = p->lchild ? p->lchild->height : 0;
    hr = p->rchild ? p->rchild->height : 0;
    return hl > hr ? hl + 1 : hr + 1;
}

int BalanceFactor(struct Node *p) {
    int hl = p->lchild ? p->lchild->height : 0;
    int hr = p->rchild ? p->rchild->height : 0;
    return hl - hr;
}

struct Node *LLRotation(struct Node *p) {
    struct Node *pl = p->lchild;
    struct Node *plr = pl->rchild;

    pl->rchild = p;
    p->lchild = plr;

    p->height = NodeHeight(p);
    pl->height = NodeHeight(pl);

    if (root == p) {
        root = pl;
    }
    printf("Rotação LL operada no nó %d\n", p->data); // Print da rotação clássico
    return pl;
}

struct Node *RRRotation(struct Node *p) {
    struct Node *pr = p->rchild;
    struct Node *prl = pr->lchild;

    pr->lchild = p;
    p->rchild = prl;

    p->height = NodeHeight(p);
    pr->height = NodeHeight(pr);

    if (root == p) {
        root = pr;
    }
    printf("Rotação RR operada no nó %d\n", p->data); 
    return pr;
}

struct Node *LRRotation(struct Node *p) {
    struct Node *pl = p->lchild;
    struct Node *plr = pl->rchild;

    pl->rchild = plr->lchild;
    p->lchild = plr->rchild;

    plr->lchild = pl;
    plr->rchild = p;

    p->height = NodeHeight(p);
    pl->height = NodeHeight(pl);
    plr->height = NodeHeight(plr);

    if (root == p) {
        root = plr;
    }
    printf("Rotação LR operada no nó %d\n", p->data); 
    return plr;
}

struct Node *RLRotation(struct Node *p) {
    struct Node *pr = p->rchild;
    struct Node *prl = pr->lchild;

    p->rchild = prl->lchild;
    pr->lchild = prl->rchild;

    prl->lchild = p;
    prl->rchild = pr;

    p->height = NodeHeight(p);
    pr->height = NodeHeight(pr);
    prl->height = NodeHeight(prl);

    if (root == p) {
        root = prl;
    }
    printf("Rotação RL operada no nó %d\n", p->data); 
    return prl;
}

struct Node *RInsert(struct Node *p, int key) {
    struct Node *t = NULL;
    if (p == NULL) {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = key;
        t->height = 1;
        t->lchild = t->rchild = NULL;
        return t;
    }
    if (key < p->data) {
        p->lchild = RInsert(p->lchild, key);
    } else if (key > p->data) {
        p->rchild = RInsert(p->rchild, key);
    } else {
        return p;
    }

    p->height = NodeHeight(p);

    if (BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == 1) {
        return LLRotation(p);
    } else if (BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == -1) {
        return LRRotation(p);
    } else if (BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == -1) {
        return RRRotation(p);
    } else if (BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == 1) {
        return RLRotation(p);
    }
    return p;
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

struct Node* Delete(struct Node *p, int key) {
    if (p == NULL) {
        return NULL;
    }

    if (p->lchild == NULL && p->rchild == NULL) {
        if (p == root) {
            root = NULL;
        }
        printf("Nó %d removido (folha):\n", p->data);
        free(p);
        return NULL;
    }

    if (key < p->data) {
        p->lchild = Delete(p->lchild, key);
    } else if (key > p->data) {
        p->rchild = Delete(p->rchild, key);
    } else {
        printf("Nó %d encontrado para remoção:\n", p->data);
        struct Node* q;
        if (NodeHeight(p->lchild) > NodeHeight(p->rchild)) {
            q = InPre(p->lchild);
            p->data = q->data;
            p->lchild = Delete(p->lchild, q->data);
        } else {
            q = InSucc(p->rchild);
            p->data = q->data;
            p->rchild = Delete(p->rchild, q->data);
        }
    }

    p->height = NodeHeight(p);

    if (BalanceFactor(p) == 2 && BalanceFactor(p->lchild) >= 0) {
        if (BalanceFactor(p->lchild) == -1) {
            return LRRotation(p);
        }
        return LLRotation(p);
    } else if (BalanceFactor(p) == -2 && BalanceFactor(p->rchild) <= 0) {
        if (BalanceFactor(p->rchild) == 1) {
            return RLRotation(p);
        }
        return RRRotation(p);
    }

    return p;
}

// Função para imprimir a árvore de forma hierárquica
void printTree(struct Node *node, int level) {
    if (node != NULL) {
        printTree(node->rchild, level + 1);
        for (int i = 0; i < level; i++) {
            printf("   "); // Identação
        }
        printf("%d (H:%d, BF:%d)\n", node->data, node->height, BalanceFactor(node));
        printTree(node->lchild, level + 1);
    }
}

int main() {
    printf(" Teste de inserção:\n\n");
    root = RInsert(root, 30);
    root = RInsert(root, 20);
    root = RInsert(root, 10);
    root = RInsert(root, 25);
    root = RInsert(root, 5);
    root = RInsert(root, 28);
    root = RInsert(root, 35);
    root = RInsert(root, 40);
    root = RInsert(root, 32);

    printf("\n Árvore AVL após inserções:\n");
    printTree(root, 0);
    printf("\n");

    printf(" Teste de delete:\n\n");

    root = Delete(root, 5); 
    root = Delete(root, 30); 

    printf("\n Árvore AVL final:\n");
    printTree(root, 0);
    printf("\n");

    return 0;
}


// este foi mais um dos casos de um código que rodando pelo VS Code ele não imprime os valores, até tentei gerar uma versão com o Claude 4 mas nada adiantou
// então eu voltei pra estaca 0 e compilei/executei pelo cmd e deu certo. Não sei o que pode estar causando isso.