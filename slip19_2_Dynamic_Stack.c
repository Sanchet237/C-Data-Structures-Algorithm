/*Q.2) Write a C program to implement dynamic implementation of stack with following operations:
● Push
● Pop
● IsEmpty
● Isfull*/

#include <stdio.h>
#include <stdlib.h>

typedef struct NODE {
    int info;
    struct NODE* next;
} NODE;

NODE* top = NULL; 

void Push(int n) {
    NODE* newnode = (NODE*)malloc(sizeof(NODE));
    if (!newnode) {
        printf("Memory allocation failed!\n");
        return;
    }
    newnode->info = n;
    newnode->next = top;
    top = newnode;
}

int pop() {
    if (!top) {
        printf("Stack is empty, cannot pop.\n");
        return -1; 
    }
    NODE* t = top;
    int n = top->info;
    top = top->next;
    free(t);
    return n;
}

int is_empty() {
    return top == NULL;
}

void display() {
    if (is_empty()) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack elements: ");
    for (NODE* t = top; t != NULL; t = t->next) {
        printf("%d ", t->info);
    }
    printf("\n");
}

void peek() {
    if (is_empty()) {
        printf("Stack is empty, no top element.\n");
    } else {
        printf("Top element is: %d\n", top->info);
    }
}

int main() {
    int ch, n;
    do {
        printf("1. Push 2. Pop 3. Is Empty 4. Display 5. Peek 6. Exit\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("Enter the element: ");
                scanf("%d", &n);
                Push(n);
                break;
            case 2:
                if (is_empty()) {
                    printf("Stack is empty.\n");
                } else {
                    printf("Popped element is: %d\n", pop());
                }
                break;
            case 3:
                printf("Stack is %s\n", is_empty() ? "empty" : "not empty");
                break;
            case 4:
                display();
                break;
            case 5:
                peek();
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (ch != 6);

    return 0;
}
