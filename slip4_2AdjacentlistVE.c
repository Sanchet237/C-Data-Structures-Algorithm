/*Q2. Write a C program to accept the V and E for a graph and store it as
an adjacency list and display it.*/
#include <stdio.h>
#include <stdlib.h>

#define MAX_V 100

typedef struct {
    int adj[MAX_V][MAX_V];
    int n_Vertices;
} Graph;

Graph* createGraph(int V) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->n_Vertices = V;
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            graph->adj[i][j] = 0;
    return graph;
}

void addEdge(Graph* graph, int src, int dest) {
    graph->adj[src][dest] = 1;
    graph->adj[dest][src] = 1; // remove for directed graph
}

void printGraph(Graph* graph) {
    for (int i = 0; i < graph->n_Vertices; i++) {
        printf("Vertex %d: ", i);
        for (int j = 0; j < graph->n_Vertices; j++) {
            if (graph->adj[i][j]) printf("%d ", j);
        }
        printf("\n");
    }
}

int main() {
    int V, E;
    printf("Enter the number of vertices: ");
    scanf("%d", &V);

    Graph* graph = createGraph(V);

    printf("Enter the number of edges: ");
    scanf("%d", &E);
    for (int i = 0; i < E; i++) {
        int src, dest;
        printf("Enter edge %d (source and destination): ", i + 1);
        scanf("%d %d", &src, &dest);
        addEdge(graph, src, dest);
    }

    printGraph(graph);
    free(graph);
    return 0;
}
