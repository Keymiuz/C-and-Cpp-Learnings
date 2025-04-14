#include <iostream>
#include <stdio.h>
using namespace std;

struct Rectangle
{
    int length;
    int breadth;
};


int main()
{
    int *p1;
    char *p2;
    float *p3;
    double *p4;
    struct Rectangle *p5;
    
    std::cout << sizeof(p1) << std::endl;
    std::cout << sizeof(p2) << std::endl;
    std::cout << sizeof(p3) << std::endl;
    std::cout << sizeof(p4) << std::endl;
    std::cout << sizeof(p5) << std::endl;
    
    
    return 0;
}

//// ou seja, todo ponteiro ocupa 8 bytes de memória, no meu compilador deu 4 bytes, 
// mas nos mais novos ocupam 8 segundo vários testes online, isso varia dependendo da arquitetura do sistema, o que indica que meu sistema
// está para uma arquitetura 32 bits, o que não faz muito sentido, mas era pra apresentar 8 (de um sistema 64bits)