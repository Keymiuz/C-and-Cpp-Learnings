#include <stdio.h>

struct Rectangle {
    int length;
    int width;
};

int main() {
    struct Rectangle r;

    r.length = 15;
    r.width = 10;

    printf("Area of Rectangle is %d\n", r.length * r.width);

    return 0;
}