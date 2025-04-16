#include <stdio.h>

double e_taylor(double x, int n) {
    static double s;

    if (n==0)
        return s;
    s=1+x*s/n;
    return e_taylor(x, n-1);
};

int main(){

    printf("%lf \n", e_taylor(1, 10));
    return 0;
};


// este código se utiliza de uma variável estática s que não corresponde a
//  inicialização implícita de variáveis, eu gostei mais do código 1, achei ele "mais matemático" por assim dizer
// e também mais declarativo, por mais que ele seja menos iterativo 