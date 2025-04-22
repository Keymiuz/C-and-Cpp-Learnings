#include <iostream> 
#include <cstdlib>  
using namespace std; 
class Array { 
private:
    int* A;   
    int size;    
    int length; 

public: 
    Array(int arrSize, int arrLength, bool sorted = false) {

        size = arrSize;      
        length = arrLength;  

        A = new int[size]; 

        if (sorted) { 
            cout << "Digite os inteiros de forma ordenada" << endl;
            for (int i = 0; i < length; i++) {
                cout << "Digite o elemento " << i << " : " << flush; // 'flush' força a saída para o console
                cin >> A[i];
            }
        } else { 
            for (int i = 0; i < length; i++) {

                int val;
                val = rand() % 100; // Gera um número inteiro aleatório entre 0 e 99 

                // Gera um número binário aleatório (0 ou 1) e torna o valor negativo se for 1
                if (rand() % 2) {
                    A[i] = -1 * val; 
                } else {
                    A[i] = val;   
                }
            }
        }
    }
    int Get(int index) const {
        if (index >= 0 && index < length) {
            return A[index];
        }
        return -1; 
    }

    // Método para definir o valor de um elemento em um determinado índice.
    void Set(int index, int x) {
        if (index >= 0 && index < length) {
            A[index] = x;
        }
    }

   
    void display() const {
        for (int i = 0; i < length; i++) {
            cout << A[i] << " "; 
        }
        cout << endl; 
    }

    Array Merge(const Array& B) const {
        Array C(length + B.length, length + B.length); 
        int i = 0; 
        int j = 0; 
        int k = 0; 

        // Enquanto houver elementos em ambos os arrays 'A' e 'B' (vou acabar copiando e implementando alguma lógica por traz)
        while (i < length && j < B.length) {
            if (A[i] < B.Get(j)) {
                C.Set(k++, A[i++]); 
            } else { 
                C.Set(k++, B.Get(j++)); 
            }
        }

        // Se ainda houver elementos restantes no array 'A', copia-os para 'C'
        for (; i < length; i++) {
            C.Set(k++, A[i]);
        }

        // Se ainda houver elementos restantes no array B, copia-os para C
        for (; j < B.length; j++) {
            C.Set(k++, B.Get(j));
        }

        return C; 
    }

   
    ~Array() {
        delete[] A; 
    }
};

int main() { 

    cout << "Criando o Array X..." << endl;
    Array X(10, 5, true); 
    cout << "Array X criado." << endl;

    cout << "Criando o Array Y..." << endl;
    Array Y(10, 4, true); 
    cout << "Array Y criado." << endl;

    cout << "Fazendo o merge dos Arrays X e Y..." << endl;
    Array Z = X.Merge(Y);
    cout << "Arrays unidos. Array resultante Z:" << endl;
    Z.display(); 

    cout << "Programa finalizado." << endl;
    return 0; 
}