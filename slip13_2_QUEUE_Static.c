/*Q.2) Write a C program to implement static implementation of Linear Queue with operations:
● Insert ()
● Delete ()
● Empty ()*/
#include <stdio.h>
#define MAX 100

int queue[MAX];
int front = -1;
int rear = -1;

void initialize() {
    front = rear = -1;
}

int isempty() {
    return front == -1;
}

int isfull() {
    return rear == MAX - 1;
}

void insert(int value) {
    if (isfull()) {
        printf("Queue is full. Cannot insert %d\n", value);
        return;
    }
    if (isempty()) {
        front = rear = 0;
    } else {
        rear++;
    }
    queue[rear] = value;
}

int delete() {
    if (isempty()) {
        printf("Queue is empty. Cannot delete.\n");
        return -1;
    }
    int value = queue[front];
    if (front == rear) {
        initialize();
    } else {
        front++;
    }
    return value;
}

void display() {
    if (isempty()) {
        printf("Queue is empty.\n");
        return;
    }
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    int choice, value;

    while (1) {
        printf("\nQueue Operations:\n1. Insert\n2. Delete\n3. Display\n4. Exit\nEnter your choice: ");
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
                display();
                break;
            case 4:
                return 0;
        }
    }

    return 0;
}
