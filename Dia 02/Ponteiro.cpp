#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int a=10;
    int *p;
    p=&a;
    
    std::cout << a << std::endl;
    printf("using pointer %d", *p);

    return 0;
}