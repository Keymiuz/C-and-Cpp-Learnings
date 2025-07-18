# Anotações sobre Hashing 

 Hashing é uma técnica de armazenamento de dados que utiliza uma função de hash para mapear chaves para posições em uma tabela de hash. 

 Na sua implementação, temos uma "velocidade" maior, pois você irá diretamente no indice que procura e verá se ele existe ou não. Mas qual seus drawbacks? 

 1. Você não pode ter chaves repetidas, pois isso irá resultar em colisões, que são situações em que duas chaves diferentes resultam na mesma posição na tabela de hash.
 2. Mesmo que você tenha um array de tamanho pequeno, o que conta é o valor do indice, como por exemplo, se você tem uma Max_Key 1000 seu hash terá que ter 1000 indices, ou seja, 1000 posições para computar cada valor.
 3. Como ele atua parecido com o Count Sort, muito espaço de memória é consumido e muito espaço é desperdiçado (por mais rápido que seja).

 Como diminuimos esse grande consumo de memória? Ainda irei ver no curso, mas pelo que vi, mapear os hash é uma solução.

 Outro comentário que o professor não explicou, mas quando ele mapeou os hash "diminuou" o tamanho do hash em si e alocou os valores maiores em suas novas posições, mas estou em dúvida se isso não geraria colisão também dos valores maiores com os menores (pelo que vi isso chama de colisão many to one).

 Pesquisando um pouco, para resolver esse problema nós usamos open hashing e closed hashing.

 Open Hashing: É a técnica onde cada posição da tabela de hash contém uma lista (ou outra estrutura de dados, como uma árvore) de todas as chaves que foram mapeadas para aquele índice.

 Closed Hashing: Aqui, todas as chaves são armazenadas diretamente na própria tabela de hash. Se ocorrer uma colisão, o algoritmo procura outra posição vazia na mesma tabela para armazenar a chave colidida (sim, ambos são bem parecidos, a diferença é que o open hashing usa uma lista e o closed hashing usa uma tabela de hash).


## Chaining

 Chaining é uma técnica de resolução de colisões que envolve a criação de uma lista encadeada para cada posição da tabela de hash. Cada posição da tabela de hash contém uma lista de chaves que colidiram com a mesma posição.

 Como nos utiliamos a tecnica? Usamos linked nodes para criar a lista encadeada e alocamos cada chave em sua posição correspondente na tabela de hash (ordenada já, por exemplo: se tivermos 35 e 55 (key values) no indíce 5, o 35 será o primeiro node e o 55 será o segundo node).

 Por que isso acelera a procura? Porque ao invés de percorrer toda a tabela de hash, ele irá diretamente no indice que procura e verá se ele existe ou não (você só precisa percorrer os nodes ordenados, o que é muito mais rápido que percorrer todo o hash, também acelerando a inserção e remoção).  

 Para facilitar a visualização, cheque o código feito sobre chaining.


### Anotações sobre Big O notation de Hashing: 

 A complexidade de tempo das operações de hash (busca, inserção, remoção) depende muito do fator de carga (λ) e da eficácia da função de hash.

 **Fator de Carga (λ):** É a relação entre o número total de chaves (n) e o número total de índices (tamanho da tabela m). Ou seja, λ=n/m. Um λ baixo significa menos colisões.

 **Complexidade no Pior Caso (para busca mal-sucedida):** O(λ).

 Para uma busca mal-sucedida (tentando encontrar uma chave que não está na tabela), no pior caso (quando todos os elementos estão na mesma lista por uma colisão em massa), você teria que percorrer todos os n elementos naquela única lista. No entanto, para o caso médio, é O(1+λ) ou simplesmente O(λ) se λ for grande.

 **Complexidade no Melhor Caso (para busca bem-sucedida):** O(1).

 Para uma busca bem-sucedida, o melhor cenário é quando a chave está no primeiro nó da lista encadeada (ou no slot direto no endereçamento aberto). Isso leva tempo constante, O(1).

 **Complexidade média para uma busca bem-sucedida em hashing aberto (chaining), assumindo uma distribuição uniforme:** O(1+λ/2). No cenário ideal de "melhor caso", onde você encontra o item imediatamente no primeiro slot, é O(1).


#### Linear probing

 Linear probing é uma  bem simples de se entender. O que ela resolve? Ela resolve colisões que envolve a busca por uma posição vazia na tabela de hash em sequência linear. Cada posição da tabela de hash contém uma chave, e se uma colisão ocorrer, o algoritmo procura a próxima posição vazia na tabela. (Em suma, armazena os key_values na proxima posição aberta possível).

 A "lista de procura" é ciclica, digamos que você comece uma busca no indice 5 e vá até o 10, se todos os valores estiverem ocupados, ele volta para o 0 e continua a busca por um valor vazio. Para realizar a busca, você vai até o index correspondente ao valor e verifica se ele existe ou não, se não for encontrado, você vai para o próximo index e verifica se ele existe ou não, e assim por diante (até você achar um valor nulo, então ele para a busca, ou seja: Empty space = Pare a busca, se não, percorra a lista (é um tipo de linear search)).


 **Complexidade no Pior Caso (para busca mal-sucedida)**: O(n).

 **Complexidade Média (com distribuição uniforme e λ razoável):**
 Para busca bem-sucedida: O(1/(1−λ))
 Para busca mal-sucedida ou inserção: O(1/(1−λ)²)
 

##### Quadratic probing

 Quadratic probing é uma técnica de resolução de colisões que envolve a busca por uma posição vazia na tabela de hash em sequência quadrática. 
 as operações são dadas por uma função matemática onde: index(key,i) = (h(key)+i²)

 Vamos pegar com exemplo o array {26, 30, 45, 23, 25, 43, 74, 19, 29, 27}, 26 é inserido no 6 índice, 30 no índice 0, 45 no índice 5, 23 no índice 3, e agora encontramos a primeira colisão que é 25, então aplicamos a fórmula: index(25) = (5 + 1²) = 6, mas como HT[6] está ocupado, aplicamos a fórmula novamente: index(25) = (5 + 2²) = 9, então HT[9] = 25 (não ocupado até então), e assim vamos repetindo o processo para todas as inserções.



###### Double Hashing
 Double Hashing é uma técnica de resolução de colisões em tabelas hash que utiliza duas funções de hash distintas para calcular as posições de sondagem. O objetivo é criar uma sequência de sondagem mais "aleatória" e menos propensa à aglomeração do que a sondagem linear ou quadrática. (é um pouco parecida com a quadratic probing, mas com uma segunda função de hash)

 Quando ocorre uma colisão, o algoritmo não apenas salta para a próxima posição linear ou quadrática, mas calcula um "passo" ou "salto" variável usando uma segunda função de hash.

 Sua fórmula matemática é dada por: index(key,i) = (h(key)+i*h2(key))

 Como exemplo (seguindo o código montado) vamos usar o array {5, 25, 15, 35, 95}, SIZE = 10 e PRIME = 7.

 Vamos começar com o 5, ele é inserido no índice 5
 Logo após nos temos que inserir o 25, mas aí já temos nossa primeira colisão, então aplicamos a fórmula: 

 PrimeHash(25) = 7 - (25 % 7) = 7 - 4 = 3
 Logo: Hash(25) = (5 + 1 * 3) % 10 = 8 (inserimos o 25 na 8 posição) - acompanhando a fórmula, nos têmos 5 + 1 + 1 * 3 = 8

 o 5 é do índice, o 1 é do i e o 3 é do PrimeHash(25)

 Logo após nos temos que inserir o 15, mas aí já temos uma colisão, então aplicamos a fórmula: 

 PrimeHash(15) = 7 - (15 % 7) = 7 - 1 = 6
 Logo: Hash(15) = (5 + 1 * 6) % 10 = 1 (inserimos o 15 na 1 posição) - acompanhando a fórmula, nos têmos 5 + 1 + 1 * 6 = 1

 o 5 é do índice, o 1 é do i e o 6 é do PrimeHash(15)

 Logo após nos temos que inserir o 35, mas aí já temos uma colisão, então aplicamos a fórmula: 

 PrimeHash(35) = 7 - (35 % 7) = 7 - 0 = 7
 Hash(35) = (5 + 1 * 7) % 10 = 2 (inserimos o 35 na 2 posição) - acompanhando a fórmula, nos têmos 5 + 1 + 1 * 7 = 2
 e assim por diante...

 Nosso único problema será na operação do índice 95, onde teremos 2 colisões, então teremos que fazer a fórmula 3x, uma com i = 1, outra com i = 2 e outra com i = 3
 PrimeHash(95) = 7 - (95 % 7) = 7 - 4 = 3
 Hash(95) = (5 + 1 * 3) % 10 = 8 (inserimos o 95 na 8 posição, mas ele já está ocupado pelo 25)
 Hash(95) = (5 + 2 * 3) % 10 = 1 (inserimos o 95 na 1 posição, mas ele já está ocupado pelo 15)
 Hash(95) = (5 + 3 * 3) % 10 = 4 (inserimos o 95 na 4 posição, que não está ocupada)
























