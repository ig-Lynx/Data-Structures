// circular linked list using single linked list

#include<stdio.h>
#include<stdlib.h>

//structure definition 
struct node {
    int data;
    struct node *link ; // self referential structure
};

struct node *tail = NULL; // we use tail so that updation becomes easy else if we use head then evertime we need to iterate

// insertion when the list is empty
struct node *add_to_empty(struct node *tail){
    int data;
    printf("Enter the data :");
    scanf("%d",&data);

    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data ; 
    temp->link = temp;

    tail = temp;

    tail = temp;
    return tail;
}

//insertion at the begining function 
struct node *insert_at_beginning(struct node *tail){
    if(tail == NULL){
        return add_to_empty(tail);
    }
    int value;
    printf("Enter the data :");
    scanf("%d",&value);

    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = value;
    temp->link = tail->link;
    tail->link = temp;

    return tail;    
}

// insertion at the end of linked list
struct node *add_to_end(struct node *tail) {
    if (tail == NULL) {
        return add_to_empty(tail);
    }
    int value;
    printf("Enter the value: ");
    scanf("%d", &value);
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = value;
    temp->link = tail->link; // New node points to the first node
    tail->link = temp; // Old tail points to the new node
    tail = temp; // Update tail to the new node

    return tail;
}

// insertion between node 
struct node *add_after_pos(struct node *tail){
    if(tail == NULL){
        return add_to_empty(tail);
    }
    int value , pos ;
    printf("Enter the value & Position to be inserted :");
    scanf("%d %d" ,&value,&pos);
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = value;
    temp->link = NULL;
    struct node *p = tail->link;
    while(pos != 1){
        p = p->link;
        pos--;
    }
    
    temp->link = p->link;
    p->link = temp;

    if(p == tail){
        // return add_to_end(tail); cannot do this as this will again ask for value 
        tail = tail->link;
    }

    return tail;
}

// deletion of first node 
struct node *delete_begining(struct node *tail){
    if(tail == NULL){
        printf("Circular Linked List is Empty \n");
        return tail;
    }
    else if(tail->link == NULL){
        free(tail);
        tail = NULL;
        return tail;
    }
    else {
        struct node *p = tail->link;
        tail->link = p->link;
        free(p);
        p = NULL;
    }

    return tail;
}


// deletion from end 
struct node *delete_end(struct node *tail){
    if(tail == NULL){
        printf("Circular LInked List is empty \n");
        return tail;
    }
    else if(tail->link == tail){
        free(tail);
        tail = NULL;
        return tail;
    }
    else {
        struct node *p = tail->link;
        while(p->link != tail){
            p=p->link;
        }
        p->link = tail->link;
        free(tail);
        tail = p;
    }

    return tail;
}


// deletion before a position
struct node *delete_at_pos(struct node *tail){
    if(tail == NULL){
        printf("Circular Linked list is empty \n");
        return tail;
    }
    else if (tail->link == tail){
        free(tail);
        tail = NULL;

        return tail;
    }
    else {
        int pos;
        printf("Enter the position : ");
        scanf("%d",&pos);

        struct node *p = tail->link;
        if(pos == 1){
            tail = delete_begining(tail);
        }
        while(pos > 2){
            p = p->link;
            pos --;
        }
        struct node *p2 = p->link;
        p->link = p2->link;

        if(p2 == tail){
            tail = p;
        }
        free(p2);
        p2 = NULL;
        /* this is using one variable only 

         p->link = p->link->link;        
         free(p->link);

         */

        
        return tail;        
    }
}





// counting number of node in Circular Linked list
struct node *counting_nodes(struct node *tail){
        int count = 0;

        struct node *p = tail->link;
        while(p != tail){ // can do using infinite while loop also 
            p = p->link;
            count++;
        }
        count ++; // aditionally incrementing so that we count the tail node also else it wont count the tail node 

    return tail;
}

// searching an element
int search_element(struct node *tail){
    int element ;
    int index = 0;

    printf("Enter the element to be searched");
    scanf("%d",&element);

    if(tail == NULL){
        return -2;
    }

    struct node *temp = tail->link;
    do{
        if(temp->data == element){
            return index;
        }
        temp = temp->link;
        index++;
    }while(temp != tail);

    return -1;
    
}




// function to traverse & print the value 
void traverse_print(struct node *tail) {
    if (tail == NULL) {
        printf("Circular Linked list is empty \n");
        return;
    }

    struct node *p = tail->link; // Start from the head node
    do {
        printf("%d ", p->data);
        p = p->link;
    } while (p != tail->link);
    printf("\n");
}

// free up the list 
struct node *free_list(struct node *tail) {
    if (tail == NULL) {
        return NULL;
    }

    struct node *p = tail->link; // Start from the head node
    struct node *temp;

    // Iterate through the list and free each node
    while (p != tail) {
        temp = p;
        p = p->link;
        free(temp);
    }

    // Free the tail node
    free(tail);
    tail = NULL;
}

void main(){
  int choice;
  struct node *tail = NULL;
  while(1){
    printf("\nOperations available on Circular Linked List are : \n");
    printf("1.Add to empty\n2.Add to beginning\n3.Add to end\n4.Add after position\n5.Delete from beginning\n6.Delete from end\n7.Delete at position\n8.Counting nodes\n9.Search element\n10.Traverse and print\n11.Free list\n12.Exit\n");
    printf("Enter your choice : ");
    scanf("%d",&choice);
    switch(choice){
      case 1:
        tail = add_to_empty(tail);
        break;
      case 2:
        tail = insert_at_beginning(tail);
        break;
      case 3:
        tail = add_to_end(tail);
        break;
      case 4:
        tail = add_after_pos(tail);
        break;
      case 5:
        tail = delete_begining(tail);
        break;
      case 6:
        tail = delete_end(tail);
        break;
      case 7 :
        tail = delete_at_pos(tail);
        break;
      case 8:
        tail = counting_nodes(tail);
        break;
      case 9:
        search_element(tail);
        break;
      case 10:
        traverse_print(tail);
        break;
      case 11:
        tail = free_list(tail);
        break;
      case 12 :
        tail = free_list(tail);
        exit(0);
      default :
        printf("INvalid Operation \n");      
    }
  }
}
