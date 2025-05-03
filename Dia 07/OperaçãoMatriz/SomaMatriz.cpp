#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

enum class TipoMatriz {
    TRIANGULAR_INFERIOR,
    TRIANGULAR_SUPERIOR
};

template <typename T>
class MatrizTriangular {
private:
    vector<T> valores;
    int n;
    TipoMatriz tipo;

    int calcularIndice(int i, int j) const {
        if (tipo == TipoMatriz::TRIANGULAR_INFERIOR && i >= j) {
            return (i * (i - 1)) / 2 + (j - 1);
        } else if (tipo == TipoMatriz::TRIANGULAR_SUPERIOR && i <= j) {
            return (j * (j - 1)) / 2 + (i - 1);
        }
        return -1;
    };

public:
    MatrizTriangular(int tamanho, TipoMatriz tipo) : n(tamanho), tipo(tipo) {
        int tamanhoVetor = (n * (n + 1)) / 2;
        valores.resize(tamanhoVetor, 0);
    };

    void definir(int i, int j, T valor) {
        if (i < 1 || i > n || j < 1 || j > n) return;
        int idx = calcularIndice(i, j);
        if (idx != -1) valores[idx] = valor;
    };

    T obter(int i, int j) const {
        if (i < 1 || i > n || j < 1 || j > n) return 0;
        int idx = calcularIndice(i, j);
        return (idx != -1) ? valores[idx] : 0;
    };

    void exibir() const {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                cout << obter(i, j) << " ";
            }
            cout << endl;
        }
    };

    void exportarParaArquivo(const string& nomeArquivo) const {
        ofstream arq(nomeArquivo);
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                arq << obter(i, j) << " ";
            }
            arq << endl;
        }
        arq.close();
    };

    // Soma entre duas matrizes triangulares do mesmo tipo e dimensão
    MatrizTriangular<T> operator+(const MatrizTriangular<T>& outra) const {
        if (n != outra.n || tipo != outra.tipo) {
            throw runtime_error("Erro: Dimensões ou tipos incompatíveis para soma.");
        }

        MatrizTriangular<T> resultado(n, tipo);
        for (size_t i = 0; i < valores.size(); ++i) {
            resultado.valores[i] = this->valores[i] + outra.valores[i];
        }

        return resultado;
    }
};

int main() {
    int tamanho;
    cout << "Informe a dimensão da matriz:" << endl;
    cout.flush();
    cin >> tamanho;

    MatrizTriangular<double> m1(tamanho, TipoMatriz::TRIANGULAR_INFERIOR);
    MatrizTriangular<double> m2(tamanho, TipoMatriz::TRIANGULAR_INFERIOR);

    cout << "Digite os elementos da primeira matriz:" << endl;
    cout.flush();
    for (int i = 1; i <= tamanho; ++i) {
        for (int j = 1; j <= tamanho; ++j) {
            double valor;
            cin >> valor;
            m1.definir(i, j, valor);
        }
    }

    cout << "Digite os elementos da segunda matriz:" << endl;
    cout.flush();
    for (int i = 1; i <= tamanho; ++i) {
        for (int j = 1; j <= tamanho; ++j) {
            double valor;
            cin >> valor;
            m2.definir(i, j, valor);
        }
    }

    cout << "\nResultado da soma:" << endl;
    MatrizTriangular<double> soma = m1 + m2;
    soma.exibir();

    
    soma.exportarParaArquivo("soma_matrizes.txt");

    return 0;
}


// Anotações: enum class TipoMatriz - indica se a matriz será inferior  ou superior
// calcularIndice(i, j) - Essa função converte a posição 2D (i, j) da matriz para um índice linear no vetor valores. Isso é necessário porque só os elementos da parte triangular são armazenados
// Se existem formular prontas pra cada tipo de matriz, eu só peguei e apliquei-las

// O construtor da matriz só calcula os elementos válidos n(n+1)/2 e os inicializa
// O resto é tudo igual das outras matrizes, eu só também adicionei uma função de exportação de arquivo para testar :)