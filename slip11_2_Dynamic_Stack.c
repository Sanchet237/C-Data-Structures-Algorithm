/*Q.2) Write a C program to implement dynamic stack of integer with operations: (20)
● Push ()
● Pop ()
● IsEmpty ()
● Isfull()*/

#include <stdio.h>
#include <stdlib.h>

typedef struct NODE {
    int info;
    struct NODE* next;
} NODE;

NODE* top = NULL; 

void Push(int n) {
    NODE* newnode = (NODE*)malloc(sizeof(NODE));
    newnode->info = n;
    newnode->next = top;
    top = newnode;
}

int Pop() {
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

int IsEmpty() {
    return top == NULL;
}

int IsFull() {
    NODE* newnode = (NODE*)malloc(sizeof(NODE));
    if (!newnode) return 1; 
    free(newnode);
    return 0; 
}

int main() {
    int ch, n;
    do {
        printf("\nMenu:\n1. Push\n2. Pop\n3. Is Empty\n4. Is Full\n5. Exit\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("Enter the element: ");
                scanf("%d", &n);
                Push(n);
                break;
            case 2:
                printf("Popped element is: %d\n", Pop());
                break;
            case 3:
                printf("Stack is %s\n", IsEmpty() ? "empty" : "not empty");
                break;
            case 4:
                printf("Stack is %s\n", IsFull() ? "full" : "not full");
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (ch != 5);

    return 0;
}
