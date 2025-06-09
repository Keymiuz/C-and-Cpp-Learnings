#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Estrutura para o nó da pilha
struct Node{
 int data;
 struct Node *next;
}*top=NULL;

void Push(int x){
 struct Node *t;
 t=(struct Node*)malloc(sizeof(struct Node));
 if(t==NULL)
 printf("stack is full\n");
 else{
 t->data=x;
 t->next=top;
 top=t;
 }
}

int Pop(){
 struct Node *t;
 int x=-1;
 if(top==NULL)
 printf("Stack is Empty\n");
 else{
 t=top;
 top=top->next;
 x=t->data;
 free(t);
 }
 return x;
}

void Display(){
 struct Node *p;
 p=top;
 while(p!=NULL){
 printf("%d ",p->data);
 p=p->next;
 }
 printf("\n");
}

int main(){
 Push(10);
 Push(20);
 Push(30);
 Display();
 printf("%d ",Pop());
 return 0;
}




// Stack com Linked List, seguindo sempre o princípio LIFO (Last-In, First-Out), ou seja, o último elemento a ser inserido é o primeiro a ser removido.
// A pilha está sendo implementada com uma lista encadeada, onde cada nó contém um valor e um ponteiro para o próximo nó.
// A pilha é inicializada com um ponteiro top apontando para NULL, indicando que a pilha está vazia.
// A função Push insere um novo elemento no topo da pilha, criando um novo nó e ajustando os ponteiros.
// A função Pop remove o elemento do topo da pilha, liberando a memória do nó removido e retornando seu valor.




// A principal vantagem de uma pilha é que ela fornece uma maneira eficiente de inserir e remover elementos, sem a necessidade de percorrer a lista para encontrar a posição correta.
// Isso é especialmente útil em situações onde você precisa adicionar e remover elementos rapidamente, como em uma pilha de arquivos abertos, uma pilha de comandos no terminal, ou uma pilha de transações financeiras.
