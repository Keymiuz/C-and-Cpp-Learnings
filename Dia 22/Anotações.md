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
