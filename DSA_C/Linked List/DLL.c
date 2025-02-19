// double linked list and its operations
// this can traverse in front direction as well as in the backward direction also 

// including the necessaru header files
#include<stdio.h>
#include<stdlib.h>

// defining a self referential structure or creating a node
struct node {
    struct node *prev;
    int data;
    struct node *next;
};

// declaring the head as gloabal as it would be accessible throught the code 
struct node *head = NULL;

struct node *add_to_emtpy(struct node *head){
    if(head == NULL){
    int value;
    printf("Enter the value of the data to be added to an emtpy Linked list :");
    scanf("%d",&value);

    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp ->prev = NULL;
    temp->data = value;
    temp->next = NULL;

    head = temp;
    }
    else{
        printf("Linked is not emtpy !!! \n");
    }
    return head;
}

struct node *add_to_beg(struct node *head){
    if(head == NULL){
        printf("Linked list is emtpy \n");
        return(add_to_emtpy(head));
    }
    int value;
    printf("Enter the value of the data :");
    scanf("%d",&value);

    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->prev = NULL;
    temp->data = value;
    temp->next = NULL;

    temp->next = head;
    head->prev = temp;

    head = temp;
    return head;
}


struct node *add_to_end(struct node *head){
    if(head == NULL){
        printf("linked list is empty \n");
        return(add_to_emtpy(head));
    }

    int value;
    printf("Enter the value of the data :");
    scanf("%d",&value);

    // creating a new node to add the current linked list
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->prev = NULL;
    temp->data = value;
    temp->next = NULL;

    // need to traverse through the linked list to reach till the end of the linked list ( using while loop)
    struct node *ptr = head; // decalring another pointer to traverse through the linked list
    while(ptr->next != NULL){ 
        ptr = ptr->next;
    }

    // updating the linking field of the node
    ptr->next = temp;
    temp->prev = ptr;

    return head;
}

// adding at a position
struct node *add_after_pos(struct node *head){
    if(head == NULL){
        printf("Linked list is empty \n");
        return add_to_emtpy(head);
    }
    int value , pos ;
    printf("Enter the position :");
    scanf("%d",&pos);    

    struct node *ptr = head ; // basically used to navigate till that position 
    while( pos != 1){
        ptr = ptr->next;
        pos--;
    }

    if(ptr->next == NULL){
        return add_to_end(head);
    }

    printf("Enter the value :");
    scanf("%d",&value);

    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->prev = NULL;
    temp->data = value;
    temp->next = NULL;
    

    temp->next = ptr->next;
    temp->prev = ptr;
    ptr->next->prev = temp;
    ptr->next = temp;

    return head;
}

// insertion before a postion
struct node *add_before_pos(struct node *head) {
    if (head == NULL) {
        printf("Linked list is empty \n");
        return add_to_emtpy(head);
    }
    int value, pos;
    printf("Enter the value and the position: ");
    scanf("%d %d", &value, &pos);

    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->prev = NULL;
    temp->data = value;
    temp->next = NULL;

    if (pos == 1) {
        // Insert at the beginning
        temp->next = head;
        head->prev = temp;
        head = temp;
        return head;
    }

    struct node *ptr = head; // used to navigate to the position before the specified position
    while (pos > 2) {
        ptr = ptr->next;
        pos--;
    }

    temp->next = ptr->next;
    temp->prev = ptr;
    if (ptr->next != NULL) {
        ptr->next->prev = temp;
    }
    ptr->next = temp;

    return head;
}


// deletion from begining
struct node *delete_beg(struct node *head){
    if(head == NULL){
        printf("Linked list is already empty \n");
        return head;
    }
    else {
    struct node *temp = head;
    head = head->next;
    free(temp);
    temp = NULL; 
    }
    return head ;
}

// deletion from end
struct node *delete_end(struct node *head){
    if(head == NULL){
        printf("linked list is already empty \n");
        return head;
    }
    else if(head->next == NULL){
        free(head);
        head = NULL ;
    }
    else {
        struct node *current = head;
        struct node *previous = NULL;;

        while(current->next != NULL){
            previous = current;
            current = current->next;
        }
        previous->next = NULL;
        free(current);
        current = NULL;
    }
    return head;

}

// deletion of end using one pointer only 
struct node *deletion_from_end_one(struct node *head){
    if(head == NULL){
        printf("Link list is already emtpy\n");
        return head;
    }
    else if(head->next == NULL){
        free(head);
        head = NULL;
    }
    else {
        struct node *current = head;

        while(current->next->next != NULL){
            current = current->next;
        }
        free(current->next);
        current->next = NULL;
    }

    return head;
}

// deleting a node from a given position
struct node *delete_pos(struct node *head){
    struct node *current = head;
    struct node *previous = NULL;
    int pos;
    printf("Enter the position from which you want to delete :");
    scanf("%d",&pos);
    if(head == NULL){
        printf("Linked list is empty \n");
        return head;
    }
    else if(pos ==1){
        head = current->next;
        free(current);
        current = NULL;
    }
    else {
        while(pos != 1){
            previous = current;
            current = current->next;
            pos--;
        }
        previous->next = current->next;
        current->next->prev = previous;
        free(current);
        current = NULL;
    }
    return head;
}

// deleting entire list 
struct node *delete_list(struct node *head){
    struct node *temp = head;
    while(head != NULL){
        temp = head;
        free(temp);
        head = head->next;
    }
    return head;
}

struct node *reverse_list(struct node *head){
    struct node *ptr1 = head;
    struct node *ptr2 = ptr1->next;

    ptr1->next = NULL;
    ptr1->prev = ptr2;

    while(ptr2 != NULL){
        ptr2->prev = ptr2->next;
        ptr2->next = ptr1;
        ptr1 = ptr2;
        ptr2 = ptr2->prev;
    }

    head = ptr1;

    printf("List Reversed \n");
    return head;

} 

void free_list(struct node *head){
    struct node *temp = head;
    while(head != NULL){
        temp = head;
        free(temp);
        head= head->next;
    }
    
}




// display function
void display(struct node *head){
    if (head == NULL){
        printf("the double linked list is empty \n");
        return;
    }
    else{
        struct node *ptr = head;
        printf("Element of the Linked list are :");
        while(ptr != NULL){
            printf("%d \t",ptr->data);
            ptr = ptr->next;
        }
    }
    printf("\n");
    printf("\n");
}

// to create an entire list at once
struct node *create_list(struct node *head){
    int data, n ,i;
    printf("Enter the number of node you want to create : ");
    scanf("%d",&n);
    if(n == 0){
        return head;
    }
    else if(head == NULL){
        // creating the first node 
        head = add_to_emtpy(head);

        // now need to use loop to create other nodes becasue the first node is created using the add_to_empty function 
        for(i=1;i<n;i++){ // here used less than so using it as n else if using <= then it should be n-1 
            head= add_to_end(head);
        }
    }
    else {
        // here  already the first node is created so we directly start appending the nodes to the end
        for(i=1;i<=n;i++){
            head = add_to_end(head);
        }
    }

    return head;
}



void main() {
    int choice ;

    while(1){
        printf("\nDouble linked list Menu \n");
        printf("0.Create an Entire list\n1.Add to empty\n2.Add to begining\n3.Add to end\n4.Add after pos\n5.Add before position\n6.Delete from Begining\n7.Delete from End\n8.Delete from End(one)\n9.Delete from position\n10.Delete List\n11.Reverse List\n12.Display\n13.Exit\n");
        printf("Enter you choice :");
        scanf("%d",&choice);
        switch(choice){
            case 0 :
                head = create_list(head);
                break;
            case 1: 
                head = add_to_emtpy(head);
                break;
            case 2:
                head = add_to_beg(head);
                break;
            case 3:
                head = add_to_end(head);
                break;
            case 4:
                head = add_after_pos(head);
                break;
            case 5:
                head = add_before_pos(head);
                break;
            case 6:
                head = delete_beg(head);
                break;
            case 7 :
                head = delete_end(head);
                break;
            case 8 :
                head = deletion_from_end_one(head);
                break;
            case 9 :
                head = delete_pos(head);
                break;
            case 10 :
                head = delete_list(head);
                break;
            case 11 :
                head = reverse_list(head);
                break;
            case 12 :
                display(head);
                break;
            case 13 :
                free_list(head);
                exit(0);
            default :
                printf("Enter a valid choice \n");
        }
    }
}



