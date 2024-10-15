/*Q.2) Write a C program to check whether an expression has correct pairs of parentheses, using Stack.*/

#include <stdio.h>
#include <string.h>
#define max 30

int top = -1;
char stack[max];

void push(char item) {
    if (top == (max - 1)) {
        printf("Stack overflow\n");
        return;
    }
    stack[++top] = item;
}

char pop() {
    if (top == -1) {
        printf("Stack underflow\n");
        return '\0'; 
    }
    return stack[top--];
}

int match(char a, char b) {
    return (a == '[' && b == ']') || (a == '{' && b == '}') || (a == '(' && b == ')');
}

int check(char exp[]) {
    char t;
    for (int i = 0; i < strlen(exp); i++) {
        if (exp[i] == '(' || exp[i] == '[' || exp[i] == '{') {
            push(exp[i]);
        } else if (exp[i] == ')' || exp[i] == ']' || exp[i] == '}') {
            if (top == -1) {
                printf("Right parenthesis is more than left\n");
                return 0;
            } else {
                t = pop();
                if (!match(t, exp[i])) {
                    printf("Mismatched parenthesis: %c and %c\n", t, exp[i]);
                    return 0;
                }
            }
        }
    }
    if (top == -1) {
        printf("Balanced parenthesis\n");
        return 1;
    } else {
        printf("Left parenthesis is more than right\n");
        return 0;
    }
}

int main() {
    char exp[max];
    int valid;
    printf("Enter an algebraic expression: ");
    fgets(exp, max, stdin);
    
    valid = check(exp);
    if (valid == 1) {
        printf("Expression is valid\n");
    } else {
        printf("Expression is not valid\n");
    }
    return 0;
}

