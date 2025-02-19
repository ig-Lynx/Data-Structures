#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Function to create a new tree node
struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to check if two trees are equal
int isEqual(struct TreeNode* p, struct TreeNode* q) {
    if (p == NULL && q == NULL) {
        return 1;
    }
    if (p == NULL || q == NULL) {
        return 0;
    }
    return (p->val == q->val) && isEqual(p->left, q->left) && isEqual(p->right, q->right);
}

int main() {
    // Example usage
    struct TreeNode* root1 = newNode(1);
    root1->left = newNode(2);
    root1->right = newNode(3);

    struct TreeNode* root2 = newNode(1);
    root2->left = newNode(2);
    root2->right = newNode(3);

    if (isEqual(root1, root2)) {
        printf("The trees are equal.\n");
    } else {
        printf("The trees are not equal.\n");
    }

    return 0;
}