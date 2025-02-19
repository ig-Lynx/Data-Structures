#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>  // Include math.h for pow function

// Define the structure for a tree node
typedef struct Node {
    char value;
    struct Node *left, *right;
} Node;

// Function to create a new tree node
Node* newNode(char value) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->value = value;
    node->left = node->right = NULL;
    return node;
}

// Recursive function to evaluate the expression tree
int evaluateExpressionTree(Node* root) {
    if (root == NULL) return 0;

    // If the node is a leaf node (operand), return its integer value
    if (root->left == NULL && root->right == NULL) {
        return root->value - '0';
    }

    // Evaluate left and right subtrees
    int leftValue = evaluateExpressionTree(root->left);
    int rightValue = evaluateExpressionTree(root->right);

    // Apply the operator at the current node
    switch (root->value) {
        case '+': return leftValue + rightValue;
        case '-': return leftValue - rightValue;
        case '*': return leftValue * rightValue;
        case '/': return leftValue / rightValue;
        case '^': return (int)pow(leftValue, rightValue);
        default: return 0;
    }
}

// Driver code
int main() {
    // Constructing a simple expression tree
    //        +
    //       / \
    //      *   5
    //     / \
    //    4   3
    Node* root = newNode('+');
    root->left = newNode('*');
    root->right = newNode('5');
    root->left->left = newNode('4');
    root->left->right = newNode('3');

    printf("The result of the expression tree is %d\n", evaluateExpressionTree(root));

    return 0;
}