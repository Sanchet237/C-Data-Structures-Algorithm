/*Q.2) Write a C program to construct a binary search tree and traverse using pre-order traversal.*/
#include <stdio.h>
#include <stdlib.h>

typedef struct NODE {
    int data;
    struct NODE* left;
    struct NODE* right;
} Node;

Node* create(Node* root) {
    int n, num;
    printf("How many nodes: ");
    scanf("%d", &n);
    
    printf("Enter all node values: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &num);
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->data = num;
        newNode->left = newNode->right = NULL;
        
        if (root == NULL) {
            root = newNode;
        } else {
            Node* temp = root;
            while (1) {
                if (num < temp->data) {
                    if (temp->left == NULL) {
                        temp->left = newNode;
                        break;
                    }
                    temp = temp->left;
                } else {
                    if (temp->right == NULL) {
                        temp->right = newNode;
                        break;
                    }
                    temp = temp->right;
                }
            }
        }
    }
    return root;
}

void preorder(Node* root) {
    if (root) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

int main() {
    Node* root = NULL;
    root = create(root);
    printf("Pre-order traversal:\n");
    preorder(root);
    return 0;
}
