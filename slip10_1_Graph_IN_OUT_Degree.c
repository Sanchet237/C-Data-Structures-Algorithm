/*Q.1) Write a C program to read a directed graph as adjacency matrix and display in-degree and out-degree of each node.*/

#include <stdio.h>

#define MAX_NODES 50

int main() {
    int adjacencyMatrix[MAX_NODES][MAX_NODES];
    int inDegree[MAX_NODES] = {0};
    int outDegree[MAX_NODES] = {0};
    int numNodes, i, j;

    printf("Enter the number of nodes: ");
    scanf("%d", &numNodes);

    printf("Enter the adjacency matrix:\n");
    for (i = 0; i < numNodes; i++) {
        for (j = 0; j < numNodes; j++) {
            scanf("%d", &adjacencyMatrix[i][j]);
            if (adjacencyMatrix[i][j] == 1) {
                outDegree[i]++;
                inDegree[j]++;
            }
        }
    }

    printf("Node\tIn-Degree\tOut-Degree\n");
    for (i = 0; i < numNodes; i++) {
        printf("%d\t%d\t\t%d\n", i, inDegree[i], outDegree[i]);
    }

    return 0;
}
