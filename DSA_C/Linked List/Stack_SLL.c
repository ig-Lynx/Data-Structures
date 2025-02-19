#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *link;
};

struct node *top = NULL; // globally declared top so it is accessible everywhere

// Function to push an element onto the stack
void push() {
    int value;
    printf("Enter the data value: ");
    scanf("%d", &value);
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL) {
        printf("Heap overflow\n");
        exit(1);
    }
    temp->data = value;
    temp->link = top;
    top = temp;
    printf("%d pushed to stack\n", value);
}

// Function to pop an element from the stack
void pop() {
    if (top == NULL) {
        printf("Stack underflow\n");
        return;
    }
    struct node *temp = top;
    top = top->link;
    printf("%d popped from stack\n", temp->data);
    free(temp);
}

// Function to display the stack
void display() {
    if (top == NULL) {
        printf("Stack is empty\n");
        return;
    }
    struct node *temp = top;
    printf("Stack elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->link;
    }
    printf("\n");
}

// Function to free the entire stack
void free_stack() {
    struct node *temp;
    while (top != NULL) {
        temp = top;
        top = top->link;
        free(temp);
    }
}

void main() {
    int choice;
    
    while (1) {
        printf("Operations available on stack are:\n");
        printf("1. Push\t2. Pop\t3. Display\t4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                free_stack();
                exit(0);
            default:
                printf("No operation found\n");
        }
    }
}
