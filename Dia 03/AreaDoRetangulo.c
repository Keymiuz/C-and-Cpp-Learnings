#include <stdio.h>

int main() {
    int length = 0, breath = 0; // Boa prática inicializar variáveis

    printf("Enter Lenght and Breadth:");
    scanf("%d %d", &length, &breath);

    int area = length * breath;
    int peri = 2 * (length + breath);

    printf("Area=%d\nPerimeter=%d\n", area, peri);
    return 0;
}