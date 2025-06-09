#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    int rowIndex;
    int colIndex;
    struct Node* next;
} Node;

Node* createNode(int value, int rowIndex, int colIndex) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Erro ao alocar memória!\n");
        exit(1);
    }
    newNode->value = value;
    newNode->rowIndex = rowIndex;
    newNode->colIndex = colIndex;
    newNode->next = NULL;
    return newNode;
}

void insert(Node** head, int value, int rowIndex, int colIndex) {
    Node* newNode = createNode(value, rowIndex, colIndex);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void printMatrix(Node* head) {
    if (head == NULL) {
        printf("A matriz está vazia.\n");
        return;
    }
    printf("Indice da Linha | Indice da Coluna | Valor\n");
    printf("------------------------------------------\n");
    Node* temp = head;
    while (temp != NULL) {
        printf("      %d         |        %d         |   %d\n", temp->rowIndex, temp->colIndex, temp->value);
        temp = temp->next;
    }
}


void freeMatrix(Node** head) {
    Node* current = *head;
    Node* nextNode = NULL;
    while (current != NULL) {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }
    *head = NULL;
}


int main() {
    Node* head = NULL;
    insert(&head, 5, 0, 2);
    insert(&head, 8, 1, 0);
    insert(&head, 3, 1, 3);
    insert(&head, 9, 2, 1);
    insert(&head, 2, 3, 3);
    printMatrix(head);
    freeMatrix(&head);
    printf("\nMemória da matriz liberada com sucesso.\n");
    return 0;
}




// visualização em forma de Matriz 