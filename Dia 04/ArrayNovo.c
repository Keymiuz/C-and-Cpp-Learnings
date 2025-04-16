#include <stdio.h>
#include <stdlib.h>

struct Array
{
    int *A;
    int size;
    int length;
};

void Display(struct Array arr)
{
    int i;
    printf("\nElements are\n");
    for (i = 0; i < arr.length; i++)
        printf("%d ", arr.A[i]);
    printf("\n");
}

int main()
{
    struct Array arr;
    int n, i;

    printf("Fala ai o tamanho do bicho\n");
    scanf("%d", &arr.size);
    arr.A = (int *)malloc(arr.size * sizeof(int)); // alocação na memoria heap, parte crucial do código com ponteiro
    arr.length = 0;

    printf("Fala o número de elementos do array\n");
    scanf("%d", &n);  // Lê o número de elementos desejado pelo usuário e o armazena em n 

    if (n > arr.size) {  // verifica se o número de elementos que o usuário quer inserir (n) é maior do que o tamanho total alocado para o array
        printf("Erro: O número de elementos excede o tamanho alocado.\n"); // verificção de erro
        free(arr.A);
        return 1;
    }

    printf("Fala todos os elementos do array\n");
    for (i = 0; i < n; i++) 
        scanf("%d", &arr.A[i]);

    arr.length = n;

    Display(arr); // chama o display para imprimir tudo 

    free(arr.A);  // coloquei liberação de memória, que o Indiano não usou kkkk
    return 0;
}



// este foi um dos códigos q eu mais quebrei a cabeça, então voltarei para estudar mais ele, mas um Array abstrato 
// onde você não define na iniciação o tamanho dele é mto interessante de se manipular em C