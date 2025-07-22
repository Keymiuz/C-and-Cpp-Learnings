## Comparações entre Espaço e Tempo

Estas anotações refletem a análise de complexidade de tempo e espaço, detalhando a hierarquia de crescimento e como diferentes funções e recorrências se encaixam nela.
### 1. Hierarquia de Crescimento e Nomenclatura

A eficiência de um algoritmo é classificada pela rapidez com que seu tempo de execução ou uso de memória cresce em relação ao tamanho da entrada (`n`). A imagem apresenta a seguinte ordem, da mais eficiente (melhor) para a menos eficiente (pior):

| Notação (Formal) | Nomenclatura |
| `$O(1)$` | Constante |
| `$O(\log n)$` | Logarítmica |
| `$O(\sqrt{n})$` | Raiz Quadrada |
| `$O(n)$` | Linear |
| `$O(n \log n)$` | Log-Linear |
| `$O(n^2)$` | Quadrática |
| `$O(n^3)$` | Cúbica |
| `$O(2^n), O(3^n), \dots$` | Exponencial |
| `$O(n^n)$` | Exponencial (superior) |

A regra fundamental é: **$1 < \log n < \sqrt{n} < n < n \log n < n^2 < n^3 < \dots < 2^n < 3^n < \dots < n^n$** (ordem cresecente de crescimento em tempo de execução do algoritmo).

### 2. Análise de Funções Polinomiais

Ao analisar a complexidade, focamos no **termo dominante** (o termo que cresce mais rápido) e ignoramos constantes multiplicativas e termos de ordem inferior.

* `f(n) = 4`
    * Isso pode ser escrito como `f(n) = 4n⁰`.
    * O termo dominante é `n⁰`, que é 1.
    * **Complexidade: $O(1)$ (Constante)**

* `f(n) = 2n + 1`
    * O termo dominante é `n` (ou `n¹`). O `+1` e o `*2` são ignorados.
    * **Complexidade: $O(n)$ (Linear)**

* `f(n) = 2n² + 2n + 1`
    * O termo dominante é `n²`. Os termos `2n` e `1` crescem muito mais lentamente.
    * **Complexidade: $O(n^2)$ (Quadrática)**

* `f(n) = 2n³ + 3n² + 2n + 1`
    * O termo dominante é `n³`.
    * **Complexidade: $O(n^3)$ (Cúbica)**

### 3. Análise de Relações de Recorrência

Estas fórmulas descrevem o custo de algoritmos recursivos.

* `T(n) = T(n-1) + 1`
    * **Descrição:** Um algoritmo que faz uma quantidade constante de trabalho (`+1`) e chama a si mesmo para um problema de tamanho `n-1`.
    * **Análise:** Isso gera uma "pilha" de `n` chamadas.
    * **Complexidade: $O(n)$ (Linear)**

* `T(n) = 2T(n-1) + 1`
    * **Descrição:** Um algoritmo que se ramifica em duas chamadas (`2T`) para um problema de tamanho `n-1`.
    * **Análise:** O número de chamadas cresce exponencialmente (1, 2, 4, 8, ...).
    * **Complexidade: $O(2^n)$ (Exponencial)**

* `T(n) = 2T(n/2) + n`
    * **Descrição:** Um algoritmo de "dividir para conquistar". Divide o problema em duas metades (`2T(n/2)`) e gasta tempo linear (`+n`) para combinar os resultados.
    * **Análise:** Resolvido pelo Teorema Mestre (Caso 2).
    * **Complexidade: $O(n \log n)$ (Log-Linear)**


## Principais Notações Assintóticas

### 1. Big O - $O(f(n))$ (Upper Bound)
* **O que representa:** O **limite superior** (upper bound) ou o **pior caso** (worst-case). Descreve a taxa de crescimento máxima de um algoritmo.
* **Significado:** A função não crescerá mais rápido que $f(n)$.
* **Analogia:** "Esta viagem de carro levará **no máximo** 5 horas." (Pode levar menos, mas não mais).
* **Exemplo:** Um algoritmo de busca linear em um array é $O(n)$ porque, no pior caso, ele terá que percorrer o array inteiro.

### 2. Big Omega - $\Omega(f(n))$ (Lower ou Avarege Bound)
* **O que representa:** O **limite inferior** (lower bound) ou o **melhor caso** (best-case). Descreve a taxa de crescimento mínima de um algoritmo.
* **Significado:** A função não crescerá mais lentamente que $f(n)$.
* **Analogia:** "Vou receber **no mínimo** R$ 1.000 de bônus." (Pode ser mais, mas não menos).
* **Exemplo:** O mesmo algoritmo de busca linear é $\Omega(1)$ porque, no melhor caso, o elemento procurado é o primeiro, e a busca termina instantaneamente.

### 3. Big Theta - $\Theta(f(n))$ (Tight ou Lower Bound)
* **O que representa:** O **limite exato** (tight bound) ou o **caso médio** (average-case). Descreve a taxa de crescimento precisa de um algoritmo.
* **Significado:** A função cresce na mesma taxa que $f(n)$. Para que uma função seja $\Theta(f(n))$, ela precisa ser tanto $O(f(n))$ quanto $\Omega(f(n))$.
* **Analogia:** "Vou trabalhar por **exatamente** 8 horas hoje." (Nem mais, nem menos).
* **Exemplo:** O algoritmo Merge Sort é sempre $\Theta(n \log n)$, pois seu melhor, médio e pior caso têm a mesma complexidade log-linear.

## Comentários adicionais:
Pela marioria das representações achadas online e nesse curso, foi apenas usado Big O, quase nunca é representado Big Omega ou Big Theta. Também achei outros tipos de anotações que não foram explicadas no curso, mas como são muito pouco usadas, decidi não incluir nesse arquivo.

Outro comentário importante é que n^3 algumas vezes apresentava um valor menor que 2^n, isso porque o 2^n é exponencial e o n^3 é polinomial, fazendo com que algumas vezes em valores baixos, n^3 fosse menor que 2^n, mas isso não significa que n^3 é menor que 2^n, pois se subirmos os valores, teremos um resultado exponecialmente maior em 2^n, sempre ficar atento que a regra fundamental é **$1 < \log n < \sqrt{n} < n < n \log n < n^2 < n^3 < \dots < 2^n < 3^n < \dots < n^n$**, mas isso não significa que todos os casos cairão nessa constante.

Como por exemplo, se o valor de n for 8, temos -> 1, 3, 8, 64, 512 e 256 (ordem 1, logn, n, n^2, n^3, 2^n,)

Mas agora se o valor for 10 -> 1, 3.2, 10, 100, 1000, 10000, 1024 (ordem 1, logn, n, n^2, n^3, 2^n,) -> aqui o valor de 2^n já supera n^2.

Crescendo apenas mais um valor -> 1, 3.3, 11, 121, 1331 e 2048 (ordem 1, logn, n, n^2, n^3, 2^n,) -> aqui superando o valor por muito


## Quando utilizar Lower ou Upper Bound?

Quando utilizar: quando você não acha a solução para o problema nas anotações clássicas, como por exemplo a função 2n∛n+5n+6 -> neste caso a anotação seria 2n∛n, porem como não temos a anotação 2n∛n na regra geral, usamos ou a upper bound ou lower bound, que neste caso seria n^2 ou ThetaN, que são as anotações mais próxima da função 2n∛n.

A função completa é: $f(n) = 2n^{4/3} + 5n^1 + 6n^0$.

Passo a passo: 

**Identificar o termo dominante**
Comparamos os expoentes: $4/3 \approx 1.33$, $1$ e $0$.
O maior expoente é $4/3$. Portanto, o termo dominante é $2n^{4/3}$.

**Localizar na hierarquia**
Agora, nos perguntamos: onde $\Theta(n^{4/3})$ se encaixa na nossa regra geral?
Como $1 < 4/3 < 2$ (ou seja, $1 < 1.33 < 2$), podemos afirmar que:
$O(n) < O(n^{4/3}) < O(n^2)$


