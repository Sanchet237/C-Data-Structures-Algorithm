//Q2. Write a C program to evaluate a postfix expression. (20)

#include <stdio.h>
#include <ctype.h>
#include <math.h>
#define MAX 100

int stack[MAX];
int top = -1;

void push(int value) {
    if (top < MAX - 1) {
        stack[++top] = value;
    } else {
        printf("Stack overflow\n");
    }
}

int pop() {
    if (top >= 0) {
        return stack[top--];
    } else {
        printf("Stack is empty\n");
        return -1;
    }
}


int evaluatePostfix(const char* pfix) {
    for (int i = 0; pfix[i]; i++) 
    {
        if (isdigit(pfix[i])) push(pfix[i] - '0');
        else {
            int op2 = pop(), op1 = pop();

            switch (pfix[i]) {
                case '+': push(op1 + op2); break;
                case '-': push(op1 - op2); break;
                case '*': push(op1 * op2); break;
                case '/': 
                    if (op2) push(op1 / op2);
                    else { printf("Division by zero error\n"); return -1; }
                    break;
                case '^': push((int)pow(op1, op2)); break;
                default: return -1; 
            }
        }
    }
    return pop(); 
}

int main() {
    char pfix[MAX];
    
    printf("Enter a postfix expression: ");
    scanf("%s", pfix);

    int result = evaluatePostfix(pfix);

    if (result != -1) printf("Result: %d\n", result);
    else printf("Invalid expression.\n");

    return 0;
}
