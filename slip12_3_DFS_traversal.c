/*Q2. Write a C program to traverse graph by using DFS.*/

#include <stdio.h>

#define MAX 20

int a[MAX][MAX], reach[MAX], n;

void dfs(int v) {
    int i;
    reach[v] = 1;
    for (i = 1; i <= n; i++) {
        if (a[v][i] && !reach[i]) {
            printf("\n %d -> %d", v, i);
            dfs(i);
        }
    }
}

int main() {
    int i, j, count = 0;

    printf("\n Enter number of vertices: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        reach[i] = 0;
        for (j = 1; j <= n; j++) {
            a[i][j] = 0;
        }
    }

    printf("\n Enter the adjacency matrix:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    printf("DFS Traversal starting from vertex 1:");
    dfs(1);
    printf("\n");

    for (i = 1; i <= n; i++) {
        if (reach[i]) count++;
    }

    if (count == n) {
        printf("\n Graph is connected\n");
    } else {
        printf("\n Graph is not connected\n");
    }

    return 0;
}
