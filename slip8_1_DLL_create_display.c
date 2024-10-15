//Write a C program to create and display doubly linked list.

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int info;
    struct Node* next;
    struct Node* prev;
} Node;

Node* create() {
    Node* head = NULL;
    Node* newNode;
    Node* last = NULL;
    int n, count;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    for (count = 1; count <= n; count++) {
        newNode = (Node*)malloc(sizeof(Node));

        printf("Enter data for node %d: ", count);
        scanf("%d", &newNode->info);
        newNode->next = NULL;
        newNode->prev = NULL;

        if (head == NULL) {
            head = newNode;
        } else {
            last->next = newNode;
            newNode->prev = last;
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
    printf("Doubly Linked List: ");
    Node* temp = head;
    while (temp != NULL) {
        printf("%d <-> ", temp->info);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    Node* head = NULL;
    head = create();
    display(head);   
    return 0;
}
