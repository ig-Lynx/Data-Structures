#include <stdio.h>
#include <stdlib.h>

// Definition of the Node structure
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to perform inorder traversal
void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// Function to find the minimum value node in a tree
struct Node* findMin(struct Node* node) {
    struct Node* current = node;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

// Function to delete a node in a BST
struct Node* deleteNode(struct Node* root, int key) {
    if (root == NULL) return root;

    // Traverse the tree to find the node to be deleted
    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    } else {
        if( root->left == NULL && root->right == NULL){
            free(root);
            return root;
        }
        // Node with only one child or no child
        else if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        // Node with two children: Get the inorder successor (smallest in the right subtree)
        struct Node* temp = findMin(root->right);

        // Copy the inorder successor's content to this node
        root->data = temp->data;

        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

int main() {
    struct Node* root = createNode(50);
    root->left = createNode(30);
    root->right = createNode(70);
    root->left->left = createNode(20);
    root->left->right = createNode(40);
    root->right->left = createNode(60);
    root->right->right = createNode(80);

    printf("Inorder traversal of the given tree: ");
    inorderTraversal(root);
    printf("\n");

    printf("Delete 20\n");
    root = deleteNode(root, 20);
    printf("Inorder traversal of the modified tree: ");
    inorderTraversal(root);
    printf("\n");

    printf("Delete 30\n");
    root = deleteNode(root, 30);
    printf("Inorder traversal of the modified tree: ");
    inorderTraversal(root);
    printf("\n");

    printf("Delete 50\n");
    root = deleteNode(root, 50);
    printf("Inorder traversal of the modified tree: ");
    inorderTraversal(root);
    printf("\n");

    return 0;
}