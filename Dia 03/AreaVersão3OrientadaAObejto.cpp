#include <iostream>
#include <stdio.h> 
using namespace std;

class Rectangle {
public:      //uma class por default é private, então você tem que declarar q ela é public se não você não consegue acessar ela na main
    int length;
    int breadth;

    void initialise(int l, int b) {
        length = l;
        breadth = b;
    }

    int area() {
        return length * breadth;
    }

    int perimeter() {
        int p;
        p = 2 * (length + breadth);
        return p;
    }
};

int main() {
    Rectangle r;
    int l, b;
    printf("FALA AS MEDIDAAAAAAAAAAA:");
    cin >> l >> b;

    r.initialise(l, b);

    int a = r.area();
    int peri = r.perimeter();

    printf("Area=%d\nPerimeter=%d\n", a, peri);

    return 0;
}



///versão orientada a objeto, mais legal hihihi