/*Q.2) Write a C program to implement dynamic implementation of stack of integers with followingoperation:
a) push()
b) pop ()
c) isempty()
d) isfull()
e) display ()*/

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
    printf("\nStack elements: ");
    for (NODE* t = top; t != NULL; t = t->next) {
        printf("%d ", t->info);
    }
    printf("\n");
}

int main() {
    int ch, n;
    do {
        printf("1. Push \n2. Pop \n3. Is Empty \n4. Display \n5. Exit\n\nEnter your choice: ");
        scanf("%d", &ch);
        
        switch (ch) {
            case 1:
                printf("Enter the element: ");
                scanf("%d", &n);
                Push(n);
                break;
            case 2:
                if (is_empty()) {
                    printf("Stack is empty.\n");} 
                else {
                    printf("Popped element is: %d\n", pop());}
                break;
            case 3:
                printf("Stack is %s\n", is_empty() ? "empty" : "not empty");
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (ch != 5);

    return 0;
}
