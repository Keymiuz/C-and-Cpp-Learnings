# Anotações sobre Algoritmos de Ordenação (Sorts)

Este documento contém anotações sobre os algoritmos de ordenação implementados em C.

## 1. Selection Sort
* **Paradigma:** Comparação e troca
* **Como Funciona:**
    * O Selection Sort divide o array em duas partes: uma sub-array ordenada e uma sub-array não ordenada
    * Em cada iteração, ele encontra o menor (ou maior) elemento na sub-array não ordenada
    * Em seguida, troca esse menor elemento com o primeiro elemento da sub-array não ordenada, movendo-o para a sub-array ordenada
    * Este processo se repete até que toda a lista esteja ordenada
* **Complexidade de Tempo (Pior Caso):** $O(n^2)$
    * Isso ocorre porque, para cada um dos $n$ elementos, o algoritmo precisa percorrer o restante do array para encontrar o menor elemento
* **Complexidade de Tempo (Melhor Caso):** $O(n^2)$
    * Mesmo que o array já esteja ordenado, o algoritmo ainda realizará todas as comparações
* **Complexidade de Espaço:** $O(1)$ (In-place)
    * Ele não requer espaço adicional significativo além do array de entrada
* **Estabilidade:** Não é estável por padrão. Elementos com valores iguais podem mudar de ordem relativa
* **Uso:** Simples de entender e implementar. É eficiente para listas pequenas ou quando a memória é uma preocupação, mas raramente é a melhor escolha para grandes conjuntos de dados

## 2. Bubble Sort
* **Paradigma:** Comparação e troca
* **Como Funciona:**
    * O Bubble Sort percorre repetidamente a lista, compara elementos adjacentes e os troca se estiverem na ordem errada
    * Os elementos maiores "borbulham" para o final da lista a cada passagem
    * Uma otimização comum (`flag`) verifica se nenhuma troca ocorreu em uma passagem; se for o caso, a lista está ordenada e o algoritmo pode parar mais cedo
* **Complexidade de Tempo (Pior Caso):** $O(n^2)$
    * Ocorre quando o array está em ordem decrescente (invertido) e cada elemento precisa "borbulhar" até sua posição correta
* **Complexidade de Tempo (Melhor Caso):** $O(n)$
    * Com a otimização da `flag`, se o array já estiver ordenado, o algoritmo fará apenas uma passagem
* **Complexidade de Espaço:** $O(1)$ (In-place)
    * Não requer espaço adicional significativo
* **Estabilidade:** É estável. A ordem relativa de elementos iguais é preservada
* **Uso:** Principalmente para fins educacionais ou para arrays muito pequenos. Não é prático para grandes conjuntos de dados devido ao seu desempenho $O(n^2)$ no pior e caso médio

## 3. Insertion Sort
* **Paradigma:** Inserção
* **Como Funciona:**
    * O Insertion Sort constrói o array final ordenado um item por vez
    * Ele itera sobre os elementos do array, pegando cada elemento e inserindo-o na sua posição correta na sub-array já ordenada à sua esquerda
    * É análogo a como você organizaria um baralho de cartas na sua mão
* **Complexidade de Tempo (Pior Caso):** $O(n^2)$
    * Ocorre quando o array está em ordem inversa, pois cada elemento precisa ser movido até o início da sub-array ordenada
* **Complexidade de Tempo (Melhor Caso):** $O(n)$
    * Ocorre quando o array já está ordenado, pois cada elemento é comparado apenas uma vez e não há deslocamentos significativos
* **Complexidade de Espaço:** $O(1)$ (In-place)
    * Não requer espaço adicional significativo
* **Estabilidade:** É estável. A ordem relativa de elementos iguais é preservada
* **Uso:** Eficiente para arrays pequenos ou arrays que já estão quase ordenados. Também é útil quando elementos são adicionados incrementalmente a uma lista já ordenada

## 4. Quick Sort
* **Paradigma:** Divisão e Conquista
* **Como Funciona:**
    * O Quick Sort escolhe um elemento como **pivô** de um array
    * Ele **particiona** o array em torno desse pivô, de modo que todos os elementos menores que o pivô fiquem à sua esquerda e todos os maiores fiquem à sua direita. O pivô está agora em sua posição final ordenada
    * Em seguida, ele **recursivamente** aplica o mesmo processo às sub-arrays à esquerda e à direita do pivô.
* **Complexidade de Tempo (Pior Caso):** $O(n^2)$
    * Ocorre quando a escolha do pivô é consistentemente ruim (ex: sempre o menor ou maior elemento), levando a sub-arrays muito desequilibradas.
* **Complexidade de Tempo (Melhor e Caso Médio):** $O(n \log n)$
    * Este é o desempenho mais comum e o que torna o Quick Sort um dos algoritmos de ordenação mais rápidos na prática para grandes conjuntos de dados.
* **Complexidade de Espaço:** $O(\log n)$ (Para a pilha de recursão no caso médio)
    * Pode ser $O(n)$ no pior caso de recursão
* **Estabilidade:** Não é estável por padrão
* **Uso:** É um dos algoritmos de ordenação mais rápidos e mais usados na prática para grandes conjuntos de dados. A escolha do pivô é crucial para seu desempenho.

## 5. Count Sort
* **Paradigma:** Contagem
* **Como Funciona:**
    * O Count Sort é um algoritmo de ordenação baseado na contagem de elementos
    * Ele cria um array auxiliar (chamado de array de contagem) para contar a frequência de cada elemento no array original
    * Em seguida, ele percorre o array de contagem e constrói o array ordenado, colocando os elementos na ordem correta
* **Complexidade de Tempo (Pior Caso):** $O(n + k)$
    * Ocorre quando o array está em ordem inversa, pois cada elemento precisa ser movido até o início da sub-array ordenada
* **Complexidade de Tempo (Melhor Caso):** $O(n + k)$
    * Ocorre quando o array já está ordenado, pois cada elemento é comparado apenas uma vez e não há deslocamentos significativos
* **Complexidade de Espaço:** $O(k)$
    * Ocorre quando o array está em ordem inversa, pois cada elemento precisa ser movido até o início da sub-array ordenada
* **Estabilidade:** Não é estável por padrão
* **Uso:** É um dos algoritmos de ordenação mais rápidos e mais usados na prática para grandes conjuntos de dados. A escolha do pivô é crucial para seu desempenho


Nestas anotações, n é o tamanho do array e k é o valor máximo do array, e se o sort tem K, indica que tiveram merge ou count sort de K arrays