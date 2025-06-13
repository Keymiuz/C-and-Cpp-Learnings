#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct No{
    char dado;
    struct No *proximo;
} *topo = NULL;

void empilhar(char x){
    struct No *t;
    t = (struct No*)malloc(sizeof(struct No));

    if (t == NULL)
        printf("Estouro de pilha! (Stack Overflow)\n");
    else{
        t->dado = x;
        t->proximo = topo;
        topo = t;
    }
}

char desempilhar(){
    struct No *t;
    char x = -1;

    if (topo == NULL)
        printf("Pilha está vazia! (Stack Underflow)\n");
    else{
        t = topo;
        topo = topo->proximo;
        x = t->dado;
        free(t);
    }
    return x;
}

int precedencia(char x){
    if (x == '+' || x == '-')
        return 1;
    else if (x == '*' || x == '/')
        return 2;
    return 0;
}


// Função para verificar se um caractere é um operando (letra ou número)
int eOperando(char x){
    if (x == '+' || x == '-' || x == '*' || x == '/')
        return 0;
    else
        return 1;
}

// Função para converter uma expressão Infixa para Pós-fixa
char* InfixoParaPosfixo(char* infixo){
    int i = 0, j = 0;
    char* posfixo;
    int len = strlen(infixo);
    posfixo = (char*)malloc((len + 2) * sizeof(char));

    while (infixo[i] != '\0'){
        if (eOperando(infixo[i])){
            posfixo[j++] = infixo[i++]; // adiciona diretamente no final (saída)
        }
        else {
            while (topo != NULL && precedencia(infixo[i]) <= precedencia(topo->dado)){
                posfixo[j++] = desempilhar();
            }
            empilhar(infixo[i++]); // empilha tudo
        }
    }

    // Desempilha todos os operadores restantes para a saída
    while (topo != NULL && topo->dado != '#'){
        posfixo[j++] = desempilhar();
    }
    posfixo[j] = '\0';
    return posfixo;
}

int main(){
    char *infixo1 = "a+b*2-c/d+2c";
    empilhar('#');
    char *posfixo1 = InfixoParaPosfixo(infixo1);
    printf("Expressão Infixa: %s\n", infixo1);
    printf("Expressão Pós-fixa: %s\n", posfixo1);
    free(posfixo1);

    // Reseta a stack para a proxima conversão (é necessário, tive que adicionar kkkk)
    while (topo != NULL) {
        desempilhar();
    }

    char *infixo2 = "a+b*2-c/d+2/22a-c";
    empilhar('#');
    char *posfixo2 = InfixoParaPosfixo(infixo2);
    printf("Expressão Infixa: %s\n", infixo2);
    printf("Expressão Pós-fixa: %s\n", posfixo2);
    free(posfixo2);
    return 0;
}



// depois de muitas alterações, aogra sim!