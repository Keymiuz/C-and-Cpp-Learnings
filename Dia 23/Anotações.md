### Programação Dinâmica (Dynamic Programming)

### Para que é usado?

A **Programação Dinâmica** é uma técnica poderosa usada para resolver problemas de otimização de forma eficiente. Em vez de calcular repetidamente as mesmas soluções, a DP armazena os resultados de subproblemas para reutilizá-los, economizando um tempo computacional imenso (como por exemplo o problema de Fibonacci).

### Características principais:

Um problema pode ser resolvido com Programação Dinâmica se ele possui duas características principais:

1.  **Subestrutura Ótima:** A solução ótima para o problema principal pode ser construída a partir das soluções ótimas de seus subproblemas.
    * *Exemplo:* O caminho mais curto entre duas cidades (A e C) que passa por uma cidade B, é a soma do caminho mais curto de A até B e do caminho mais curto de B até C.

2.  **Subproblemas Sobrepostos:** O algoritmo resolve os mesmos subproblemas várias e várias vezes, em vez de gerar novos subproblemas a cada passo.
    * *Exemplo:* Para calcular `fib(5)`, calculamos `fib(4)` e `fib(3)`. Para calcular `fib(4)`, calculamos `fib(3)` e `fib(2)` (É valido anotar que `fib(3)` é calculado duas vezes. A DP guarda o resultado da primeira vez para não precisar recalculá-lo).

### Como funciona?

A Programação Dinâmica funciona basicamente "lembrando" dos resultados de problemas que já resolvemos. Existem duas abordagens principais para implementar uma solução com DP, ambas visando evitar o recálculo da recursão simples.

#### Abordagem 1: Memoization (Top-Down)

Esta técnica é uma otimização direta da recursão.

1.  **Comece com a solução recursiva:** Escreva uma função recursiva normal que resolve o problema.
2.  **Adicione um cache:** Crie uma estrutura de dados (geralmente um array ou um mapa hash) para armazenar os resultados dos subproblemas já resolvidos.
3.  **Implemente a lógica de cache:**
    * No início da função, verifique se o resultado para o subproblema atual já está no cache.
    * Se **sim**, retorne o valor do cache imediatamente.
    * Se **não**, calcule o resultado como faria normalmente, **armazene-o no cache** antes de retorná-lo.

Essa abordagem é chamada de **Top-Down** porque começa do problema original (o "topo") e vai quebrando-o em subproblemas menores.

#### Abordagem 2: Tabulation (Bottom-Up)

Esta técnica resolve o problema de forma iterativa, sem usar recursão.

1.  **Identifique os subproblemas:** Determine todos os subproblemas que precisam ser resolvidos.
2.  **Crie uma tabela:** Crie uma tabela (geralmente um array 1D ou 2D) para armazenar os resultados dos subproblemas.
3.  **Preencha a tabela:** Preencha a tabela de forma iterativa, começando pelos menores subproblemas (casos base). A solução para um problema maior é calculada com base nos valores já preenchidos na tabela para subproblemas menores.

Essa abordagem é chamada de **Bottom-Up** porque começa dos casos mais simples (a base) e vai construindo a solução até chegar no problema original. 

### Exemplos Clássicos nos Tópicos

#### Problema da Mochila 0/1 (0/1 Knapsack Problem)

* **Problema:** Diferente da versão fracionária (vista no método guloso), aqui você deve escolher se **leva ou não** um item inteiro (não é possível levar frações, como visto no exemplo anterior de Knapsack no dia 22).
* **Aplicação de DP:** A decisão de incluir um item `i` depende do valor máximo que pode ser obtido com os itens restantes e a capacidade restante da mochila.
* **Abordagens:** Os tópicos mostram a evolução clara: da recursão simples (ineficiente) para a otimização com memoization e tabulation.

#### Multiplicação de Cadeia de Matrizes (Matrix Chain Multiplication)

* **Problema:** Encontrar a maneira mais eficiente (com o menor número de multiplicações) de multiplicar uma sequência de matrizes. A ordem da multiplicação altera drasticamente o custo, mas não o resultado final.
* **Aplicação de DP:** O custo mínimo para multiplicar uma cadeia de `A1...An` é encontrado ao testar todas as divisões possíveis `(A1...Ak) * (Ak+1...An)` e escolher a que tem o menor custo, resolvendo recursivamente o custo de cada sub-cadeia (para visualização melhor, voltar no tópico 429 do curso).

#### Maior Subsequência Comum (Longest Common Subsequence - LCS)

* **Problema:** Dadas duas sequências (strings), encontrar o comprimento da subsequência mais longa que é comum a ambas. Uma subsequência não precisa ter elementos contíguos.
* **Aplicação de DP:** O comprimento da LCS de duas strings `X` e `Y` depende da LCS de seus prefixos (para visualização melhor, voltar no tópico 430 do curso).
    * Se os últimos caracteres de `X` e `Y` são iguais, a LCS é `1 + LCS(prefixo de X, prefixo de Y)`.
    * Se forem diferentes, é o `máximo(LCS(X, prefixo de Y), LCS(prefixo de X, Y))`.

#### Soma Máxima de Subarray (Max Subarray Sum)

* **Problema:** Encontrar o subarray contíguo dentro de um array que possui a maior soma.
* **Aplicação de DP:** Para cada posição `i` no array, a soma máxima do subarray que **termina** em `i` é ou o próprio elemento `array[i]`, ou `array[i] + (a soma máxima do subarray que termina em i-1)` (Sendo bem honesto eu não entendi muito esse exemplo (na sua totalidade), só como o exemplo funciona na sua praticalidade).
* **Algoritmo de Kadane:** Como visto no tópico 438 do curso, este é o nome dado a essa otimização de DP para o problema. Ele resolve o problema em tempo linear $O(n)$ e com espaço constante $O(1)$, mantendo apenas a "soma máxima atual" e a soma máxima global encontradas.


### Anotações extras sobre Knapsack Problem

Como "melhorar esse problema"? já entendemos a maneira "mais eficiente" de encontrar uma solução de forma recursiva, mas tem como ir mais além?

Sim, existe uma maneira de resolver esse problema com Programação Dinâmica, mas para isso, precisamos de uma **tabela** para armazenar os resultados dos subproblemas já resolvidos (o famoso cache). Vamos pegar já implementação dinâmica aplicada (conceito i) e "reservamos" as contas já feitas, mas como aplicar isso?

***Criamos uma função recursiva*** por exemplo knapsack(capacidade, pesos, valores, n), onde n é o número de itens que ainda estamos considerando e turbina ela com uma matriz 2D dp[n+1][W+1], para armazenar os resultados dos subproblemas. O método também pode ser resolvido com Tabulação (Bottom-Up DP), que resolve o problema de forma iterativa, sem usar recursão, exemplo a seguir:

* **Dimensões:** A tabela terá `(n + 1)` linhas e `(W + 1)` colunas, onde `n` é o número de itens e `W` é a capacidade máxima da mochila.
* **Significado:** Cada célula `dp[i][w]` terá um significado muito específico:
    > `dp[i][w]` = O **valor máximo** que pode ser obtido usando **apenas os primeiros `i` itens** com uma mochila de capacidade máxima **`w`**.

### Passo 1: A Lógica de Preenchimento da Tabela

Nós preencheremos a tabela célula por célula, da esquerda para a direita, de cima para baixo. Para cada célula `dp[i][w]`, estamos fazendo a seguinte pergunta:

"Considerando o item `i`, qual o valor máximo que consigo para uma capacidade `w`?"

Para responder, seguimos a mesma lógica da recursão. Lembre-se que o item `i` na tabela corresponde ao índice `i-1` nos nossos arrays `pesos` e `valores` (pois arrays começam em 0).

#### Caso A: O item `i` NÃO CABE na mochila
Se o peso do item atual (`pesos[i-1]`) é maior que a capacidade atual da mochila (`w`), **não podemos incluir o item `i`**.

* **Lógica:** O valor máximo que podemos obter é o mesmo que podíamos obter sem este item, ou seja, usando os `i-1` itens anteriores com a mesma capacidade `w`.
* **Fórmula:** `dp[i][w] = dp[i-1][w]`

#### Caso B: O item `i` CABE na mochila
Se `pesos[i-1] <= w`, agora temos uma escolha:

1.  **NÃO INCLUIR o item `i`**: Se não o incluirmos, o valor será o máximo obtido com os `i-1` itens anteriores e a mesma capacidade `w`.
    * `valor_sem_item = dp[i-1][w]`

2.  **INCLUIR o item `i`**: Se o incluirmos, seu valor é adicionado. O espaço restante na mochila (`w - pesos[i-1]`) deve ser preenchido otimamente com os `i-1` itens anteriores.
    * `valor_com_item = valores[i-1] + dp[i-1][w - pesos[i-1]]`

* **Lógica:** A solução ótima para `dp[i][w]` será o **máximo** entre essas duas escolhas.
* **Fórmula:** `dp[i][w] = max(valor_sem_item, valor_com_item)`

### Passo 2: Código em si

Aqui está o código que implementa essa lógica.

```c (aprendi isso agora kkkkkk)
#include <stdio.h>

// Função para encontrar o maior de dois inteiros
int max(int a, int b) {
    return (a > b) ? a : b;
}

int knapsackBottomUp(int W, int pesos[], int valores[], int n) {
    // Passo 1: Criar a tabela DP com (n+1) linhas e (W+1) colunas.
    int dp[n + 1][W + 1];

    // Passo 2: Preencher a tabela como descrito acima
    for (int i = 0; i <= n; i++) { // Itera sobre os itens
        for (int w = 0; w <= W; w++) { // Itera sobre as capacidades
            
            // Se i=0 ou w=0, estamos nos casos base (linha 0 ou coluna 0). O valor é 0.
            if (i == 0 || w == 0) {
                dp[i][w] = 0;
            } 
            // Caso 1: O item atual (i-1) n cabe na mochila de capacidade w.
            else if (pesos[i - 1] > w) {
                // Copiamos o valor da célula de cima (solução sem este item).
                dp[i][w] = dp[i - 1][w];
            } 
            // Caso 2: O item atual cabe na mochila. Temos que fazer uma escolha.
            else {
                // Escolha A: n incluir o item i. O valor vem da célula de cima.
                int valor_sem_item = dp[i - 1][w];
                
                // Escolha B: incluir o item i.
                int valor_com_item = valores[i - 1] + dp[i - 1][w - pesos[i - 1]];

                // A solução para dp[i][w] é o máximo entre as duas escolhas.
                dp[i][w] = max(valor_com_item, valor_sem_item);
            }
        }
    }
    return dp[n][W]; // Solução final
}

int main() {
    int valores[] = {60, 100, 120};
    int pesos[] = {10, 20, 30};
    int W = 50; // cap da mochila
    int n = sizeof(valores) / sizeof(valores[0]); 
    
    int valorMaximo = knapsackBottomUp(W, pesos, valores, n);
    
    printf("O valor maximo que pode ser carregado e: %d\n", valorMaximo); // Saída esperada: 220
    
    return 0;
}
```

### E como ficaria com a implementação de cache? 

***O código e praticamente o mesmo***, a única diferença é:

```c

// A função recursiva com a lógica de cache
int knapsackMemo(int W, int pesos[], int valores[], int n, int dp[][W + 1]) {
    // Passo 1: Casos Base
    if (n == 0 || W == 0) {
        return 0;
    }

    // Passo 2: verficar diretamente o cache, vulgo: se o resultado para este subproblema (n, W) já foi calculado, retorne-o.
    if (dp[n][W] != -1) {
        return dp[n][W];
    }

    // Passo 3: lógica recursiva (calcula só se o valor n está em cache)
    int resultado;
    
    if (pesos[n - 1] > W) {
        resultado = knapsackMemo(W, pesos, valores, n - 1, dp);
    } 
    else {
        // Escolha 1: Incluir o item n-1
        int valor_com_item = valores[n - 1] + knapsackMemo(W - pesos[n - 1], pesos, valores, n - 1, dp);

        // Escolha 2: Não incluir o item n-1
        int valor_sem_item = knapsackMemo(W, pesos, valores, n - 1, dp);
        resultado = max(valor_com_item, valor_sem_item);
    }

    // salvar no cache antes de retornar.
    dp[n][W] = resultado;
    return resultado;
}

int main() {
    int valores[] = {60, 100, 120};
    int pesos[] = {10, 20, 30};
    int W = 50;
    int n = sizeof(valores) / sizeof(valores[0]);

    
    // Criar a tabela DP
    int dp[n + 1][W + 1];

    // Inicializar toda a tabela com -1 para indicar que nenhuma célula foi calculada.
    memset(dp, -1, sizeof(dp));

    // Chamar a função recursiva principal
    int valorMaximo = knapsackMemo(W, pesos, valores, n, dp);

    printf("O valor maximo que pode ser carregado e: %d\n", valorMaximo);

    return 0;
}
```
A ***recursão simples*** explora uma árvore de chamadas gigante. A ***Memoization*** "poda" os ramos dessa árvore que já foram explorados. A eficiência vem de transformar chamadas recursivas repetidas em simples consultas a uma matriz.