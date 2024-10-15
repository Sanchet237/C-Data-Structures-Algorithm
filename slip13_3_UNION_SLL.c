/*Q2. Write a C program to find union of two singly linked lists of integers.*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createList() {
    Node* head = NULL;
    Node* newNode;
    int n, data;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        newNode = (Node*)malloc(sizeof(Node));
        printf("Enter element %d: ", i + 1);
        scanf("%d", &data);
        newNode->data = data;
        newNode->next = head;
        head = newNode;
    }
    return head;
}

Node* findUnion(Node* list1, Node* list2) {
    Node* unionList = NULL;
    Node* temp;

    // Add elements from list1 to the union list
    while (list1) {
        temp = unionList;
        int isDuplicate = 0;

        while (temp) {
            if (temp->data == list1->data) {
                isDuplicate = 1;
                break;
            }
            temp = temp->next;
        }

        if (!isDuplicate) {
            Node* newNode = (Node*)malloc(sizeof(Node));
            newNode->data = list1->data;
            newNode->next = unionList;
            unionList = newNode;
        }
        list1 = list1->next;
    }

    // Add elements from list2 to the union list
    while (list2) {
        temp = unionList;
        int isDuplicate = 0;

        while (temp) {
            if (temp->data == list2->data) {
                isDuplicate = 1;
                break;
            }
            temp = temp->next;
        }

        if (!isDuplicate) {
            Node* newNode = (Node*)malloc(sizeof(Node));
            newNode->data = list2->data;
            newNode->next = unionList;
            unionList = newNode;
        }
        list2 = list2->next;
    }

    return unionList;
}

void displayList(Node* head) {
    if (!head) {
        printf("List is empty.\n");
        return;
    }
    printf("List elements: ");
    while (head) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void freeList(Node* head) {
    Node* temp;
    while (head) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    Node* list1 = NULL;
    Node* list2 = NULL;
    Node* unionList = NULL;

    printf("Create first linked list:\n");
    list1 = createList();

    printf("Create second linked list:\n");
    list2 = createList();

    unionList = findUnion(list1, list2);

    printf("Union of the two linked lists:\n");
    displayList(unionList);

    freeList(list1);
    freeList(list2);
    freeList(unionList);

    return 0;
}
