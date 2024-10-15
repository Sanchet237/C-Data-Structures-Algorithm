/*Q2. Write a C program to convert infix expression into Postfix.*/
#include <stdio.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) {
    if (top < MAX - 1) {
        stack[++top] = c;
    }
}

char pop() {
    if (top >= 0) {
        return stack[top--];
    } else {
        return -1;
    }
}

char peek() {
    if (top >= 0) {
        return stack[top];
    } else {
        return -1;
    }
}

int priority(char c) {
    switch (c) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}

int isOprtr(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

void infix2Pfix(const char* infix, char* pfix) {
    int i = 0, j = 0;
    char c;

    while (infix[i] != '\0') {
        c = infix[i];

        if (isalnum(c)) {
            pfix[j++] = c;
        } else if (c == '(') {
            push(c);
        } else if (c == ')') {
            while (top != -1 && peek() != '(') {
                pfix[j++] = pop();
            }
            pop(); 
        } else if (isOprtr(c)) {
            while (top != -1 && priority(peek()) >= priority(c)) {
                pfix[j++] = pop();
            }
            push(c);
        }

        i++;
    }

    while (top != -1) {
        pfix[j++] = pop();
    }

    pfix[j] = '\0'; 
}

int main() {
    char infix[MAX], pfix[MAX];

    printf("Enter an infix expression: ");
    scanf("%s", infix);

    infix2Pfix(infix, pfix);

    printf("Postfix expression: %s\n", pfix);

    return 0;
}
