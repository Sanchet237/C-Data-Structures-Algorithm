//Q.1) Write a C program to create and display singly linked list.
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int info;
    struct Node* next;
} Node;

Node* create() {
    Node* head = NULL;
    Node* newNode;
    Node* last = NULL;
    int n;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    for (int count = 1; count <= n; count++) {
        newNode = (Node*)malloc(sizeof(Node));
        if (newNode == NULL) {
            printf("Memory allocation failed.\n");
            return head;
        }
        printf("Data for Node %d: ", count);
        scanf("%d", &newNode->info);
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode; 
        } else {
            last->next = newNode; 
        }
        last = newNode; 
    }

    return head;
}

void display(Node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    printf("Singly Linked List: ");
    Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->info);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    Node* head = create();
    display(head);
    return 0;
}
