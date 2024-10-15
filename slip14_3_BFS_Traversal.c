/*Q2. Write a C program to traverse graph by using BFS*/

#include <stdio.h>
#define MAX 100

int adj[MAX][MAX];
int visited[MAX];
int queue[MAX];
int front = -1, rear = -1;

void enqueue(int value) {
    if (rear == MAX - 1) {
        printf("Queue Overflow\n");
    } else {
        if (front == -1) front = 0;
        queue[++rear] = value;
    }
}

int dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue Underflow\n");
        return -1;
    } else {
        return queue[front++];
    }
}

void bfs(int start, int n) {
    int i;
    printf("BFS Traversal starting from vertex %d: ", start);
    enqueue(start);
    visited[start] = 1;

    while (front <= rear) {
        int v = dequeue();
        printf("%d ", v);

        for (i = 1; i <= n; i++) {
            if (adj[v][i] == 1 && !visited[i]) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

int main() {
    int n, i, j, start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        visited[i] = 0;
        for (j = 1; j <= n; j++) {
            adj[i][j] = 0;
        }
    }

    printf("Enter the adjacency matrix:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    printf("Enter the starting vertex: ");
    scanf("%d", &start);

    bfs(start, n);

    return 0;
}
