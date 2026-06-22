#include <stdio.h>
#include <stdlib.h>
#include <limits.h>  // нужно для INT_MAX (наша бесконечность)

#define N 3
#define INF INT_MAX

int matrix[N][N] = {
        {0, 1, 2},
        {1, 0, 3},
        {2, 3, 0}
};

int main() {
    int visited[N];
    int key[N];
    int parent[N];
    for (int i = 0; i < N; i++) {
        visited[i] = 0;
        key[i] = INF;
        parent[i] = -1;
    }

    key[0] = 0;
    for (int count = 0; count < N; count++) {

        int min_key = INF;
        int u = -1;

        for (int i = 0; i < N; i++) {
            if (visited[i] == 0 && key[i] < min_key) {
                min_key = key[i];
                u = i;
            }
        }
        visited[u] = 1;
        for (int v = 0; v < N; v++) {

            if (matrix[u][v] != 0 && visited[v] == 0 && matrix[u][v] < key[v]) {
                parent[v] = u;
                key[v] = matrix[u][v];
            }
        }

    }


    return 0;
}
