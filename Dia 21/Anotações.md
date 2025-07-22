# Análise de Relações de Recorrência

Relações de recorrência são a linguagem matemática para descrever o custo de algoritmos recursivos. Elas nos permitem analisar a complexidade de tempo de um algoritmo com base em sua estrutura recursiva.


## Teorema para Funções de Subtração (Decreasing Functions)

Este tipo de recorrência tem a forma geral **`T(n) = aT(n-b) + f(n)`**, onde o tamanho do problema `n` é reduzido por uma constante `b` em cada chamada. O comportamento da solução depende crucialmente do valor de `a` (o fator de ramificação).

### Caso 1: `a = 1`
A função chama a si mesma apenas uma vez. A complexidade total é a soma do trabalho `f(n)` em cada um dos aproximadamente `n/b` passos da recursão.

* **Solução:** $T(n) \in O(n \cdot f(n))$
* **Exemplo:** `T(n) = T(n-1) + 1`. Aqui, `a=1, b=1, f(n)=1`. A solução é $O(n \cdot 1) = O(n)$.
* **Exemplo 2:** `T(n) = T(n-2) + n`. Aqui, `a=1, b=2, f(n)=n`. A solução é $O(n \cdot n) = O(n^2)$.

### Caso 2: `a > 1`
A função se ramifica em múltiplas chamadas. Isso leva a um crescimento exponencial, onde o número de operações é dominado pelo número de folhas na árvore de recursão.

* **Solução:** $T(n) \in O(a^{n/b})$
* **Exemplo:** `T(n) = 2T(n-1) + 1`. Aqui, `a=2, b=1`. A solução é $O(2^{n/1}) = O(2^n)$.



##  Teorema para Funções de Divisão (Division Functions) - O Teorema Mestre

Este é o teorema mais famoso para análise de algoritmos de "dividir para conquistar". Ele se aplica a recorrências da forma **`T(n) = aT(n/b) + f(n)`**, onde `a ≥ 1` e `b > 1`.

O Teorema Mestre compara a função `f(n)` com o termo $n^{\log_b a}$. Este valor crítico, $c_{crit} = \log_b a$, representa o ponto de equilíbrio entre o custo de dividir/combinar os problemas e o custo de resolver os subproblemas na base da recursão.

Existem três casos:

### Caso 1: O custo está nas folhas
Se $f(n) = O(n^c)$ onde $c < \log_b a$, então o trabalho nos nós folha da árvore de recursão domina.
* **Solução:** $T(n) = \Theta(n^{\log_b a})$
* **Exemplo:** `T(n) = 8T(n/2) + n^2`.
    * $a=8, b=2, f(n)=n^2$.
    * Como $f(n) = O(n^2)$ e $2 < 3$, estamos no Caso 1.
    * Solução: $T(n) = \Theta(n^3)$.

### Caso 2: O custo é distribuído igualmente
Se $f(n) = \Theta(n^c \log^k n)$ onde $c = \log_b a$ e $k \ge 0$, então o trabalho é distribuído de forma relativamente uniforme em todos os níveis da árvore.
* **Solução:** $T(n) = \Theta(n^{\log_b a} \log^{k+1} n)$
* **Exemplo (Merge Sort):** `T(n) = 2T(n/2) + n`.
    * $a=2, b=2, f(n)=n$.
    * Aqui, $f(n) = \Theta(n^1 \log^0 n)$, então $c=1, k=0$. Estamos no Caso 2.
    * Solução: $T(n) = \Theta(n^1 \log^{0+1} n) = \Theta(n \log n)$.

### Caso 3: O custo está na raiz
Se $f(n) = \Omega(n^c)$ onde $c > \log_b a$, e se `a·f(n/b) ≤ k·f(n)` para alguma constante `k < 1` (condição de regularidade), então o trabalho no nó raiz domina.
* **Solução:** $T(n) = \Theta(f(n))$
* **Exemplo:** `T(n) = 3T(n/4) + n^2`.
    * $a=3, b=4, f(n)=n^2$.
    * Como $f(n) = \Omega(n^2)$ e $2 > 0.79$, estamos no Caso 3.
    * Solução: $T(n) = \Theta(n^2)$.


##  Teorema para Funções com Raízes (Root Functions)

Recorrências com raízes, como **`T(n) = aT(√[b]{n}) + f(n)`**, são resolvidas com a técnica da **mudança de variável**.

O processo é o seguinte:

1.  **Faça a substituição:** Seja $n = 2^m$, o que implica que $m = \log_2 n$.
2.  **Transforme a recorrência:** Substitua `n` por `2^m` na equação. O termo recursivo se torna $T(\sqrt[b]{n}) = T((2^m)^{1/b}) = T(2^{m/b})$.
3.  **Defina uma nova função:** Crie uma nova função `S(m) = T(2^m)`.
4.  **Reescreva e resolva:** A recorrência se torna $S(m) = aS(m/b) + f(2^m)$. Agora, esta é uma recorrência de divisão em termos de `m` e pode ser resolvida com o Teorema Mestre.
5.  **Converta de volta:** Após encontrar a solução para `S(m)`, substitua `m` por `log n` para obter a solução final para `T(n)`.

* **Exemplo:** $T(n) = 2T(\sqrt{n}) + \log n$
    1.  Seja $n = 2^m$, então $m = \log_2 n$.
    2.  A recorrência se torna $T(2^m) = 2T(\sqrt{2^m}) + \log(2^m) = 2T(2^{m/2}) + m$.
    3.  Defina $S(m) = T(2^m)$. A equação vira: $S(m) = 2S(m/2) + m$.
    4.  Esta é a recorrência do Merge Sort. Pelo Teorema Mestre (Caso 2), sabemos que $S(m) = \Theta(m \log m)$.
    