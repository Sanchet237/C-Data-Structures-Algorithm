/*Q.2) Write a menu driven program using C for implementation of singly linked list. Menu should have the following options – (20)
1. Create.
2. Display.
3. Search specific element in list and display appropriate Message.
4. Delete specific element*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int info;
    struct Node* next;
} Node;

Node* create() {
    Node* head = NULL, *last = NULL;
    int n;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        Node* newNode = (Node*)malloc(sizeof(Node));
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &newNode->info);
        newNode->next = NULL;

        if (!head) head = newNode;
        else last->next = newNode;
        last = newNode;
    }

    return head;
}

void display(Node* head) {
    if (!head) {
        printf("The list is empty.\n");
        return;
    }
    printf("Linked list: ");
    for (Node* temp = head; temp; temp = temp->next) {
        printf("%d -> ", temp->info);
    }
    printf("NULL\n");
}

Node* search(Node* head, int key) {
    while (head) {
        if (head->info == key) return head;
        head = head->next;
    }
    return NULL;
}

Node* deleteNode(Node* head, int key) {
    Node *temp = head, *prev = NULL;

    if (temp && temp->info == key) {
        head = temp->next;
        free(temp);
        return head;
    }

    while (temp && temp->info != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp) {
        prev->next = temp->next;
        free(temp);
    } else {
        printf("Element %d not found in the list.\n", key);
    }

    return head;
}

int main() {
    Node* head = NULL;
    int choice, element;

    do {
        printf("\nMenu:\n1. Create\n2. Display\n3. Search Element\n4. Delete Element\n5. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: head = create(); break;
            case 2: display(head); break;
            case 3:
                printf("Enter element to search: ");
                scanf("%d", &element);
                if (search(head, element)) {
                    printf("Element %d found in the list.\n", element);
                } else {
                    printf("Element %d not found in the list.\n", element);
                }
                break;
            case 4:
                printf("Enter element to delete: ");
                scanf("%d", &element);
                head = deleteNode(head, element);
                break;
            case 5: printf("Exiting program.\n"); break;
            default: printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}
