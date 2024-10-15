/*Write a C program to implement binary search tree of integers with following operations:
1. Inserting a new element
2. Searching an element
3. Creating a mirror of the tree.*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, int data) {
    if (root == NULL) return createNode(data);
    if (data < root->data) root->left = insert(root->left, data);
    else root->right = insert(root->right, data);
    return root;
}

Node* search(Node* root, int data) {
    if (root == NULL || root->data == data) return root;
    return (data < root->data) ? search(root->left, data) : search(root->right, data);
}

Node* mirror(Node* root) {
    if (root == NULL) return NULL;
    Node* newRoot = createNode(root->data);
    newRoot->left = mirror(root->right);
    newRoot->right = mirror(root->left);
    return newRoot;
}

void inorder(Node* root) {
    if (root) {
        inorder(root->left);
        printf("%d -> ", root->data);
        inorder(root->right);
    }
}

void freeTree(Node* root) {
    if (root) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main() {
    Node* root = NULL;
    int choice, data;

    while (1) {
        printf("\n1. Insert Element\n2. Search Element\n3. Create Mirror\n4. Inorder Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                root = insert(root, data);
                break;
            case 2:
                printf("Enter data to search: ");
                scanf("%d", &data);
                printf("Element %d %s in the tree.\n", data, search(root, data) ? "found" : "not found");
                break;
            case 3: {
                Node* mirroredRoot = mirror(root);
                printf("Inorder of mirrored tree: ");
                inorder(mirroredRoot);
                printf("NULL\n");
                freeTree(mirroredRoot);
                break;
            }
            case 4:
                printf("Inorder of original tree: ");
                inorder(root);
                printf("NULL\n");
                break;
            case 5:
                freeTree(root);
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
}
