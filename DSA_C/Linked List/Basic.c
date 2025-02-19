// Linked list basic implementation 

#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *link;
};

struct node *head = NULL;


void Count_no_of_nodes(struct node *head); // function decalaration to count the number of nodes
void print_data(struct node *head);



int  main() {
    head = (struct node *)malloc(sizeof(struct node)); // allocating memeory for the node 

    // assigning the values for the memmbers of the structure
    head->data = 45;
    head->link = NULL; 

    // now if we want to add another node and link it with the first node

    struct node *next = (struct node *)malloc(sizeof(struct node)); // allocated memeory for the new node 

    // assign values for the new node 
    next->data = 25;
    next->link = NULL;

    // giving connection from the previous node to to follow through the next node
    head->link = next;

    // again adding new node 
    struct node *next2 = (struct node *)malloc(sizeof(struct node));
    next2->data = 65;
    next2->link = NULL;

        // need to link the preivous node to the new node added 
        next->link = next2; // also be written in terms of head as ( head->link->link)

    
    Count_no_of_nodes(head);
    print_data(head);

    return 0;
}

// Traversing 
// function to count the number of nodes

void Count_no_of_nodes(struct node *head){
    struct node *ptr = head;
    int count = 0;

    if(head == NULL){
        printf("Linked list is empty");
    }
    
    while(ptr != NULL){
        count++;
        ptr = ptr->link;
    }
    printf("Number of nodes present are : %d \n",count);
}

void print_data(struct node *head){
    struct node *ptr = head;

    if(head == NULL){
        printf("Linked list is empty");
    }

    printf("Elements of the node are : \t");
    while(ptr != NULL){
        printf("%d \t",ptr->data);
        ptr = ptr->link ;
    }
    printf("\n");

}