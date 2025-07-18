#include <stdio.h>
#include <stdlib.h> 
#include <string.h> 

#define SIZE 10

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

// Função de sondagem quadrática
int QuadraticProbe(int H[], int key) {
    int idx = Hash(key);
    int i = 0;
    while (H[(idx + i * i) % SIZE] != 0) {
        i++;
    }
    return (idx + i * i) % SIZE;
}

void Insert(int H[], int key) {
    int idx = Hash(key);

    if (H[idx] != 0) {
        idx = QuadraticProbe(H, key);
    }
    H[idx] = key;
}


int Search(int H[], int key) {
    int idx = Hash(key);
    int i = 0;
    // Adiciona uma condição para limitar as iterações e evitar loops infinitos
    // No pior caso, precisaria verificar todos os SIZE slots
    while (i < SIZE) { // Limita o número de sondagens ao tamanho da tabela
        int current_idx = (idx + i * i) % SIZE;
        if (H[current_idx] == key) {
            return current_idx; // Chave encontrada
        }
        if (H[current_idx] == 0) {
            return -1; // Slot vazio encontrado, chave não está na tabela
        }
        i++;
    }
    return -1; // Se o loop terminar sem encontrar a chave 
}

int main() {
    int A[] = {26, 30, 45, 23, 25, 43, 74, 19, 29, 27};
    int n = sizeof(A) / sizeof(A[0]);
    Print(A, n, "A");
    int HT[SIZE] = {0}; // inicializando a tabela hash com zeros
    for (int i = 0; i < n; i++) {
        Insert(HT, A[i]);
    }
    Print(HT, SIZE, "HT");
    int index = Search(HT, 25);
    printf("Key achada em: %d\n", index);
    index = Search(HT, 12);
    printf("Key achada em: %d\n", index);
    return 0;
}

// Esse código utiliza a sondagem quadrática para resolver colisões na tabela hash, a visuailização dele é igual a Linear probing, onde a ordem de inserção importa
// como por exemplo, a primeira inserção é do 26: HT [0, 0, 0, 0, 0, 0, **26**, 0, 0, 0]
// Segunda inserção: HT [**30**, 0, 0, 0, 0, 0, 26, 0, 0, 0]
// Terceira: HT [30, 0, 0, 0, 0, **45**, 26, 0, 0, 0]
// Quarta: HT [30, 0, 0, **23**, 0, 45, 26, 0, 0, 0]
// Quinta -  Aqui acontece o grando pulo e toda a lógica da função: Hash(25) = 25 % 10 = 5, mas HT[5] está já preenchido, logo - Inicia a sondagem quadrática 
// (i=1): (5 + 1*1) % 10 = 6. - Porém HT[6] está preenchido, logo (i=2): (5 + 2*2) % 10 = 9. - HT[9] está livre, logo HT[9] = 25.
// E assim adiante, até a hash table ser preenchida, é uma operação mais complexa (em termos matemáticos) do que linear probing, mas é mais eficiente em termos 
// de tempo de execução e espaço de memória.

