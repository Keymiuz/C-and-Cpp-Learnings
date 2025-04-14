#include <iostream>
using namespace std;

int * fun(int size) {
    int *p;
    p = new int[size];
    for(int i=0; i<size; i++)
        p[i] = i + 1;
    return p;
}

int main() {
    int *ptr, tamanho = 6;
    ptr = fun(tamanho);
    for(int i=0; i<tamanho; i++)
        cout << ptr[i] << endl;
    return 0;

// o código acima é um exemplo de como alocar memória dinamicamente em C++ usando ponteiros, eu usei o new, mas poderia usar o malloc também, prt = ponteiro e fun é a função que retorna o ponteiro, e o tamanho é o tamanho do vetor que eu quero alocar, e depois eu uso o delete para liberar a memória, mas não vou usar agora pq não tem necessidade, só vou usar quando for fazer um código mais complexo, por enquanto só estou testando mesmo