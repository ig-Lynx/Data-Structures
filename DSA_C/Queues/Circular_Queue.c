// Circular Queue
// Insertion done from rear and deletion using front ...
// can be reused the same memory by deleting some elements of the queue ( adv)
// drawback of simple queue is solved in this 

// Lab program 4

#include<stdio.h>
#define MAX 5

int Queue[MAX];
int front = -1 , rear = -1;

// Function to check if the Queue is full
int isFull(){
    return ( front == (rear + 1)% MAX);
}

// function to check if the Queue is empty 
int isEmpty(){
    return( front == -1);
}

// Enqueue Function 
void enqueue(int value){
    if(isFull()){
        printf("Queue is full \n");
        return ;
    }
    if(front == -1){
        front = 0;
    }

    rear = (rear + 1) % MAX ;
    Queue[rear] = value;
    printf("Instered element is %d",Queue[rear]);
}


// dequeue function

int dequeue(){
    if(isEmpty()){
        printf("Queue is Empty \n");
        return -1;
    }
    
    int element = Queue[front];
    if( front == rear){
        front = rear = -1; // reset the queue
    }
    else{
        front = (front + 1) % MAX;
    }

    printf("Deleted Element is %d",element);
    return element;
}

// Display Function
void display() {
    int i ;

    if(isEmpty()){
        printf("Queue is Empty \n");
        return ;
    }

    printf("Queue Elements are ");
    for(i= front ; i != rear ; i = (i+1)%MAX){
        printf("%d \t",Queue[i]);
    }
    printf("%d \t", Queue[i]); // this can be Queue[rear]

    printf("\n");
}


// main function 
int main() {
    int choice , value;

    while(1){
        printf(" \n Menu Card for Circular Queue \n 1. Enqueue \t 2. Dequeue \t 3. Display \t 4. Exit \n");
        printf("Enter your Choice :");
        scanf("%d",&choice);



        switch(choice){
            case 1 : 
                printf("Enter the value to be entered :");
                scanf("%d",&value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4: 
                return 0;

            default :
                printf("Invalid Statement \n");
        }
    }
    return 0;
}