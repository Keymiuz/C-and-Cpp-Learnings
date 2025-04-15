#include <iostream>
using namespace std;

class Arithmetic {
private:
    int a;
    int b;
public:
    Arithmetic(int a, int b) {
        this->a = a;
        this->b = b;
    }
    int add() {
        int c;
        c = a + b;
        return c;
    }
    int sub() {
        int c;
        c = a - b;
        return c;
    }
};

int main() {
   
}
