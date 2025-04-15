#include <stdio.h>
int potencia_otimizada(int base, int expoente) {
    int resultado = 1;
    while (expoente > 0) {
        if (expoente % 2 == 1) {
            resultado *= base;
        }
        base *= base;
        expoente /= 2;
    }
    return resultado;
}


// essa é uma versão com Iteração com Exponenciação por Quadratura, 
// Muito eficiente em termos de número de multiplicações: Realiza da ordem de log 2(n) multiplicações,
// onde n é o expoente. Isso é significativamente mais eficiente do que a abordagem recursiva simples

//Eficiente em termos de uso de memória: Utiliza uma quantidade constante de memória, sem risco de estouro de pilha.