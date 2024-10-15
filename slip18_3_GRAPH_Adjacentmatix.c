/*Q2. Write C program to construct a graph using adjacency matrix and display its adjacency list (20)*/
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

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            graph->adj[i][j] = 0;
        }
    }
    
    return graph;
}

void addEdge(Graph* graph, int src, int dest) {
    graph->adj[src][dest] = 1;
    graph->adj[dest][src] = 1;
}

void printGraph(Graph* graph) {
    for (int i = 0; i < graph->n_Vertices; i++) {
        printf("Vertex %d: ", i);
        for (int j = 0; j < graph->n_Vertices; j++) {
            if (graph->adj[i][j] == 1) {
                printf("%d ", j);
            }
        }
        printf("\n");
    }
}

int main() {
    int V, E;

    printf("Enter the number of vertices (V): ");
    scanf("%d", &V);

    Graph* graph = createGraph(V);

    printf("Enter the number of edges (E): ");
    scanf("%d", &E);

    for (int i = 0; i < E; i++) {
        int src, dest;
        printf("Enter edge %d (source and destination): ", i + 1);
        scanf("%d %d", &src, &dest);
        addEdge(graph, src, dest);
    }

    printf("\nAdjacency List Representation:\n");
    printGraph(graph);

    free(graph);
    return 0;
}
