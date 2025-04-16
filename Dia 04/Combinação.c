#include <stdio.h>

int fact(int n){
    if (n==0) return 1;

    return fact(n-1)*n;
};



int nCr(int n, int r){
    int num, den;

    num=fact(n);
    den=fact(r)*fact(n-r);

    return num/den;
}





int main() {

    printf("%d \n", nCr(4,2));
    return 0;
}


// primeiro eu defini o que é um fatorial, depois apliquei a lógica do fatorial no nCr (combination formula)