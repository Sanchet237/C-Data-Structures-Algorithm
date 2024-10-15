//Q.1) Write a C program to accept two polynomials and display the addition of polynomials.(10)

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int coef;           
    int exp;            
    struct Node* next;  
} Node;

void insert(Node** poly, int coef, int exp) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->coef = coef;
    temp->exp = exp;
    temp->next = NULL;

    if (*poly == NULL || (*poly)->exp < exp) {
        temp->next = *poly;
        *poly = temp;
    } else {
        Node* current = *poly;
        while (current->next != NULL && current->next->exp >= exp) {
            current = current->next;
        }
        temp->next = current->next;
        current->next = temp;
    }
}

void print(Node* poly) {
    if (poly == NULL) {
        printf("0\n");
        return;
    }

    Node* current = poly;
    while (current != NULL) {
        printf("%dx^%d", current->coef, current->exp);
        if (current->next != NULL) {
            printf(" + ");
        }
        current = current->next;
    }
    printf("\n");
}

Node* add(Node* poly1, Node* poly2) {
    Node* result = NULL;

    while (poly1 != NULL || poly2 != NULL) {
        if (poly1 != NULL && (poly2 == NULL || poly1->exp > poly2->exp)) {
            insert(&result, poly1->coef, poly1->exp);
            poly1 = poly1->next;
        } else if (poly2 != NULL && (poly1 == NULL || poly2->exp > poly1->exp)) {
            insert(&result, poly2->coef, poly2->exp);
            poly2 = poly2->next;
        } else {
            insert(&result, poly1->coef + poly2->coef, poly1->exp);
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }

    return result;
}

int main() {
    Node* poly1 = NULL;
    Node* poly2 = NULL;
    int numTerms, coef, exp;

    printf("Enter number of terms in first polynomial: ");
    scanf("%d", &numTerms);
    for (int i = 0; i < numTerms; i++) {
        printf("Enter coefficient and exponent for term %d: ", i + 1);
        scanf("%d %d", &coef, &exp);
        insert(&poly1, coef, exp);
    }

    printf("Enter number of terms in second polynomial: ");
    scanf("%d", &numTerms);
    for (int i = 0; i < numTerms; i++) {
        printf("Enter coefficient and exponent for term %d: ", i + 1);
        scanf("%d %d", &coef, &exp);
        insert(&poly2, coef, exp);
    }

    printf("First polynomial: ");
    print(poly1);
    printf("Second polynomial: ");
    print(poly2);

    Node* result = add(poly1, poly2);
    printf("Result: ");
    print(result);

    free(poly1);
    free(poly2);
    free(result);

    return 0;
}
