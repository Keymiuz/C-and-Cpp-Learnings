nodes em C/C++ são criados fundamentalmente para construir estruturas de dados dinâmicas. Eles servem como blocos de construção que permitem organizar e conectar dados de maneira flexível, onde a quantidade de memória necessária não precisa ser conhecida em tempo de compilação.

Mas por que usar node? Criamos nós em C/C++ para ter a flexibilidade de construir estruturas de dados poderosas e eficientes que podem se adaptar dinamicamente às necessidades de armazenamento e manipulação de informações

Em que exemplo um node seria melhor? Normalmente visamos alocação de memória dinâmica
Exemplo: Você está processando uma lista de comandos de um usuário, e não sabe quantos comandos ele vai digitar.

Por que nós são melhores: Array/Matriz você precisaria predefinir um tamanho máximo. Se o usuário digitar mais comandos, você terá um estouro (overflow). Se digitar poucos, você desperdiçará memória. Redimensionar um array dinamicamente (como std::vector faz por baixo dos panos) pode ser custoso, pois envolve alocar um novo bloco de memória maior e copiar todos os elementos.

Lista Encadeada (Nós): Você pode simplesmente alocar um novo nó para cada comando que o usuário digita. A estrutura cresce organicamente, usando apenas a memória necessária.
