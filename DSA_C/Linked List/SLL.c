// Single linked list 
// can traverse only in one direction 
// can go forword only and cannot come backwards 
// store data and link field ( link is of data type struct node)
// also we have used self refernetial structures to link one node to another node


#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *link;
};  
 
 struct node *head = NULL; // globally declared head  so it accessible everywhere 

// adding a new node when the list is empty( basically when HEAD == NULL)
struct node *add_to_emtpy(struct node *head){
    if(head == NULL){
        int value;
        printf("Enter the data value : ");
        scanf("%d",&value);
        struct node *temp = (struct node *)malloc(sizeof(struct node));
        temp->data = value;
        temp->link = NULL;
        head = temp;
    }
    else {
        printf("Linked LIst is not emtpy");
    }
    
    return head; 
}

// adding element at the beginning of the list
struct node  *add_to_beginning(struct node *head){
    int value;

    if(head == NULL){
        printf("Linked list is empty \n");
        return add_to_emtpy(head);  
    }
    
    printf("Enter the data :");
    scanf("%d",&value);
    
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = value;
    temp->link = NULL;

    temp->link = head;
    head = temp;
    return head;
}

// adding an element at the end of List
struct node *add_at_end(struct node *head){
    struct node *ptr;
    int value;
    if(head == NULL){
        printf("Linked list is empty \n");
        return add_to_emtpy(head);
    }

    printf("Enter the data :");
    scanf("%d",&value);
    ptr = head;

    struct node *temp = (struct node *)malloc(sizeof(struct node));

    temp->data = value;
    temp->link = NULL;

    while(ptr->link != NULL){
        ptr = ptr->link;
    }
    ptr->link = temp;
    return head;

}

// adding an element at a giving position
struct node *add_after_pos(struct node *head){
    int value , pos;
    printf("Enter the value of the data and the position : ");
    scanf("%d %d",&value, &pos);

    //create a new node
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = value;
    temp->link = NULL;

    struct node *ptr = head; // another pointer variabl to traverse throught the array 
    
    while(pos != 1){
        ptr = ptr->link;
        pos--;
    }
    
    temp->link = ptr->link;
    ptr->link = temp;

    return head;

}

// deleting a node from the first position
struct node *delete_begin(struct node *head){
    if(head == NULL){
        printf("The list is already empty \n");
        return head ;
    }
    else {
        struct node *temp = head;
        head = head->link;
        free(temp);
        return head;
    }
}

// deleting node from the last 
struct node *delete_end(struct node *head){
    if(head == NULL){
        printf("the list is already emtpy \n");
        return head;
    }
    else if(head->link == NULL){
        free(head);
        head = NULL;
    }
    else {
    struct node *current = head;
    struct node *previous = head;

    while( current->link != NULL){
        previous = current;
        current = current->link;
    }

    previous->link = NULL;
    free(current);
    current = NULL;
    }
    return head ;
}

// deleting the end using one pointer variable 
struct node *delete_end_one(struct node *head){
    if(head == NULL ){
        printf("The list is already empty \n");
        return head;
    }
    else if (head->link == NULL){
        free(head);
        head = NULL;
    }
    else {
        struct node *temp = head;

        while(temp->link->link != NULL){
            temp = temp->link;
        }
        free(temp->link);
        temp->link = NULL;        
    }
    return head;
}


// deleting a node from a given position
struct node *delete_pos(struct node *head){
    struct node *current = head;
    struct node *previous = NULL;
    int pos;
    printf("enter the postion from which nod has to be deleted :");
    scanf("%d",&pos);

    if(head == NULL){
        printf("The list is already emtpy \n");
        return head;
    }
    else if( pos == 1){
        head = current->link;
        free(current);
        current = NULL;
    }
    else {
        while(pos != 1){
            previous = current;
            current = current->link;
            pos--;
        }
        previous->link = current->link;
        free(current);
        current = NULL;
    }
    return head;
}

// deleteing the entire list
struct node *delete_entire(struct node *head){
    struct node *temp = head;
    while(temp != NULL){
        temp = temp->link;
        free(head);
        head = temp;
    }
    return head;
}



// printing the data memebers of the list
void print_data(struct node *head){
    

    if(head == NULL){
        printf("Linked list is empty \n");
        return;
    }

    struct node *ptr = head;
    printf("Elements of the node are : \t");
    while(ptr != NULL){
        printf("%d \t",ptr->data);
        ptr = ptr->link ;
    }
    printf("\n");

}

void free_list(struct node *head){
    struct node *temp;
    while(head != NULL){
        temp = head;
        head = head->link;
        free(temp);
    }
    
}


void main(){
    
    int choice;
    //struct node *head = NULL;
    
    while(1){
        printf("\n Operations available on linked list are : \n");
        printf("1.Add to empty\t2.Add to end\t3.Add to beginning\t 4.Add after position\t5.Delete begin\t6.Delete End\t7.Delete End1\t 8.Delete from pos\t\t 9.Delete List\t10.Display\t11.Exit\n");
        printf("Enter your choice :");
        scanf("%d",&choice);

        switch (choice){
            case 1:
                head = add_to_emtpy(head);
                break;
            case 2:
                head = add_at_end(head);
                break;
            case 3:
                head = add_to_beginning(head);
                break;
            case 4: 
                head = add_after_pos(head);
                break;
            case 5:
                head = delete_begin(head);
                break;
            case 6: 
                head = delete_end(head);
                break;
            case 7:
                head = delete_end_one(head);
                break;
            case 8 :
                head = delete_pos(head);
                break;
            case 9:
                head = delete_entire(head);
                break;
            case 10:
                print_data(head);
                break;
            case 11:
                free_list(head);
                exit(0);
            default : 
                printf("No operation found \n");
        }
    }
}
