/*Q.2) Write a C program to implement static implementation of Circular Queue with operations:
● Insert ()
● Delete ()
● Empty ()*/

#include <stdio.h>

#define MAX 5

int queue[MAX];
int F = -1;
int R = -1; 

void initialize() {
    F = R = -1;
}

int isempty() {
    return F == -1;
}

int isfull() {
    return (F == 0 && R == MAX - 1) || (F == R + 1);
}

void insert(int value) {
    if (isfull()) {
        printf("Queue is full\n");
        return;
    }
    if (isempty()) {
        F = R = 0;
    } else if (R == MAX - 1 && F != 0) {
        R = 0; 
    } else {
        R++;
    }
    queue[R] = value;
}

int delete() {
    if (isempty()) {
        printf("Queue is empty\n");
        return -1;
    }
    int value = queue[F];
    if (F == R) {
        initialize(); 
    } else if (F == MAX - 1) {
        F = 0; 
    } else {
        F++;
    }
    return value;
}

int main() {
    int choice, value;
    initialize();

    while (1) {
        printf("\nCircular Queue Operations:\n1. Insert\n2. Delete\n3. Check if empty\n4. Check if full\n5. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                insert(value);
                break;
            case 2:
                value = delete();
                if (value != -1) {
                    printf("Deleted value: %d\n", value);
                }
                break;
            case 3:
                if (isempty()) {
                    printf("Queue is empty.\n");
                } else {
                    printf("Queue is not empty.\n");
                }
                break;
            case 4:
                if (isfull()) {
                    printf("Queue is full.\n");
                } else {
                    printf("Queue is not full.\n");
                }
                break;
            case 5:
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
