// doing priority Queue with the help of structures 

#include<stdio.h>
#define MAX 5

struct item{
    int value;
    int priority;
};

struct item queue[MAX]; //creating an array of structures

int size =0 ; // current size of queue 

//  Function  to insert an element into priority queue 
void insert( int value , int prio){
    if(size == MAX){
        printf("Priority queue is full \n");
    }
    else{
        int i;

        for ( i = size -1 ; i >= 0 && queue[i].priority > prio ; i--){
            queue[i+1] = queue[i];
        }

        // insertion of the element 
        queue[i+1].value = value;
        queue[i+1].priority  = prio;
        size++;
        printf("Element inserted : %d , priority : %d \n", value , prio);
    }
}

// function to delete an element
int delete() {
    if(size == 0){
        printf("priority Queue is empty \n");
    }

    int value = queue[0].value;

    for(int i = 0 ; i < size -1 ; i++){
        queue[i] = queue[i+1];
    }
    size--;
    return value;
}

// display function

void display() {
    if( size == 0){
        printf("Priority Queue is empty \n");
    }
    else {
        printf("Elements of the priority  queue are : \n");
        for( int i = 0; i < size ; i++){
            printf("Value %d , priority : %d \n",queue[i].value , queue[i].priority);
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
                insert(value, prio);
                break;
            case 2:
                delete();
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