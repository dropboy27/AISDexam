#include <stdlib.h>
#include <stdio.h>
#include <limits.h>


void Dijkstra(int n, int graph[n][n]){
    int parent[n];
    for (int i = 0; i < n; i++){
        parent[i] = -1;
    }
    int dist[n];
    for (int i = 0; i < n; i++){
        dist[i] = INT_MAX;
    }
    int visited[n];
    for (int i = 0; i < n; i++){
        visited[i] = 0;
    }
    dist[0] = 0;
    for (int count = 0; count < n; count++) {
        int min_dist = INT_MAX;
        int u = -1;
        for (int i = 0; i < n; i++){
            if (!visited[i] && dist[i]<min_dist){
                u = i;
                min_dist = dist[i];
            }
        }
        if (u == -1) break;
        visited[u] = 1;
        for (int j = 0; j < n; j++) {
            if (graph[u][j] != 0 && !visited[j] && dist[u] != INT_MAX) {
                int new_dist = graph[u][j] + dist[u];
                if (new_dist < dist[j]) {
                    dist[j] = new_dist;
                    parent[j] = u;
                }
            }
        }
    }
    for (int i = 0; i<n; i++){
        printf("Vert %d: %d\n",i, dist[i]);
    }
    int target = 4;
    printf("%d", target);
    int curr = parent[target];
    while (curr != -1) {
        printf(" <- %d", curr);
        curr = parent[curr];
    }
}






int main(){
    int graph[5][5] = {
            {0, 10,  3,  0,  0},
            {0,  0,  1,  2,  0},
            {0,  4,  0,  8,  2},
            {0,  0,  0,  0,  7},
            {0,  0,  0,  0,  0}
    };
    Dijkstra(5,graph);

}