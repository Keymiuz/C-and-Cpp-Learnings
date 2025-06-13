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
int eOperando(char x)
{
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
    char *infixo = "a+b*c-d/e";
    empilhar('#'); 
    char *posfixo = InfixoParaPosfixo(infixo);
    printf("Expressão Infixa: %s\n", infixo);
    printf("Expressão Pós-fixa: %s\n", posfixo);
    free(posfixo); 

    return 0;
}