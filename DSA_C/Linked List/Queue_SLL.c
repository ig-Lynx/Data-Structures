#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *link;
};

struct node *front = NULL; // globally declared front so it is accessible everywhere
struct node *rear = NULL;  // globally declared rear so it is accessible everywhere

// Function to add an element to the queue
void enqueue() {
    int value;
    printf("Enter the data value: ");
    scanf("%d", &value);
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL) {
        printf("Heap overflow\n");
        exit(1);
    }
    temp->data = value;
    temp->link = NULL;
    if (rear == NULL) {
        front = rear = temp;
    } else {
        rear->link = temp;
        rear = temp;
    }
    printf("%d enqueued to queue\n", value);
}

// Function to remove an element from the queue
void dequeue() {
    if (front == NULL) {
        printf("Queue underflow\n");
        return;
    }
    struct node *temp = front;
    front = front->link;
    if (front == NULL) {
        rear = NULL;
    }
    printf("%d dequeued from queue\n", temp->data);
    free(temp);
}

// Function to display the queue
void display() {
    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }
    struct node *temp = front;
    printf("Queue elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->link;
    }
    printf("\n");
} 

// Function to free the entire queue
void free_queue() {
    struct node *temp;
    while (front != NULL) {
        temp = front;
        front = front->link;
        free(temp);
    }
    rear = NULL;
}

void main() {
    int choice;
    
    while (1) {
        printf("Operations available on queue are:\n");
        printf("1. Enqueue\t2. Dequeue\t3. Display\t4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                free_queue();
                exit(0);
            default:
                printf("No operation found\n");
        }
    }
}
