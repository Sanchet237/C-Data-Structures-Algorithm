/*Q.2) Write a C program to create BST and implement following operations:
● Display in-order traversal
● To count leaf nodes
● To count total no of nodes*/

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
        return 1; 
    }
    return countLeafNodes(root->left) + countLeafNodes(root->right);
}

int countTotalNodes(Node* root) {
    if (root == NULL) {
        return 0;
    }
    return 1 + countTotalNodes(root->left) + countTotalNodes(root->right);
}

void inorderTraversal(Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

int main() {
    Node* root = NULL;
    int n, value;

    printf("Enter the number of elements to insert into the BST: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter value %d: ", i + 1);
        scanf("%d", &value);
        root = insert(root, value);
    }

    printf("\nIn-order traversal of the BST:\n");
    inorderTraversal(root);
    printf("\n");

    printf("Number of leaf nodes: %d\n", countLeafNodes(root));
    printf("Total number of nodes: %d\n", countTotalNodes(root));

    return 0;
}
