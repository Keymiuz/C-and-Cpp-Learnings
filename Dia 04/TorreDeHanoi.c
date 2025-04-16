#include <stdio.h>
#include <math.h>

void TOH (int n, int a, int b, int c){

    if(n>0){
        TOH(n-1, a, b, c);
        printf("(%d,%d)\n",a,c);
        TOH(n-1,b,a,c);
    }
}


int main(){
    TOH(3,1,2,3);
    return 0;
}




//// este código mostra os movimentos que você deveria fazer no jogo Torre de Hanoi se você tivesse 3 aros e 3 torres


// os valores na TOH correspondem a 3(n) discos e 3 torres (a, b , c), podendo ser extendida a lógica