/*Write a C program to display addition of two polynomials using singly linked list.*/
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int coeff;       
    int exp;         
    struct Node* next;
} Node;

Node* insertTerm(Node* head, int coeff, int exp) {
    Node* newTerm = (Node*)malloc(sizeof(Node));
    newTerm->coeff = coeff;
    newTerm->exp = exp;
    newTerm->next = NULL;

    if (!head || exp > head->exp) {
        newTerm->next = head;
        return newTerm;
    }

    Node* current = head;
    while (current->next && current->next->exp >= exp) {
        current = current->next;
    }

    if (current->exp == exp) {
        current->coeff += coeff;  // Combine coefficients if exponent matches
        free(newTerm);            // Free newTerm since we don't need to add it
    } else {
        newTerm->next = current->next;
        current->next = newTerm;
    }

    return head;
}

Node* addPolynomials(Node* p1, Node* p2) {
    Node* sum = NULL;

    while (p1 || p2) {
        if (!p1) {
            sum = insertTerm(sum, p2->coeff, p2->exp);
            p2 = p2->next;
        } else if (!p2) {
            sum = insertTerm(sum, p1->coeff, p1->exp);
            p1 = p1->next;
        } else if (p1->exp > p2->exp) {
            sum = insertTerm(sum, p1->coeff, p1->exp);
            p1 = p1->next;
        } else if (p1->exp < p2->exp) {
            sum = insertTerm(sum, p2->coeff, p2->exp);
            p2 = p2->next;
        } else {
            sum = insertTerm(sum, p1->coeff + p2->coeff, p1->exp);
            p1 = p1->next;
            p2 = p2->next;
        }
    }
    return sum;
}

void displayPolynomial(Node* head) {
    if (!head) {
        printf("0");
        return;
    }
    while (head) {
        printf("%dx^%d", head->coeff, head->exp);
        if (head->next) printf(" + ");
        head = head->next;
    }
    printf("\n");
}

void freePolynomial(Node* head) {
    Node* temp;
    while (head) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    Node* poly1 = NULL;
    Node* poly2 = NULL;
    
    printf("Enter first polynomial (coeff exp), enter -1 -1 to end:\n");
    int coeff, exp;
    while (1) {
        scanf("%d %d", &coeff, &exp);
        if (coeff == -1 && exp == -1) break;
        poly1 = insertTerm(poly1, coeff, exp);
    }
    
    printf("Enter second polynomial (coeff exp), enter -1 -1 to end:\n");
    while (1) {
        scanf("%d %d", &coeff, &exp);
        if (coeff == -1 && exp == -1) break;
        poly2 = insertTerm(poly2, coeff, exp);
    }

    Node* sum = addPolynomials(poly1, poly2);
    printf("Sum of polynomials: ");
    displayPolynomial(sum);

    freePolynomial(poly1);
    freePolynomial(poly2);
    freePolynomial(sum);
    
    return 0;
}

/*Enter first polynomial (coeff exp), -1 -1 to end:
3 2
4 1
5 0
-1 -1
Enter second polynomial (coeff exp), -1 -1 to end:
2 1
1 0
-1 -1

Sum of polynomials: 3x^2 + 6x^1 + 6x^0

*/