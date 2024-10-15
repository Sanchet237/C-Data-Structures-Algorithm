/*Q.2) Write a C program to implement dynamic implementation of circularqueue with following operations:
● Insert
● Delete
● IsEmpty
● Isfull*/

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

int is_full() {
    return 0; 

void insert(int n) {
    NODE* newnode = (NODE*)malloc(sizeof(NODE));
    if (newnode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    newnode->info = n;
    if (is_empty()) {
        front = rear = newnode;
        rear->next = front; 
    } else {
        rear->next = newnode;
        rear = newnode;
        rear->next = front; 
    }
}

int dequeue() {
    if (is_empty()) {
        printf("Queue is empty, cannot remove.\n");
        return -1;
    }
    NODE* t = front;
    int n = front->info;
    if (front == rear) {
        front = rear = NULL;
    } else {
        front = front->next;
        rear->next = front; 
    }
    free(t);
    return n;
}

int main() {
    int ch, n;
    printf("Dynamic implementation of Circular Queue\n");
    do {
        printf("1. Insert 2. Delete 3. Is Empty 4. Is Full 5. Exit\nEnter your choice: ");
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
                printf("Queue is %s\n", is_empty() ? "empty" : "not empty");
                break;
            case 4:
                printf("Queue is %s\n", is_full() ? "full" : "not full");
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
