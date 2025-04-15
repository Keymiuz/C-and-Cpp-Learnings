#include <stdio.h>
void fun1(int n) {
    if (n > 0) {
      printf("%d ", n);
      fun1(n - 1);
    }
  };
  
  void main() {
    int x = 3;
    fun1(x);
  };


  // neste exemplo eu tenho uma funnção (func1) que se chama sempre
  //e tem como se fosse um bloco de while true 
  


  /// se eu inverto o bloco "fun1(n - 1);"  o print tbm é invertido, bem engraçado
  // ver como as operações mudam dependendo do método da recursão (ascendente e descentende)
  // call method e returning method



  ///Eu to com preguiça de digitar todos os tipos de recursão, mas tem tail, head, tree, indirect e nested
  /// talvez eu dê mais atenção para a tree e nested :)
  


  // tail recursion = use loop, é melhor no geral (NO GERAL, NEM SEMPRE!!!)