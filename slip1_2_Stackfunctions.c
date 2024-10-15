/*Q.2) Write a C program to implement static stack of integer with operations: (20)
● Push ()
● Pop ()
● Empty ()*/

#include <stdio.h>
#define MAX 100

int stack[MAX];
int top = -1;

void push(int value) {
    if (top == MAX - 1) {
        printf("Stack Overflow. Cannot push %d\n", value);
        return;
    }
    stack[++top] = value;
}

int pop() {
    if (top == -1) {
        printf("Stack is empty. Cannot pop.\n");
        return -1;
    }
    return stack[top--];
}

int isempty() {
    return top == -1;
}

void display() {
    if (isempty()) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack elements are:\n");
    for (int i = top; i >= 0; i--) {
        printf("%d\n", stack[i]);
    }
}

int main() {
    int choice, value;

    while (1) {
        printf("\nStack Operations:\n1. Push\n2. Pop\n3. Display\n4. Check if empty\n5. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) 
        {
            case 1:
                printf("Enter the value to push: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                value = pop();
                if (value != -1) {
                    printf("Popped value: %d\n", value);
                }
                break;
            case 3:
                display();
                break;
            case 4:
                if (isempty()) {
                    printf("Stack is empty.\n");
                } else {
                    printf("Stack is not empty.\n");
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
