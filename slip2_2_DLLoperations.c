/*Q.2) Write a C menu driven program to implement doubly linked list of integers with following Operations: (20)
● Create
● Delete
● Insert
● Display*/

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

    for (count = 1; count <= n; count++) 
    {
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

Node* insert(Node* head) 
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    
    printf("Enter data for new node: ");
    scanf("%d", &newNode->info);
    newNode->next = NULL;
    newNode->prev = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }

    return head;
}

Node* deleteNode(Node* head, int value) {
    Node* temp = head;

    while (temp != NULL && temp->info != value) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Value not found in the list.\n");
        return head;
    }

    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    } else {
        head = temp->next;
    }

    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }

    free(temp);
    return head;
}

int main() {
    Node* head = NULL;
    int c, value;

    while (1) {
        printf("\nDoubly Linked List Operations:\n1. Create List\n2. Display List\n3. Insert Node at End\n4. Delete Node by Value\n5. Exit\nEnter your choice: ");
        scanf("%d", &c);

        switch (c) {
            case 1:
                head = create();
                break;

            case 2:
                display(head);
                break;

            case 3:
                head = insert(head);
                printf("Node added to the end\n");
                break;

            case 4:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                head = deleteNode(head, value);
                printf("Node with value %d deleted\n", value);
                break;

            case 5:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
