// this is with ascending order priority 
// for dscending order priority ( change the greater than sign to less than sign... shown here (priority[i] < prio))


#include<stdio.h>
#include<stdlib.h>
#define MAX 5

int queue[MAX]; // array to hold the elements
int priority[MAX]; // array to store the priority of the corresponding elements

int front = -1;
int rear = -1;

// Function to check if the queue if full 
int isfull() {
    return( front == MAX -1);
}

// Function to check if queue is empty 
int isemtpy(){
    return( front == -1);
}

// enqueue operation 

void enqueue(int value , int prio){
    if (isfull()){
        printf("Priority Queue is full \n");
    }
    else {
        if(isemtpy()){
            front = rear = 0;
            queue[rear] = value;
            priority[rear] = prio;
        }
        else {
            // shift  elements to make room for the higher priority queue elements
            int i = rear;
            while( i >= front && priority[i] > prio){ 
                queue[i+1] = queue[i];
                priority[i+1] = priority[i];
                i--;
            }
            queue[i+1] = value;
            priority[i+1] = prio;
            rear++;

        }
        printf("Inserted  %d with priority  %d \n", value , prio);
    }
}

int dequeue(){
    if(isemtpy()){
        printf("Priority Queue is empty \n");
    }
    else {
        int value = queue[front];
        front++;
        if(front > rear){
            front = rear = -1;
        }
        return value;
    }
    
}

void display(){
    if(isemtpy()){
        printf("Priority Queue is empty \n");
    }
    else{
        printf("Priority Queue elements are : \n");
        for( int i = front ; i<= rear ; i++){
            printf("Value : %d , priority : %d \n", queue[i],priority[i]);
        }
        printf("\n");
    }
}



int main() {
    int choice , value , prio;

    while(1){
        printf(" \n Menu Card for priority Queue \n 1. Enqueue \t 2. Dequeue \t 3. Display \t 4. Exit \n");
        printf("Enter your Choice :");
        scanf("%d",&choice);



        switch(choice){
            case 1 : 
                printf("Enter the value & priority to be entered :");
                scanf("%d %d",&value, &prio);
                enqueue(value, prio);
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
