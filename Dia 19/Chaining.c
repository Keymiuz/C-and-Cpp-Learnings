#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

void SortedInsert(struct Node **H, int x) {
    struct Node *t, *q = NULL, *p = *H;

    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    t->next = NULL;

    if (*H == NULL) {
        *H = t;
    } else {
        while (p && p->data < x) {
            q = p;
            p = p->next;
        }
        if (p == *H) {
            t->next = *H;
            *H = t;
        } else {
            t->next = q->next;
            q->next = t;
        }
    }
}

struct Node *Search(struct Node *p, int key) {
    while (p != NULL) {
        if (key == p->data) {
            return p;
        }
        p = p->next;
    }
    return NULL;
}

int Hash(int key) {
    return key % 10;
}

void Insert(struct Node *HT[], int key) {
    int index = Hash(key);
    SortedInsert(&HT[index], key);
}

int main() {
    struct Node *HT[10];
    int i;

    for (i = 0; i < 10; i++) {
        HT[i] = NULL;
    }
    Insert(HT, 12);
    Insert(HT, 32);
    Insert(HT, 22);
    Insert(HT, 42);
    Insert(HT, 5);
    Insert(HT, 15);
    Insert(HT, 25);
    Insert(HT, 35);
    Insert(HT, 45);
    Insert(HT, 55);
    Insert(HT, 27);
    Insert(HT, 37);
    Insert(HT, 1);
    Insert(HT, 11);
    Insert(HT, 10);
    Insert(HT, 20);





    printf("\nConteudo da Tabela Hash:\n");
    for (i = 0; i < 10; i++) {
        printf("HT[%d]: ", i);
        struct Node *current = HT[i];
        while (current) {
            printf("%d -> ", current->data);
            current = current->next;
        }
        printf("NULL\n");
    }

    return 0;
}