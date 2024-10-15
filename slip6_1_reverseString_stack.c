//Q.1) Write a C program to reverse a string using Stack . (10)

#include <stdio.h>
#include <string.h>
#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) {
    if (top < MAX - 1) {
        stack[++top] = c;
    } else {
        printf("Stack is full\n");
    }
}

char pop() {
    if (top >= 0) {
        return stack[top--];
    } else {
        printf("Stack is empty\n");
        return '\0'; 
    }
}

void reverseString(char *str, char *rev) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        push(str[i]);
    }

    for (int i = 0; i < len; i++) {
        rev[i] = pop();
    }
    rev[len] = '\0';
}

int main() {
    char str[MAX];
    char rev[MAX];

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    // Remove the newline character if present
    str[strcspn(str, "\n")] = '\0';
   
    reverseString(str, rev);

    printf("Reversed string: %s\n", rev);

    return 0;
}
