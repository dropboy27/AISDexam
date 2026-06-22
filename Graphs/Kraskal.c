#include <stdlib.h>
#include <stdio.h>

void insertion_sort(int n, int m, int graph[n][m]){
    for (int i = 1; i < n; i++){
        int *current = graph[i];
        int a = current[0];
        int b = current[1];
        int w = current[2];
        int j = i-1;
        while( j >=0 && graph[j][2] > w){
            graph[j+1][0] = graph[j][0];
            graph[j+1][1] = graph[j][1];
            graph[j+1][2] = graph[j][2];
            j--;
        }
        graph[j+1][0] = a;
        graph[j+1][1] = b;
        graph[j+1][2] = w;
    }
}

int FindParent(int n, int parent[n], int i){
    while (parent[i]!=-1){

        i = parent[i];
    }
    return i;
}

void Kruskal(int n, int m, int parent[n], int graph[n][m]){
    insertion_sort(n,m,graph);
    for (int i = 0; i <n; i++){
        int u = graph[i][0];
        int v = graph[i][1];
        int root_u = FindParent(n, parent, u);
        int root_v = FindParent(n, parent,v);
        if (root_u!= root_v){
            printf("{u:%d v:%d w:%d}\n", u, v, graph[i][2]);
            parent[root_v] = root_u;
        }
    }
}




int main(){
    int graph[5][3] = {
            {0, 1, 10},
            {0, 2, 6},
            {0, 3, 5},
            {1, 3, 15},
            {2, 3, 4}
    };
    int par[5];
    for (int i =0; i <5; i++){
        par[i] = -1;
    }
    Kruskal(5,3,par,graph);

}