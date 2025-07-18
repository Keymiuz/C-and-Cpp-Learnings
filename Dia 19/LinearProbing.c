#include <stdio.h>

#define SIZE 10

int hash(int key) {
    return key % SIZE;
}

int probe(int H[], int key) {
    int index = hash(key);
    int i = 0;
    while (H[(index + i) % SIZE] != 0) {
        i++;
    }
    return (index + i) % SIZE;
}

void Insert(int H[], int key) {
    int index = hash(key);

    if (H[index] != 0) {
        index = probe(H, key);
    }
    H[index] = key;
}

int Search(int H[], int key) {
    int index = hash(key);
    int i = 0;

    while (H[(index + i) % SIZE] != key) {
        i++;
    }

    return (index + i) % SIZE;
}

int main() {
    int HT[10] = {0};

    Insert(HT, 12);
    Insert(HT, 25);
    Insert(HT, 35);
    Insert(HT, 26);

    printf("\nKey achada em %d\n", Search(HT, 12));
    printf("Key achada em %d\n", Search(HT, 25));
    printf("Key achada em %d\n", Search(HT, 26));
    printf("Key achada em %d\n", Search(HT, 35));

    return 0;
}

// esse código é mais díficil da visualização, mas ele é mais eficiente em termos de tempo de execução e espaço de memória
// As keys nem sempre vão estar nos mesmo locais de definição, já que ele ocupa a procura com o próximo valor disponível
// Por exemplo, se tivermos 35 e 55 (key values) no indíce 5, o 35 será o primeiro valor inserido e o 55 será o segundo valor inserido.

// Nesse caso a ordem de inserção importa e muito, já que altera diretamente os valores exibidos no terminal (para dificultar um pouco a visualização mental rsrs)