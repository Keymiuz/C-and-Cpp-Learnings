#include <stdio.h>

int potencia(int m, int n)
{
    if (n == 0)
        return 1;
    return potencia(m, n - 1) * m;
};

int main()
{
    int r = potencia(3, 3);
    printf("%d ", r);
    return 0;
};