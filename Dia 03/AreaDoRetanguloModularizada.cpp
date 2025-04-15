#include <iostream>
using namespace std;

int area(int length, int width) {
    return length * width;
}

int perimeter(int length, int width) {
    int p;
    p = 2 * (length + width);
    return p;
}

int main() {
    int length = 0, width = 0;
    printf("Fala as medidas ai bandido:");
    cin >> length >> width;

    int a = area(length, width);
    int peri = perimeter(length, width);

    printf("Area=%d\nPerimeter=%d\n", a, peri);
    return 0;
}


// mesmo código do anterior (area do retangulo), só que agora chamando as variáveis
//fora da main func para deixar o código mais modular e escalável