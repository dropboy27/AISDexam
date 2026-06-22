#include <stdlib.h>
#include <stdio.h>
typedef struct Node{
    int ver;
    int weight;
    struct Node * next;
}Node;


typedef struct Graph{
    int num_vert;
    Node **arr_of_nodes;
}Graph;

Node *CreateNode(int v, int w){
    Node* new = (Node *)malloc(sizeof(Node));
    new -> ver = v;
    new->weight = w;
    new->next = NULL;
    return new;
}

Graph *CreateGraph(int vertices){
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->num_vert = vertices;

    graph->arr_of_nodes = (Node**)malloc(sizeof(Node*) * vertices);

    for (int i = 0; i<vertices; i++){
        graph->arr_of_nodes[i] = NULL;
    }
    return graph;
}

Node *AddEdge(Graph *graph, int el, int vert, int weight){
    Node *new = CreateNode(vert, weight);
    new->next = graph->arr_of_nodes[el];
    graph->arr_of_nodes[el] = new;
}

void Print(Graph* graph){
    for (int i = 0; i <graph->num_vert; i++){
        Node *curr = graph->arr_of_nodes[i];
        while(curr!=NULL){
            printf("(%d %d), ", curr->weight, curr->ver);
            curr = curr->next;
        }
        printf("\n");
    }
}


int main_1() {
    // Создаем граф на 3 вершины (0, 1, 2)
    Graph *myGraph = CreateGraph(3);

    // Добавляем ребра (ориентированные, из одной вершины в другую)
    AddEdge(myGraph, 0, 1, 2); // Из 0 в 1 с весом 2
    AddEdge(myGraph, 0, 2, 3); // Из 0 в 2 с весом 3
    AddEdge(myGraph, 1, 2, 5); // Из 1 в 2 с весом 5

    // Выводим результат
    Print(myGraph);

    // По-хорошему здесь еще нужна функция FreeGraph для очистки памяти,
    // но для быстрого теста пока сойдет и так.

    return 0;
}