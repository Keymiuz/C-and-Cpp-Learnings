#include <cstdio> // Biblioteca padrão de I/O do C (equivale a stdio.h)
#include <queue> 

using namespace std; 

void BFS(int vtx, int A[][8], int n) {
    queue<int> Q;      
    int visited[8] = {0};

    
    printf("%d, ", vtx); 
    visited[vtx] = 1;
    Q.push(vtx); // Método do C++ para adicionar na fila

    // Loop de exploração
    while (!Q.empty()) { // Método do C++ para verificar se está vazia
        int u = Q.front(); // ver o primeiro item
        Q.pop();          

        // Itera por todos os vizinhos de 'u'
        for (int v = 1; v < n; v++) {
            if (A[u][v] == 1 && visited[v] == 0) {
                printf("%d, ", v); 
                visited[v] = 1;
                Q.push(v);
            }
        }
    }
    printf("\n"); 
}

int main() {
    int A[8][8] = {
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 1, 1, 1, 0, 0, 0},
        {0, 1, 0, 1, 0, 0, 0, 0},
        {0, 1, 1, 0, 1, 1, 0, 0},
        {0, 1, 0, 1, 0, 1, 0, 0},
        {0, 0, 0, 1, 1, 0, 1, 1},
        {0, 0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 1, 0, 0}
    };

    printf("Vertex: 1 -> ");
    BFS(1, A, 8);

    printf("Vertex: 4 -> ");
    BFS(4, A, 8);

    return 0;
}


// utilizei C++ por que em C eu teria que construir tudo do 0, enquanto em C++ eu posso usar a biblioteca queue para facilitar minha vida kk