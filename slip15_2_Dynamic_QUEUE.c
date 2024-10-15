/*Q.2) Write a C program to implement Dynamic Implementation of Queue with following operations:
● Insert
● Delete
● Empty*/

#include <stdio.h>
#include <stdlib.h>

typedef struct NODE {
    int info;
    struct NODE* next;
} NODE;

NODE* front = NULL;
NODE* rear = NULL;

int is_empty() {
    return (front == NULL);
}

void insert(int n) {
    NODE* newnode = (NODE*)malloc(sizeof(NODE));
    if (newnode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    newnode->info = n;
    newnode->next = NULL;
    if (rear == NULL) {
        front = rear = newnode;
    } else {
        rear->next = newnode;
        rear = newnode;
    }
}

int dequeue() {
    if (is_empty()) {
        printf("Queue is empty, cannot remove.\n");
        return -1;
    }
    NODE* t = front;
    int n = front->info;
    front = front->next;
    if (front == NULL) {
        rear = NULL;
    }
    free(t);
    return n;
}

void display() {
    if (is_empty()) {
        printf("Queue is empty.\n");
        return;
    }
    NODE* t = front;
    printf("Queue elements: ");
    while (t != NULL) {
        printf("%d ", t->info);
        t = t->next;
    }
    printf("\n");
}

int main() {
    int ch, n;
    do {
        printf("\nQueue Operations:\n1. Insert\n2. Delete\n3. Empty\n4. Display\n5. Exit\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("Enter the element: ");
                scanf("%d", &n);
                insert(n);
                break;
            case 2:
                printf("Removed element is: %d\n", dequeue());
                break;
            case 3:
                if (is_empty()) {
                    printf("Queue is empty.\n");
                } else {
                    printf("Queue is not empty.\n");
                }
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (ch != 5);

    return 0;
}
