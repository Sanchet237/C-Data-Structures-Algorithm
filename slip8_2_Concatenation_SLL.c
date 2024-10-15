//Q.2) Write a C program to concatenate two singly linked list
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int info;
    struct Node* next;
} Node;

Node* create() {
    Node* head = NULL;
    Node* last = NULL;
    int n;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    for (int count = 1; count <= n; count++) {
        Node* newNode = (Node*)malloc(sizeof(Node));
        printf("Enter data for node %d: ", count);
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
    printf("Linked list: ");
    Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->info);
        temp = temp->next;
    }
    printf("NULL\n");
}

Node* concatenate(Node* l1, Node* l2) {
    if (l1 == NULL) {
        return l2;
    }
    if (l2 == NULL) {
        return l1;
    }

    Node* temp = l1;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = l2;

    return l1;
}

void freeList(Node* head) {
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    printf("Create first linked list:\n");
    Node* l1 = create();

    printf("Create second linked list:\n");
    Node* l2 = create();

    printf("First Linked List: ");
    display(l1);

    printf("Second Linked List: ");
    display(l2);

    Node* concat = concatenate(l1, l2);
    printf("Concatenated Linked List: ");
    display(concat);

    freeList(concat);
    return 0;
}
