#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int coefficient;
    int exponent;
    struct node *next;
}NODE;

NODE *createNode(int coefficient , int exponent){
    NODE *newNode = (NODE *)malloc(sizeof(NODE));
    newNode->coefficient = coefficient;
    newNode->exponent = exponent;
    newNode->next = NULL;

    return newNode;
}

NODE *insert(NODE **poly , int coefficient , int exponent){
    NODE *newNode = createNode(coefficient ,exponent);

    if(*poly == NULL){
        *poly = newNode;
    }
    else {
        NODE *temp = *poly;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void display(NODE **poly){
    NODE *temp = *poly;
    while(temp != NULL){
        printf("%dx^%d", temp->coefficient,temp->exponent);
        if(temp->next != NULL){
            printf(" + ");
        }
        temp = temp->next;
    }
    printf("\n");
}


NODE *addPolys(NODE **poly1 , NODE **poly2){
    NODE *result = NULL;
    NODE *temp1 = *poly1;
    NODE *temp2 = *poly2;

    while(temp1 != NULL && temp2 != NULL){
        if(temp1->exponent == temp2->exponent){
            int sum = temp1->coefficient + temp2->coefficient;
            if( sum != 0)
                insert(&result,sum,temp1->exponent);
            temp1= temp1->next;
            temp2 = temp2->next;
        }
        else if (temp1->exponent > temp2->exponent){
            insert(&result,temp1->coefficient,temp1->exponent);
            temp1 = temp1->next;
        }
        else {
            insert(&result,temp2->coefficient,temp2->exponent);
            temp2 = temp2->next;
        }
        
    }
    while(temp1 != NULL){
            insert(&result,temp1->coefficient, temp1->exponent);
            temp1= temp1->next;
    }
    while(temp2 != NULL){
            insert(&result,temp2->coefficient,temp2->exponent);
            temp2= temp2->next;
    }
    return result;
}

void main() {
    NODE *poly1 = NULL;
    NODE *poly2 = NULL;

    printf("Enter the terms of the first polynomial :\n");
    insert(&poly1,5,3);
    insert(&poly1,4,2);
    insert(&poly1,2,0);

    printf("Enter the terms of the second polynomial : \n");
    insert(&poly2,7,4);
    insert(&poly2,1,3);
    insert(&poly2,2,1);

    // display of 1st poly
    printf("First polynomial :");
    display(&poly1);

    // dsiplay of 2nd poly
    printf("Seocnd Polynomial :");
    display(&poly2);


    NODE *ans = addPolys(&poly1,&poly2);

    printf("The resultent polynomial is : ");
    display(&ans);

}