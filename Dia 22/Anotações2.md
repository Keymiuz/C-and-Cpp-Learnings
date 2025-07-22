## Divide and Conquer 

O que é? Basicamente é dividir um problema em "pequenas partes" e resolver essas pequenas partes, após isso "combinar" suas soluções para chegar na resolução do problema principal

O processo geralmente segue três etapas principais:

1.  **Dividir:** O problema principal é dividido em vários subproblemas menores e independentes. Esses subproblemas são versões menores do problema original.
2.  **Conquistar:** Os "subproblemas" são resolvidos recursivamente. Se um subproblema for pequeno o suficiente (caso base), ele é resolvido diretamente.
3.  **Combinar:** As soluções dos menores problemas são combinadas para criar a solução para o problema original.


exemplo de algoritmo que aplica essa técnica: Merge Sort.

* **Dividir:** O array a ser ordenado é dividido ao meio em dois subarrays.
* **Conquistar:** Cada subarray é ordenado recursivamente chamando o Merge Sort.
* **Combinar:** Os dois subarrays ordenados são mesclados  para produzir um único array ordenado. 


Quais as vantagens desse método? Eficiência, muitos algoritmos de dividir para conquistar são muito rápidos. Por exemplo, Merge Sort e Quick Sort têm uma complexidade de tempo média de $O(n \log n)$, que é significativamente mais rápida do que algoritmos mais simples como o Bubble Sort ($O(n^2)$).

### Análise de Complexidade (Teorema Mestre)

A complexidade de tempo de muitos algoritmos de dividir para conquistar pode ser analisada usando o **Teorema Mestre**. Ele fornece uma "receita" para encontrar a solução de relações de recorrência da forma:

$$T(n) = aT\left(\frac{n}{b}\right) + f(n)$$

Onde:
* $T(n)$ é o tempo de execução para um problema de tamanho $n$.
* $a$ é o número de subproblemas.
* $\frac{n}{b}$ é o tamanho de cada subproblema.
* $f(n)$ é o custo do trabalho feito para dividir o problema e combinar as soluções.


exemplo de algoritmo usando Divide and Conquer: 

------Binary Search---------

int pesquisaBinaria(int arr[], int tamanho, int alvo) {
    int baixo = 0;
    int alto = tamanho - 1;

    while (baixo <= alto) {
        // Calcula o índice do meio 
        int meio = baixo + (alto - baixo) / 2;

        // Comparações (vulgo lógica de "Dividir para Conquistar")
        if (arr[meio] == alvo) {
            return meio; 
        }

        // Se o alvo for maior, ele só pode estar na metade direita.
        if (arr[meio] < alvo) {
            baixo = meio + 1;
        } 
        // Se o alvo for menor, ele só pode estar na metade esquerda.
        else {
            alto = meio - 1;
        }
    }

    return -1;
}

// Função principal para demonstrar o uso
int main() {
    int array_ordenado[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int n = sizeof(array_ordenado) / sizeof(array_ordenado[0]); 
    
    int alvo1 = 23;
    int alvo2 = 100;

    // Teste com um alvo que existe no array
    int resultado1 = pesquisaBinaria(array_ordenado, n, alvo1);
    if (resultado1 != -1) {
        printf("Alvo %d encontrado no indice: %d\n", alvo1, resultado1);
    } else {
        printf("Alvo %d nao encontrado no array.\n", alvo1);
    }

    // Teste com um alvo que NÃO existe no array
    int resultado2 = pesquisaBinaria(array_ordenado, n, alvo2);
    if (resultado2 != -1) {
        printf("Alvo %d encontrado no indice: %d\n", alvo2, resultado2);
    } else {
        printf("Alvo %d nao encontrado no array.\n", alvo2);
    }

    return 0;
} 

O código acima é uma "espécie" de sudo code em C, ele não irá funcionar 100%, mas serve para ilustrar o conceito de Divide and Conquer e a sua lógica. A Lógica de Divisão (meio = baixo + (alto - baixo) / 2). A cada iteração, calculamos o índice do meio do espaço de busca atual, depois, comparamos o valor nesse índice, arr[meio], com o nosso alvo.

**Complexidade de tempo:** $O(log n)$

Por quê? A cada iteração do loop, o tamanho do problema (o espaço de busca no array) é dividido pela metade.

**Complexidade de espaço:** $O(1)$

Por quê? A versão iterativa do algoritmo usa apenas um número fixo de variáveis (baixo, alto, meio, tamanho, alvo) para fazer seu trabalho, independentemente do tamanho do array.
