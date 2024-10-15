//Q.1) Write a C program to create and display singly Linked List. (10)

#include <stdio.h>
#include <stdlib.h>

typedef struct Node 
{
    int info;
    struct Node* next;
} Node;

Node* create() 
{
    Node* head = NULL;
    Node* newNode;
    Node* last = NULL;
    int n, count;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    for (count = 1; count <= n; count++)
    {
        newNode = (Node*)malloc(sizeof(Node));
        if (newNode == NULL) {
            printf("Memory allocation failed.\n");
            return head;
        }
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

void display(Node* head) 
{
    if (head == NULL)
    {
        printf("The list is empty.\n");
        return;
    }
    printf("Singly Linked list: ");
    Node* temp = head;
    while (temp != NULL) 
    {
        printf("%d -> ", temp->info);
        temp = temp->next;
    }
    printf("NULL\n");
}

void freeList(Node* head) 
{
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() 
{
    Node* head = create();

    printf("Singly Linked List: ");
    display(head);

    freeList(head);

    return 0;
}

