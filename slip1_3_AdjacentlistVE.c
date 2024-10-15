/*Q2. Write a C program to accept the vertices and edges for a graph and store it as
an adjacency list and display it.*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

typedef struct {
    int adj[MAX_VERTICES][MAX_VERTICES];
    int numVertices;
} Graph;

Graph* createGraph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = vertices;

    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
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
    for (int i = 0; i < graph->numVertices; i++) {
        printf("Vertex %d: ", i);
        for (int j = 0; j < graph->numVertices; j++) {
            if (graph->adj[i][j] == 1) {
                printf("%d ", j);
            }
        }
        printf("\n");
    }
}

int main() {
    int vertices, edges;

    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    Graph* graph = createGraph(vertices);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    for (int i = 0; i < edges; i++) {
        int src, dest;
        printf("Enter edge %d (source and destination): ", i + 1);
        scanf("%d %d", &src, &dest);
        addEdge(graph, src, dest);
    }

    printGraph(graph);

    free(graph);
    return 0;
}
