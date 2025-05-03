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
    // Corrigido para evitar shadowing de 'tipo'
    MatrizTriangular(int tamanho, TipoMatriz tipoParam) : n(tamanho), tipo(tipoParam) {
        size_t tamanhoVetor = (n * (n + 1)) / 2;  // Usei std::size_t para evitar conversão de sinal
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
            arq << "\n";
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

    // Salvar em arquivo binário
    void salvarEmBinario(const string& nomeArquivo) const {
        ofstream arq(nomeArquivo, ios::binary);
        size_t tamanhoVetor = valores.size();
        arq.write(reinterpret_cast<const char*>(&tamanhoVetor), sizeof(tamanhoVetor));
        arq.write(reinterpret_cast<const char*>(valores.data()), tamanhoVetor * sizeof(T));
        arq.close();
    }

    // Carregar de arquivo binário
    void carregarDeBinario(const string& nomeArquivo) {
        ifstream arq(nomeArquivo, ios::binary);
        size_t tamanhoVetor;
        arq.read(reinterpret_cast<char*>(&tamanhoVetor), sizeof(tamanhoVetor));
        valores.resize(tamanhoVetor);
        arq.read(reinterpret_cast<char*>(valores.data()), tamanhoVetor * sizeof(T));
        arq.close();
    }
};

int main() {
    int tamanho;
    cout << "Informe a dimensão da matriz: ";
    cin >> tamanho;

    MatrizTriangular<double> m1(tamanho, TipoMatriz::TRIANGULAR_INFERIOR);
    MatrizTriangular<double> m2(tamanho, TipoMatriz::TRIANGULAR_INFERIOR);

    cout << "Digite os elementos da primeira matriz:\n";
    for (int i = 1; i <= tamanho; ++i) {
        for (int j = 1; j <= tamanho; ++j) {
            double valor;
            cin >> valor;
            m1.definir(i, j, valor);
        }
    }

    cout << "Digite os elementos da segunda matriz:\n";
    for (int i = 1; i <= tamanho; ++i) {
        for (int j = 1; j <= tamanho; ++j) {
            double valor;
            cin >> valor;
            m2.definir(i, j, valor);
        }
    }

    cout << "\nResultado da soma:\n";
    MatrizTriangular<double> soma = m1 + m2;
    soma.exibir();
    soma.exportarParaArquivo("soma_matrizes.txt");
    soma.salvarEmBinario("soma_matrizes.bin");

    // Carregar de arquivo binário
    MatrizTriangular<double> m3(tamanho, TipoMatriz::TRIANGULAR_INFERIOR);
    m3.carregarDeBinario("soma_matrizes.bin");
    cout << "\nMatriz carregada do arquivo binário:\n";
    m3.exibir();

    return 0;
}
