#include<stdio.h>
#include<stdlib.h>


void push(int ele , int *top,int **stack,int *size);
void pop(int *top, int stack[]);
void display(int top , int stack[]);

void main() {

    int choice ,ele;
    int top =-1;
    int *stack = NULL; //Stack initialised to Dynmaic memory Allocation
    int size = 0;

    while(1) {
    printf("Enter the given options :\n 1. Push \n 2. Pop \n 3.Display \n 4. Exit \n");
    scanf("%d",&choice);

    switch(choice) {
        case 1:
                printf("Enter the elemen to be pushed into the stack \n");
                scanf("%d",&ele);
                push(ele,&top,&stack,&size);
                            
            break;
        case 2 : if(top == -1){
            printf("Stack is underflow \n");
            }
            else {
                pop(&top,stack);
                
            }
            break;
        case 3 : if(top == -1){
            printf("Stack is underflow \n");
        }
        else {
            display(top,stack);
            
        }
        break;
        case 4 :
            free(stack);
            stack = NULL;
            exit(0);
            
    
    }
    }
}


void push(int ele , int *top , int **stack, int *size){
    if( *top == *size-1){
        *size = (*size == 0) ? 1 : (*size) *2; 
        *stack = realloc(*stack,(*size)*sizeof(int));
        if(stack == NULL){
            printf("Memory Allocation failed \n");
            exit(1);
        }
    }
    (*stack)[++(*top)] = ele;
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
    
}