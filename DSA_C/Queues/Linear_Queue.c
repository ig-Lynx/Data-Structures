// Linear Queue Code
// Insertion is done using rear and Deletion using front
// Drawback : cannot reutilise the space ....once allocated then again cannot be reallocated



#include<stdio.h>
#define SIZE 5

int queue[SIZE];
int front = -1 , rear = -1;

// Enqueue funtion
void enqueue(int value){
    // checking if the Queue is full
    if(rear == SIZE -1){ 
        printf("Queue is Full");
    } else {
        if(front == -1){ // alsp ensuring that front is not pointing to -1 when element is being added
            front = 0;
        }
        
        queue[++rear] = value ; // pushing the value to Queue 
        printf("%d enqueued to the Queue \n",value);
    }
}

// dequeue Function
void dequeue() {
    // checking two condtion if front is -1 or front greater than rear 
    if(front == -1 || front > rear){
        printf("Queue is empty \n");
    }else {
        printf("Element to be removed is : %d \n ",queue[front]);
        front++;
        if(front > rear){
            front = rear = -1;
        }
    }
}

void display() {
    int i;

    // checking if Queue is empty 
    if(front == -1){ 
        printf("Queue is empty \n");
    }else { // if not empty then we use the front pointer to navigate till rear
        printf("The elements of the Queue are :");
        for(i = front ; i <= rear ; i++){
        printf("%d \t",queue[i]);
        }
    }

    printf("\n");
}



// main function
int main() {
    int choice,value;

    while(1){ 
        printf("\n");
        printf(" \nMenu for the operations on the Linear Queue \n");
        printf(" 1. Enqueue \n");
        printf(" 2. Dequeue \n");
        printf(" 3. Display \n");
        printf(" 4. Exit \n ");
        printf("Enter your choice : ");
        scanf("%d", &choice);

        switch(choice){

            case 1 :
                printf("Enter the value of the element to be enqueued :");
                scanf("%d",&value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3 :
                display();
                break;
            case 4 : 
                return 0;
            default :
                printf("Invalid operator \n");
        }
    }

    return 0;
}
