/*Write a ‘C’ program to create BST and display tree level wise.*/

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
    if (root == NULL) {
        return createNode(data);
    }

    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }

    return root;
}

void levelOrderTraversal(Node* root) {
    if (root == NULL) {
        printf("The tree is empty.\n");
        return;
    }

    Node* queue[50];
    int front = 0, rear = 0;
    queue[rear++] = root;

    printf("Level Order Traversal: ");
    while (front < rear) {
        Node* current = queue[front++];

        printf("%d ", current->data);

        if (current->left != NULL) {
            queue[rear++] = current->left;
        }
        if (current->right != NULL) {
            queue[rear++] = current->right;
        }
    }
    printf("\n");
}

int main() {
    Node* root = NULL;
    int choice, value;

    while (1) {
        printf("\nMenu:\n1. Insert Node\n2. Display Level-wise\n3. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                break;
            case 2:
                levelOrderTraversal(root);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
