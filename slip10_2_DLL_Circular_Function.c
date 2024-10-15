/*Write a menu driven program using C for implementation of doubly circular linked list. Menu should have the following options –
1. Create.
2. Display.
3. Delete a node at given position.*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

Node* head = NULL;

void create() {
    Node* newNode;
    Node* last;
    int n, i;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid number of nodes.\n");
        return;
    }

    for (i = 1; i <= n; i++) {
        newNode = (Node*)malloc(sizeof(Node));
        printf("Enter data for node %d: ", i);
        scanf("%d", &newNode->data);
        newNode->next = newNode->prev = NULL;

        if (head == NULL) { 
            head = newNode;
            head->next = head;
            head->prev = head;
        } else {
            last = head->prev;
            last->next = newNode;
            newNode->prev = last;
            newNode->next = head;
            head->prev = newNode;
        }
    }
}

void display() {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    Node* temp = head;
    printf("Doubly Circular Linked List: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

void deleteAtPosition(int position) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    Node* temp = head;
    int count = 1;

    if (position == 1) {
        if (head->next == head) {
            free(head);
            head = NULL;
        } else {
            Node* last = head->prev;
            head = head->next;
            last->next = head;
            head->prev = last;
            free(temp);
        }
        printf("Node at position %d deleted.\n", position);
        return;
    }

    while (count < position && temp->next != head) {
        temp = temp->next;
        count++;
    }

    if (count != position) {
        printf("Invalid position!\n");
        return;
    }

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;

    if (temp == head->prev) {
        head->prev = temp->prev;
    }

    free(temp);
    printf("Node at position %d deleted.\n", position);
}

int main() {
    int choice, pos;

    while (1) {
        printf("\nMenu:\n1. Create\n2. Display\n3. Delete a node at given position\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                create();
                break;
            case 2:
                display();
                break;
            case 3:
                printf("Enter the position to delete: ");
                scanf("%d", &pos);
                deleteAtPosition(pos);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
