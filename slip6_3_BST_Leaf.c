/*Q.2) Write a C program to implement binary search tree of integers with following operations:
1. Add a function to insert a new element in the tree
2. Add a function to count non-leaf nodes.
3. Add a function to count leaf nodes.*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }
    return root;
}

int countLeafNodes(Node* root) {
    if (root == NULL) {
        return 0;
    }
    if (root->left == NULL && root->right == NULL) {
        return 1; // Leaf node
    }
    return countLeafNodes(root->left) + countLeafNodes(root->right);
}

int countNonLeafNodes(Node* root) {
    if (root == NULL || (root->left == NULL && root->right == NULL)) {
        return 0; // No non-leaf node here
    }
    return 1 + countNonLeafNodes(root->left) + countNonLeafNodes(root->right);
}

int main() {
    Node* root = NULL;
    int choice, value;

    while (1) {
        printf("\nMenu:\n"
               "1. Insert a new element\n"
               "2. Count Leaf Nodes\n"
               "3. Count Non-Leaf Nodes\n"
               "4. Exit\n"
               "Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                break;
            case 2:
                printf("Number of leaf nodes: %d\n", countLeafNodes(root));
                break;
            case 3:
                printf("Number of non-leaf nodes: %d\n", countNonLeafNodes(root));
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
