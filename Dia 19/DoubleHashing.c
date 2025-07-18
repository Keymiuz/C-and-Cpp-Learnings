#include <stdio.h>
#include <stdlib.h> 

#define SIZE 10
#define PRIME 7 // Uma constante prima, menor que SIZE, usada na segunda função de hash

void Print(int vec[], int n, const char *s) {
    printf("%s: [", s);
    for (int i = 0; i < n; i++) {
        printf("%d", vec[i]);
        if (i < n - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

int Hash(int key) {
    return key % SIZE;
}

// Segunda função de hash (h2(key)) - Usada para calcular o salto"em caso de colisão
int PrimeHash(int key) {
    return PRIME - (key % PRIME);
}

// Função de sondagem de Double Hashing
int DoubleHash(int H[], int key) {
    int idx = Hash(key); // Índice inicial (h1(key))
    int h2_val = PrimeHash(key); // Valor do salto (h2(key))
    int i = 0; // Contador de tentativas de sondagem

    while (H[(idx + i * h2_val) % SIZE] != 0) {
        i++;
    }
    return (idx + i * h2_val) % SIZE;
}

void Insert(int H[], int key) {
    int idx = Hash(key); 

    if (H[idx] != 0) {
        idx = DoubleHash(H, key);
    }
    H[idx] = key; // Insere a chave no slot encontrado
}


int Search(int H[], int key) {
    int idx = Hash(key); // Índice inicial
    int h2_val = PrimeHash(key); // Valor do salto
    int i = 0; // Contador de tentativas

    // Loop para procurar a chave ou um slot vazio
    while (i < SIZE) { // Adicionado limite para o loop
        int current_idx = (idx + i * h2_val) % SIZE;

        if (H[current_idx] == key) {
            return current_idx; // Chave encontrada
        }
        if (H[current_idx] == 0) {
            return -1; // Slot vazio encontrado, chave não está na tabela
        }
        i++; // Incrementa o contador para a próxima sondagem
    }
    return -1; // Chave não encontrada após todas as sondagens possíveis
}

// Função principal
int main() {
    int A[] = {5, 25, 15, 35, 95};
    int n = sizeof(A) / sizeof(A[0]);
    Print(A, n, "A");

    int HT[SIZE] = {0}; 

    for (int i = 0; i < n; i++) {
        Insert(HT, A[i]);
    }
    Print(HT, SIZE, "HT");

    int index = Search(HT, 25);
    printf("Key achada em: %d\n", index);

    index = Search(HT, 35);
    printf("Key achada em: %d\n", index);

    return 0;
}

// Nesse código, como no Quadratic Probing, a forma de inserção é mto parecida, e dada por uma operação matemática:
// Hash(key) = (h1(x) + i * h2(x)) % 10

// Neste caso temos para a primeira operação de inserção: Hash(5) = 5 % 10 = 5
// Após a primeira inserção nos já temos uma colisão, então temos que usar a operação, onde, primeiro calculamos o PrimeHash e depois adicionamos ele ao índice inicial
// h2 = PrimeHash(25) = 7 - (25 % 7) = 7 - 4 = 3. (o 4 se da pelo restante da divisão, igual no Quadratic Probing)
// Logo: Hash(25) = (5 + 1 * 3) % 10 = 8. (então inserimos o 25 na 8 posição)

// A operação segue fácil até chegar na inserção do 95, que temos 2 colisões, tendo que fazer a operação 3x:
// PrimeHash(95) = 7 - (95 % 7) = 7 - 4 = 3
// Logo: Hash(95) = (5 + 1 * 3) % 10 = 8 (inserimos o 95 na 8 posição, mas ele já está ocupado pelo 25)
// Hash(95) = (5 + 2 * 3) % 10 = 1 (inserimos o 95 na 1 posição, mas ele já está ocupado pelo 15)
// Hash(95) = (5 + 3 * 3) % 10 = 4 (inserimos o 95 na 4 posição, que não está ocupada)
// Para continuar as operações, sempre incrementamos o i, mesmo procedimento pradrão, começando do 1 e indo de 1 em 1 até achar um lugar vázio.