//Write a C program to find the length of singly linked list
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
    int n, count;

    printf("**** NODES CREATION **** \n");
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    for (count = 1; count <= n; count++) {
        newNode = (Node*)malloc(sizeof(Node));
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

int displayAndCount(Node* head) {
    int count = 0;
    if (head == NULL) {
        printf("The list is empty.\n");
        return count;
    }
    printf("Singly Linked List: ");
    Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->info);
        count++;
        temp = temp->next;
    }
    printf("NULL\n");
    return count;
}

int main() {
    Node* head = create();
    
    int length = displayAndCount(head);
    printf("Length of the linked list: %d\n", length);

    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
