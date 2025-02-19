// Lab Program 1

#include<stdio.h>
#include<stdlib.h>
# define SIZE 20

void push(int ele , int *top,int stack[]);
void pop(int *top, int stack[]);
void display(int top , int stack[]);

void main() {

    int choice ,ele;
    int top =-1;
    int stack[SIZE]; //defined the array of size 20 

    while(1) {
    printf("Enter the given options :\n 1. Push \n 2. Pop \n 3.Display \n 4. Exit \n");
    scanf("%d",&choice);

    switch(choice) {

        case 1 : if(top == SIZE-1){
            printf("Stack is overflow \n");
            }
            else {
                printf("Enter the element to be pushed into the stack \n");
                scanf("%d",&ele);
                push(ele,&top,stack);
                
            }
            break;
        case 2 : if(top == -1){
            printf("Stack is underflow \n");
            }
            else {
                pop(&top,stack);
                
            }
            break;
        case 3 : if(top == -1){
            printf("Stack is Empty \n");
        }
        else {
            display(top,stack);
            
        }
        break;
        case 4 :
            exit(0);
            
    
    }
    }
}


void push(int ele , int *top , int stack[]){
    stack[++(*top)] = ele;
}

void pop(int *top , int stack[]){
    printf("Element to be deleted is  : %d  \n", stack[(*top)--]);
    //(*top)--;
}

void display(int top , int stack[]){
    int i;
    printf("The elements of the Stack are : ");
    for(i = top;i>=0 ; i--){
        printf("%d \t ",stack[i]);
        
    }
    printf("\n");
    printf("\n");
}