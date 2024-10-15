//Q.2) Write a C program to find intersection of two linked list.

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createList() {
    Node *head = NULL, *newNode, *last = NULL;
    int n, data;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        newNode = (Node *)malloc(sizeof(Node));
        if (!newNode) {
            printf("Memory allocation failed.\n");
            return head;
        }
        printf("Enter data for node %d: ", i);
        scanf("%d", &data);
        newNode->data = data;
        newNode->next = NULL;

        if (!head) head = newNode;
        else last->next = newNode;
        last = newNode;
    }
    return head;
}

void findIntersection(Node* list1, Node* list2) {
    Node* temp1 = list1;
    Node* temp2;
    int found = 0;

    printf("Intersection: ");
    while (temp1) {
        temp2 = list2;
        while (temp2) {
            if (temp1->data == temp2->data) {
                printf("%d ", temp1->data);
                found = 1;
                break;
            }
            temp2 = temp2->next;
        }
        temp1 = temp1->next;
    }
    if (!found) printf("No intersection found.");
    printf("\n");
}

void displayList(Node* head) {
    while (head) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    Node* list1 = NULL;
    Node* list2 = NULL;

    printf("Create the first linked list:\n");
    list1 = createList();
    printf("Create the second linked list:\n");
    list2 = createList();

    printf("List 1: ");
    displayList(list1);
    printf("List 2: ");
    displayList(list2);

    findIntersection(list1, list2);

    return 0;
}
