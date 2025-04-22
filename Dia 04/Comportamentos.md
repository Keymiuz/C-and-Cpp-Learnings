Como arrays funcionam:


Eu fiz um documento BEM completo sobre Arrays que deixarei linkado no meu google Docs, já que foi um tópico bem comentado neste curso, mas deixarei aqui um .md comentando as principais coisas que eu achei importante documentar no no Github


1. Definição e Declaração de Arrays em C:

A sintaxe geral para declarar um array em C envolve especificar o tipo de dados que o array irá armazenar, o nome do array e o número de elementos que ele pode conter.

2. Acesso a Elementos Individuais do Array:

Os elementos de um array em C são acessados utilizando seus valores de índice. A indexação de arrays em C começa em 0, o que significa que o primeiro elemento de um array está na posição 0, o segundo na posição 1, e assim por diante. Para acessar um elemento específico, o nome do array é seguido pelo índice do elemento entre colchetes.

3. Alocação de Memória para Arrays em C:

A memória para arrays em C pode ser alocada de duas maneiras principais: estaticamente (na stack) ou dinamicamente (no heap).   

Alocação Estática (na Stack): Quando um array é declarado com um tamanho fixo dentro de uma função (ou globalmente), a memória para ele é alocada na stack (para variáveis locais) ou na seção de dados (para variáveis globais) em tempo de compilação. O tamanho dessa alocação é fixo e deve ser conhecido em tempo de compilação. A memória alocada na stack é gerenciada automaticamente pelo compilador; ela é alocada quando a função é chamada e desalocada quando a função retorna. Arrays estáticos são rápidos para alocar e acessar, mas seu tamanho não pode ser alterado durante a execução do programa. Além disso, o espaço da stack é limitado, o que pode ser uma preocupação para arrays muito grandes.   

Alocação Dinâmica (no Heap): A alocação dinâmica de memória para arrays ocorre durante a execução do programa, utilizando funções como malloc(), calloc() e realloc() da biblioteca <stdlib.h>. A memória é alocada no heap, uma região de memória maior e gerenciada manualmente pelo programador. A alocação dinâmica permite que o tamanho do array seja determinado em tempo de execução, oferecendo maior flexibilidade. No entanto, é responsabilidade do programador liberar a memória alocada dinamicamente usando a função free() quando ela não for mais necessária, para evitar vazamentos de memória.


4. Como o Compilador C Lida com a Declaração de Arrays:

Para arrays declarados com um tamanho constante  o compilador reserva um bloco contíguo de memória suficiente para armazenar o número especificado de elementos do tipo dado. O tamanho total da memória alocada para o array é calculado multiplicando o número de elementos pelo tamanho de cada elemento (em bytes). Por exemplo, um array de 10 inteiros (onde cada inteiro ocupa 4 bytes) exigirá 40 bytes de memória 

Para arrays declarados como variáveis o tamanho do array não é conhecido até o tempo de execução, ai meio que não importa a declaração, o compilador reserva um espaço na stack só quando a função é chamada, também com base no valor da variável



6. O Conceito de Heap na Alocação de Memória em C (Copiado da interwebs): 

O heap é uma região de memória disponível para o programa para alocação dinâmica em tempo de execução. Ao contrário da stack, a memória no heap não é gerenciada automaticamente; o programador deve alocar e desalocar explicitamente essa memória. O heap é menos organizado que a stack; a alocação envolve encontrar um bloco de memória livre do tamanho solicitado. Essa região de memória permite que os programas aloquem memória conforme necessário durante a execução, o que é essencial para estruturas de dados cujo tamanho não é conhecido em tempo de compilação ou que precisam mudar de tamanho.   

Arrays podem ser alocados dinamicamente no heap usando as funções malloc() e calloc(). A função malloc() aloca um bloco de memória do tamanho especificado (em bytes) e retorna um ponteiro para o início desse bloco. A memória alocada com malloc() não é inicializada e pode conter valores de "lixo". Já a função calloc() também aloca memória, mas recebe como argumentos o número de elementos e o tamanho de cada elemento. Além disso, calloc() inicializa todos os bytes do bloco de memória alocado com zero. Se a alocação de memória falhar (por exemplo, se não houver memória suficiente), ambas as funções retornam NULL, e é importante que o programador verifique esse valor para lidar com a falha adequadamente.   

A memória alocada dinamicamente no heap pode ser redimensionada usando a função realloc(). realloc() tenta redimensionar o bloco de memória apontado pelo ponteiro fornecido para um novo tamanho especificado. Se o novo tamanho for maior, realloc() pode precisar alocar um novo bloco de memória (possivelmente em um local diferente) e copiar o conteúdo do bloco antigo para o novo. É crucial notar que, assim como malloc() e calloc(), realloc() pode retornar NULL se a realocação falhar, e o ponteiro original não deve ser sobrescrito até que a realocação seja bem-sucedida.   

7. Ponteiros e Arrays:

Eu não cheguei a mexer ainda muito com ponteiros e arrays, a próxima matéria acho que vai entrar nos Arrays ADT(abstract), mas sei que você pode apontar para um elemento de um array por ponteiros, fazer calculos aritméticos, etc.

8. Anotações +:

Chegando na parte de Arrays ADT, eu vi que não tinha muito o que adicionar nesse doc, eu só trabalhei mais as operações e a lógica matemática por traz das operações. Mas foi um capítulo bem interessante do curso para entender a lógica matemática por trás de C, como por exemplo: Aprendi que o metodo "sort" não existe em C, até existe um qsort, mas você tem que declarar e implementar sua própria função de comparação para ordenar seus dados. Outra coisa que eu aprendi foi quando usar métodos já atribuidos diretamente na linguaguem, e quando é mais conveniente fazer "o seu próprio método" (com loops etc). 
//para arrays muito pequenos e/ou você precisa de um algoritmo de ordenação específico com propriedades particulares normalmente a gente cria nosso próprio metodo, de resto a gente usa métodos já implementados na linguaguem como o qsort (arrays grandes você nem perde seu tempo escrevendo um método).