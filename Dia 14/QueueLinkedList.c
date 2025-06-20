#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    long long data;
    struct Node *next;
};

struct Node *front = NULL;
struct Node *rear = NULL;

bool isEmpty() {
    return front == NULL;
}

void enqueue(long long value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Erro: Memoria insuficiente! Fila 'cheia'.\n");
        return;
    }

    newNode->data = value;
    newNode->next = NULL;

    if (front == NULL) {
        front = newNode;
        rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    printf("%lld adicionado a fila.\n", value);
}

long long dequeue() {
    long long x = -1;
    struct Node *temp;

    if (isEmpty()) {
        printf("Fila Vazia! Nao ha elementos para remover.\n");
    } else {
        x = front->data;
        temp = front;
        front = front->next;

        if (front == NULL) {
            rear = NULL;
        }

        free(temp);
        printf("%lld removido da fila.\n", x);
    }
    return x;
}

void displayQueue() {
    if (isEmpty()) {
        printf("A fila esta vazia. Nada para exibir.\n");
        return;
    }

    printf("Elementos na fila: [ ");
    struct Node *current = front;
    while (current != NULL) {
        printf("%lld ", current->data);
        current = current->next;
    }
    printf("]\n");
}

int main() {
    int choice;
    long long value;

    printf("Bem-vindo ao Testador de Fila Encadeada!\n");

    do {
        printf("\n--- Menu da Fila Encadeada ---\n");
        printf("1. Adicionar elemento (Enqueue)\n");
        printf("2. Remover elemento (Dequeue)\n");
        printf("3. Exibir fila\n");
        printf("4. Verificar se a fila esta vazia\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Digite o valor para adicionar: ");
                scanf("%lld", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                displayQueue();
                break;
            case 4:
                if (isEmpty()) {
                    printf("A fila esta vazia.\n");
                } else {
                    printf("A fila NAO esta vazia.\n");
                }
                break;
            case 0:
                printf("Saindo do programa.\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    } while (choice != 0);

    while (!isEmpty()) {
        dequeue();
    }
    printf("Memoria da fila liberada antes de sair.\n");

    return 0;
}

// neste código a principal diferença para uma Circular Queue é o uso de nós.
// Aqui, a fila é construída a partir de nós (Node). Cada nó contém um valor (data) e um ponteiro (next) que aponta para o próximo nó na sequência. 
// A fila não tem um tamanho fixo definido por você; ela cresce e diminui dinamicamente conforme os nós são adicionados ou removidos.
// Os ponteiros front e rear apontam diretamente para o primeiro e o último nó, respectivamente.
// A principal vantagem de uma fila encadeada é que ela fornece uma maneira eficiente de inserir e remover elementos, sem a necessidade de percorrer a lista para encontrar a posição correta.
// Isso é especialmente útil em situações onde você precisa adicionar e remover elementos rapidamente, como em uma fila de espera, uma fila de comandos no terminal, ou uma fila de transações financeiras.
// A desvantagem é que a fila encadeada pode consumir mais memória do que uma fila circular, especialmente se a fila estiver cheia.
// Isso ocorre porque cada nó contém um ponteiro para o próximo nó, o que pode levar a uma maior quantidade de memória sendo usada.
// Em resumo, a principal diferença prática é que sua Fila Encadeada é muito mais flexível em termos de tamanho, enquanto a Fila Circular (baseada em array) é mais eficiente em termos de desempenho se o tamanho for fixo e conhecido.
// esta fila tbm não vai dizer que está cheia, porque ela cresce e diminui dinamicamente conforme os nós são adicionados ou removidos.




// adicionei long para conter valores mais altos e não só int 


