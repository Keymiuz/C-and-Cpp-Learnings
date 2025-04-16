#include <stdio.h>
#include <math.h>
double e_taylor(double x, int n) {
    if (n == 0) {
        return 1.0; // Primeiro termo (x^0 / 0!)
    } else {
        double previous_term = e_taylor(x, n - 1);
        double current_term = pow(x, n) / tgamma(n + 1); // Usando tgamma para o fatorial 
        return previous_term + current_term;
    }
}

int main() {
    double x_value = 4.0;
    int num_terms = 15; // Número de termos para aproximar a série
    double result = e_taylor(x_value, num_terms);
    printf("%lf\n", result);
    return 0;
}

// este código é uma Taylor Serie você precisa calcular cada termo x^n/n! individualmente e somá-los
// neste código eu fiz uma abordagem recursiva para calcular os termos e somá0los aos anteriores 

 
​
 