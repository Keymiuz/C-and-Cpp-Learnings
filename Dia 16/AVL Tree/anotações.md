                                                       --Árvore AVL (Adelson-Velsky e Landis)--
Tipo de Árvore: É uma Árvore de Busca Binária (BST) auto balanceada. Isso significa que cada nó tem no máximo dois filhos (esquerda e direita).

Balanceamento: O balanceamento é mantido através do fator de balanceamento de cada nó. O fator de balanceamento é a diferença entre a altura da subárvore esquerda e a altura da subárvore direita. Em uma árvore AVL, o fator de balanceamento de qualquer nó deve ser −1, 0 ou 1.
Mecanismo de Balanceamento: Quando uma inserção ou remoção desequilibra a árvore (ou seja, o fator de balanceamento de um nó se torna maior que 1 ou menor que −1), a árvore realiza rotações. Existem quatro tipos principais de rotações: rotação simples à esquerda (LL), rotação simples à direita (RR), rotação dupla à esquerda-direita (LR) e rotação dupla à direita-esquerda (RL). Essas rotações rearranjam os nós para restaurar a propriedade de balanceamento.
Dados nos Nós: Cada nó armazena uma única chave (ou valor) e ponteiros para seus filhos esquerdo e direito, além da altura de sua subárvore ou seu fator de balanceamento.

Rigidez do Balanceamento: Árvores AVL são consideradas mais estritamente balanceadas do que outras árvores balanceadas (ainda não entedi exatamente o por que, mas acho que é por causa da altura que a árvore tem que ser balanceada) (ou pela quantidade de rotações) KKKKKKKKK


Definição na prática: Imagine que eu eu tenho uma biblioteca e quero organizar os livros nela. Eu decido organizar meus livros da seguinte forma: para cada prateleira que eu tenho, os livros à esquerda e à direita daquele ponto central na prateleira estejam sempre em número muito parecido. Se eu adiciona um livro e perceber que uma prateleira ficou muito mais cheia de um lado do que do outro, eu rearranjo (faz uma "rotação") alguns livros para equilibrar a prateleira. Eu movo alguns livros para cima ou para baixo, ou troco a posição de alguns para manter tudo simétrico.

Resultado: Não importa qual livro eu queira, eu sempre faço poucos "passos" para encontrá-lo, porque a altura das minhas pilhas de livros (as "subárvores") estão sempre controladas e balanceadas.


Segundo o chatGPT esse tipo de código não é para o mundo de banco de dados (apenas pra indexação), Por que? Porque No mundo real, imagine que cada vez que você compra um livro, você precisa rearranjar um monte de livros em várias prateleiras, gerando muito trabalho. Por isso que a árvore AVL não é usada para índices de banco de dados em disco: cada rearranjo (rotação) significaria mexer em muitas "prateleiras" (blocos de dados) no disco, o que é lento.

