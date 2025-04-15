#include <iostream>
using namespace std;

template <class T>
class Arithmetic {
private:
    T a;
    T b;
public:
    Arithmetic(T a, T b);
    int add();
    int sub();
};

template <class T>
Arithmetic<T>::Arithmetic(T a, T b) {
    this->a = a;
    this->b = b;
}

template <class T>
int Arithmetic<T>::add() {
    int c = a + b;
    return c;
}

template <class T>
int Arithmetic<T>::sub() {
    int c = a - b;
    return c;
}

int main() {
    Arithmetic<int> intArith(10, 5);
    cout << "Adicao = " << intArith.add() << endl;
    cout << "Subtracao  = " << intArith.sub() << endl;

    Arithmetic<double> doubleArith(999.33, 16.46);
    cout << "Adicao  = " << doubleArith.add() << endl;
    cout << "Subtracao  = " << doubleArith.sub() << endl;

    return 0;
}

//aqui eu uso o Arithmetic<T>:: para chamar a class Arithmetic que foi definida lá
// em cima e já templaitarizada, os :: chamam a class e o <T> fazem 
//o tamplate T modular