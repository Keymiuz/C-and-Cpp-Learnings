#include <iostream>
using namespace std;

struct Rectangle {
    int length;
    int breadth;
};

Rectangle * fun() {
    Rectangle * p = new Rectangle;
    p->length = 15;
    p->breadth = 7;
    return p;
}

int main() {
    Rectangle * ptr = fun();
    int area = ptr->length * ptr->breadth; // Cálculo da área na main()
    cout << "Length " << ptr->length << endl;
    cout << "Breadth " << ptr->breadth << endl;
    cout << "Area " << area << endl;
    delete ptr;
    return 0;
}