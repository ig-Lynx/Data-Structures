#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Function to create a new tree node
struct TreeNode* createNode(int val) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to merge two binary trees
struct TreeNode* mergeTrees(struct TreeNode* t1, struct TreeNode* t2) {
    if (t1 == NULL) return t2;
    if (t2 == NULL) return t1;
    
    t1->val += t2->val;
    t1->left = mergeTrees(t1->left, t2->left);
    t1->right = mergeTrees(t1->right, t2->right);
    
    return t1;
}

// Helper function to print the tree (in-order traversal)
void printTree(struct TreeNode* root) {
    if (root == NULL) return;
    printTree(root->left);
    printf("%d ", root->val);
    printTree(root->right);
}

int main() {
    // Create first tree
    struct TreeNode* t1 = createNode(1);
    t1->left = createNode(3);
    t1->right = createNode(2);
    t1->left->left = createNode(5);

    // Create second tree
    struct TreeNode* t2 = createNode(2);
    t2->left = createNode(1);
    t2->right = createNode(3);
    t2->left->right = createNode(4);
    t2->right->right = createNode(7);

    // Merge trees
    struct TreeNode* mergedTree = mergeTrees(t1, t2);

    // Print merged tree
    printf("Merged tree (in-order traversal): ");
    printTree(mergedTree);
    printf("\n");

    return 0;
}