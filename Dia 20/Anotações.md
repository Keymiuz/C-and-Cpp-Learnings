## É um pouco difícil fazer anotações sobre Grafos, mas vou tentar sumarizar para mim mesmo do futuro:


 **Pegando o exemplo da BSF:**

 A primeira fila é bem fácil de entender, então eu vou usar o exemplo da segunda fila, que começa no índice 4

 Imagine que este código não está falando de grafos e vértices. Em vez disso, ele está organizando uma festa de bairro.
 Pessoas: São os números de 1 a 7.
 Amizades: Quem é amigo de quem.
 O Objetivo: começar convidando uma pessoa e a partir dela, espalhar o convite para todos os amigos, até que todos saibam da festa.
 
 o primeiro convidado é a Pessoa 4 - Fila: [4]. Terminal: [4].Convida-se seus amigos não visitados: 1, 3, 5. Terminal: 4, 1, 3, 5, . Fila: [1, 3, 5].
 Vez do 1. Convida seu amigo não visitado: 2. Terminal: 4, 1, 3, 5, 2, . Fila: [3, 5, 2].
 Vez do 3. Seus amigos já foram convidados.
 Vez do 5. Convida seus amigos não visitados: 6, 7. Terminal: 4, 1, 3, 5, 2, 6, 7, . Fila: [2, 6, 7].
 O resto (2, 6, 7) não tem ninguém novo para convidar, o looping se encerra e o terminal imprime 4, 1, 3, 5, 2, 6, 7.

