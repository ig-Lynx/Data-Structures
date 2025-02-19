// Lab program 2

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> // for functions like isalpha() and isdigit()
#include <string.h>

#define MAX 100 // defining the max constant

char stack[MAX]; // declaring the stack of size MAX 
int top = -1; // initializing the top variable to -1

void push(char x); // declaring the push function 
char pop(); // function to pop the elements of the stack 
void InfixToPostfix(char infix[]); // function to convert from infix to postfix
int precedence(char x); // function to check the precedence of the current operator with the , operator present in the top of the stack 

int main() {
    char infix[MAX];

    printf("Enter the infix expression: \n"); 
    scanf("%s", infix);

    // calling the infix to postfix function
    InfixToPostfix( infix);
    return 0;
}

void push(char x) {
    if (top == MAX - 1) {
        printf("Stack overflow\n");
        return;
    }
    stack[++top] = x;
}

char pop() {
    if (top == -1) {
        printf("Stack underflow\n");
        return '\0'; 
    }
    return stack[top--];
}

int precedence(char x) {
    switch (x) {
        case '+': 
        case '-': return 1;
        case '/':
        case '*': return 2; // modulo also has the same number as divide and multiplication 
        case '^': return 3;
        default: return 0;
    }
}

void InfixToPostfix(char infix[]) {
    int i = 0, j = 0;
    char postfix[MAX]; // to store the postfix expression
    char x, token;

    // need to create a loop which runs throughout the infix expression
    while (infix[i] != '\0') {
        token = infix[i];

        // if token is an operand, directly add it to the postfix expression 
        if (isalpha(token) || isdigit(token)) {
            postfix[j++] = token;
        }

        // if token is '('
        else if (token == '(') {
            push(token);
        }

        // if token is ')', then pop all the operators until we reach '('
        else if (token == ')') {
            while ((x = pop()) != '(') {
                //to check the mismatched Paranthesis not in college code but good to have stuff as it avoids the mismatching :)
                /* if (x == '\0') { // In case of underflow
                    printf("Error: Mismatched parentheses\n");
                    return;
                }
                */
                postfix[j++] = x;
            }
        }

        // if token is an operator
        else {
            while (top != -1 && precedence(stack[top]) >= precedence(token)) {
                postfix[j++] = pop();
            }
            push(token);
        }
        i++;
    }

    // pop all the remaining operators from the stack
    while (top != -1) {
        x = pop();
        // if (x == '(' || x == ')') {
        //     printf("Error: Mismatched parentheses\n");
        //     return;
        // }
        postfix[j++] = x;
    }
    postfix[j] = '\0'; // null terminate the postfix expression

    printf("Postfix expression is: %s\n", postfix);
}
 