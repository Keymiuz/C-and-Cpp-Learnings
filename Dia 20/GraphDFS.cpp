#include <cstdio>
#include <queue>
#include <vector>
#include <stack> // Necessário para a versão iterativa do DFS

using namespace std;

void DFS(int G[][7], int start, int n) {
    vector<bool> visited(n, false);
    stack<int> S;

    printf("DFS a partir de %d: ", start);

    S.push(start);
    visited[start] = true;
    printf("%d ", start);

    while (!S.empty()) {
        int u = S.top();
        bool found_unvisited_neighbor = false;
        for (int v = 1; v < n; v++) {
            if (G[u][v] == 1 && !visited[v]) {
                S.push(v);
                visited[v] = true;
                printf("%d ", v);
                found_unvisited_neighbor = true;
                break;
            }
        }
        if (!found_unvisited_neighbor) {
            S.pop();
        }
    }
    printf("\n");
}

int main() {
    int G[7][7] = {
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 1, 1, 0, 0, 0},
        {0, 1, 0, 0, 1, 0, 0},
        {0, 1, 0, 0, 1, 0, 0},
        {0, 0, 1, 1, 0, 1, 1},
        {0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 0, 0}
    };
    DFS(G, 4, 7); 
    return 0;
}

// esse código foi construido de forma iterativa, se não eu teria que usar uma função auxiliar para percorrer a matriz e eu estava com preguiça de fazer essa lógica