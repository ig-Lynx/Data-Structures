#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int rows;
    int col;
    int value;
    struct node *next;
}NODE;

NODE *head = NULL;

NODE *get_Node(int rows, int col , int value){
    NODE *newNode = (NODE*)malloc(sizeof(NODE));
    newNode->col = col;
    newNode->rows = rows;
    newNode->value= value;
    newNode->next = NULL;
    

    return newNode;
}

NODE *insert(NODE *head,int rows , int col, int value){
    NODE *newNode = get_Node(rows,col,value); // creating a new newNode using a function instead of inlcuding it here 

    if( head == NULL)
        head = newNode;
    
    else{
        NODE *temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
    }
    return head;
}  


void display(NODE *head){
    NODE *temp = head;
    printf("Row\tCol\tValue\n");
    while(temp != NULL){
        printf("%d\t%d\t%d\n",temp->rows,temp->col,temp->value);
        temp = temp->next;
    }
}


void free_list(NODE *head){
    NODE *temp = head;
    while(head != NULL){
        temp = head;
        head = head->next;
        free(temp);
    }
}

void main() {
    int rows,col;
    int value;

    printf("Enter the number of rows & columns in the matrix :");
    scanf("%d  %d",&rows,&col);

    printf("Enter the elements of the matrix :\n ");
    for(int i = 0 ; i < rows ; i++){
        for(int j = 0 ; j < col; j++){
            scanf("%d",&value);

            if(value != 0){
                head = insert(head,i,j,value); // here we need to pass the vlaue of current row & col
                // also as head is global we need to keep updating head value else if you declare local then use the double pointer
            }
        }
    }

    display(head);

    free_list(head);

}