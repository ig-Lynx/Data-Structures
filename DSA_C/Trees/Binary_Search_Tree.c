// binary serach program (LAB program 8)

#include<stdio.h>
#include<stdlib.h>

struct node {
    int info;
    struct node *llink;
    struct node *rlink;
};

typedef struct node TNODE;

TNODE *get_node(){
    TNODE *temp = (TNODE *)malloc(sizeof(TNODE));
    temp->llink = temp->rlink = NULL;
    return temp;
}

TNODE *insert(TNODE *root, int ele){
    if(root == NULL){
        TNODE *temp;
        temp = get_node();
        temp->info = ele;
        return temp;
    }
    if(ele > root->info)
        root->rlink = insert(root->rlink,ele);
    else 
        root->llink = insert(root->llink,ele);

    return root;
}

void PreOrder(TNODE *root){
    if(root != NULL ){
        printf("%d\t ",root->info);
        PreOrder(root->llink);
        PreOrder(root->rlink);
    }
    
}

void InOrder(TNODE *root){
    if(root != NULL){
        InOrder(root->llink);
        printf("%d\t",root->info);
        InOrder(root->rlink);
    }
}

void PostOrder(TNODE *root){
    if(root != NULL){
        PostOrder(root->llink);
        PostOrder(root->rlink);
        printf("%d\t",root->info);
    }
}

int search(TNODE *root, int key){
    if (root == NULL){
        return -1;
    }
    if(root->info == key){
        return key;
    }
    if(root->info > key) {
    return search(root->llink, key);
    } else {
    return search(root->rlink, key);
    }
    return -1;    
}

void main() {
    TNODE *root = NULL;

    int choice , ele , key;
    for(;;){
        printf("1.Insert\t2.Search\t3.Display\t4.Exit \n");
        printf("Enter your Choice :");
        scanf("%d",&choice);
        switch(choice){
            case 1 :
                printf("Enter the element to be inserted : ");
                scanf("%d",&ele);
                root = insert(root,ele);
                break;
            case 2 :
                printf("Enter  the element to be searched : ");
                scanf("%d",&key);
                int result  = search(root,key);
                if(result == -1)
                    printf("Key not Found \n");
                else 
                    printf("Key  Found \n");
                break;
            case 3 :
                printf("PreOrder   :");
                PreOrder(root);
                printf("\n InOrder  :");
                InOrder(root);
                printf("\n PostOrder :");
                PostOrder(root);
                printf("\n");
                printf("\n");
                break;
            case 4 :
                exit(0);
        }
    }
}

