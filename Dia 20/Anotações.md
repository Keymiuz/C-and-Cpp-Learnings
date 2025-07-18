## É um pouco difícil fazer anotações sobre Grafos, mas vou tentar sumarizar para mim mesmo do futuro:


 **Pegando o exemplo da BSF:**

 A primeira fila é bem fácil de entender, então eu vou usar o exemplo da segunda fila, que começa no índice 4:

 Imagine que este código não está falando de grafos e vértices. Em vez disso, ele está organizando uma festa de bairro
 Pessoas: São os números de 1 a 7
 Amizades: Quem é amigo de quem
 O Objetivo: começar convidando uma pessoa e a partir dela, espalhar o convite para todos os amigos, até que todos saibam da festa
 
 o primeiro convidado é a Pessoa 4 - Fila: [4]. Terminal: [4].Convida-se seus amigos não visitados: 1, 3, 5. Terminal: 4, 1, 3, 5, . Fila: [1, 3, 5]
 Vez do 1. Convida seu amigo não visitado: 2. Terminal: 4, 1, 3, 5, 2, . Fila: [3, 5, 2]
 Vez do 3. Seus amigos já foram convidados.
 Vez do 5. Convida seus amigos não visitados: 6, 7. Terminal: 4, 1, 3, 5, 2, 6, 7, . Fila: [2, 6, 7]
 O resto (2, 6, 7) não tem ninguém novo para convidar, o looping se encerra e o terminal imprime 4, 1, 3, 5, 2, 6, 7

 **Pegando o exemplo da DFS:**

 O DFS é como um explorador que ao chegar a um novo lugar (pessoa), não para de explorar uma trilha (amizade) até que ela chegue ao fim (não há mais amigos não convidados por ali). Só então ele volta para tentar outra trilha.

 Pegando o mesmo exemplo criado, começamos pela pessoa 4:

 A Pessoa 4 tem amigos: 2, 3, 5, 6. O DFS escolhe o primeiro amigo não convidado que encontra: 2. Terminal: [4, 2]
 A Pessoa 2 tem amigos: 1, 4. O DFS escolhe o primeiro amigo não convidado que encontra: 1. Terminal: [4, 2, 1]
 A Pessoa 1 tem amigos: 2, 3. O DFS escolhe o primeiro amigo não convidado que encontra: 3. Terminal: [4, 2, 1, 3]. O 2 já foi convidado, então ele não é mais considerado
 A Pessoa 3 tem amigos: 1, 4. O DFS escolhe o primeiro amigo não convidado que encontra: 4. Terminal: [4, 2, 1, 3, 4]. O 1 já foi convidado, então ele não é mais considerado. Não há mais para onde mergulhar a partir da Pessoa 3.
 Como a Pessoa 3 não tem mais amigos não convidados, o DFS "volta" para a pessoa que a convidou (a Pessoa 1)
 A Pessoa 1 já explorou o 3. Ela não tem mais amigos não convidados
 O DFS "volta" para a pessoa que a convidou (a Pessoa 2)
 A Pessoa 2 já explorou o 1. Ela não tem mais amigos não convidados
 O DFS "volta" para a pessoa que a convidou (a Pessoa 4)
 A Pessoa 4 já explorou o 2 (e através dele, o 1 e o 3)
 Agora, ela procura o próximo amigo não convidado: 5. Terminal: [4, 2, 1, 3, 4, 5]
 Não há mais para onde mergulhar a partir da Pessoa 5
 O DFS "volta" para a pessoa que a convidou (a Pessoa 4)
 A Pessoa 4 já explorou o 2 (e através dele, o 1 e o 3)
 Agora, ela procura o próximo amigo não convidado: 6. Terminal: [4, 2, 1, 3, 4, 5, 6]
 Não há mais para onde mergulhar a partir da Pessoa 6 e a lista acaba.





 



Para facilitar a visualização eu salvei algumas fotos e recomendo você VISUALIZAR isso acontecendo, a mesma coisa para Hashing techniques, já que é mais difícil de entender só visualizando o código.