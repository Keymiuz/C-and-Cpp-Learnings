#include <iostream>
using namespace std;

class Diagonal {
private:
    int *A;
    int n;

public:
    Diagonal() {
        n = 2;
        A = new int[2];
    }

    Diagonal(int tamanho) {
        this->n = tamanho;
        A = new int[tamanho];
    }
    
    ~Diagonal() {
        delete[] A;
    }

    void definir(int i, int j, int valor);
    int obter(int i, int j);
    void exibir();
    int obterDimensao() { return n; }
};

void Diagonal::definir(int i, int j, int valor) {
    if (i == j)
        A[i - 1] = valor;
}

int Diagonal::obter(int i, int j) {
    if (i == j)
        return A[i - 1];
    return 0;
}

void Diagonal::exibir() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j)
                cout << A[i - 1] << " ";
            else
                cout << "0 ";
        }
        cout << endl;
    }
}

int main() {
    int dimensao;
    cout << "Informe a dimensão da matriz: ";
    cin >> dimensao;

    Diagonal matriz(dimensao);

    int valor;
    cout << "Digite os elementos da matriz (apenas diagonal):\n";
    for (int i = 1; i <= dimensao; i++) {
        for (int j = 1; j <= dimensao; j++) {
            cin >> valor;
            matriz.definir(i, j, valor);
        }
    }

    cout << "\nMatriz Diagonal:\n";
    matriz.exibir();

    return 0;
}
