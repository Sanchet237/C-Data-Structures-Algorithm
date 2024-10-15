/*Q.2) Write a C menu driven program to implement singly circular linked list of integers with Following operations: (20)
● Create
● Insert
● Delete
● Display*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int info;
    struct Node* next;
} Node;

Node* create() {
    Node* head = NULL;
    Node* newNode, *last = NULL;
    int n;

    printf("**** NODES CREATION ****\nEnter the number of nodes: ");
    scanf("%d", &n);

    for (int count = 1; count <= n; count++) {
        newNode = (Node*)malloc(sizeof(Node));
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
    if (last) last->next = head; 
    return head;
}

void display(Node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    Node* temp = head;
    printf("Singly Circular Linked List: ");
    do {
        printf("%d -> ", temp->info);
        temp = temp->next;
    } while (temp != head);
    printf("(head)\n");
}

void insert(Node* head, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->info = value;

    if (head == NULL) {
        newNode->next = newNode;
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }
}

void deleteNode(Node* head, int value) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    Node *current = head, *prev = NULL;

    do {
        if (current->info == value) {
            if (prev == NULL) {
                Node* last = head;
                while (last->next != head) {
                    last = last->next;
                }
                last->next = current->next;
                head = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            printf("Node with value %d deleted.\n", value);
            return;
        }
        prev = current;
        current = current->next;
    } while (current != head);
    printf("Value %d not found in the list.\n", value);
}

int main() {
    Node* head = NULL;
    int c, value;

    while (1) {
        printf("\n1. Create List\n2. Display List\n3. Insert Node\n4. Delete Node\n5. Exit\nEnter your choice: ");
        scanf("%d", &c);

        switch (c) {
            case 1: head = create(); break;
            case 2: display(head); break;
            case 3:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insert(head, value);
                break;
            case 4:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                deleteNode(head, value);
                break;
            case 5: return 0;
            default: printf("Invalid choice \n");
        }
    }
    return 0;
}
