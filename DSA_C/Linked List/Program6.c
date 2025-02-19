#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char name[20];
    char usn[10];
    char branch[5];
    int sem;
    char phno[10];
    struct node* link;
};

typedef struct node* NODE;

// Get node
NODE get_node() {
    NODE temp;
    temp = (NODE)malloc(sizeof(struct node)); // allocation of memory
    temp->link = NULL;
    printf("\n Name: ");
    scanf("%s", temp->name);
    printf("\n USN: ");
    scanf("%s", temp->usn);
    printf("\n Branch: ");
    scanf("%s", temp->branch);
    printf("\n Sem: ");
    scanf("%d", &temp->sem);
    printf("\n Ph no: ");
    scanf("%s", temp->phno);
    return temp;
}

// Insert front
NODE insert_front(NODE first) {
    NODE temp;
    temp = get_node();
    if (first == NULL) {
        first = temp;
        return temp;
    } 
    else {
        temp->link = first;
        return temp;
    }
}

// Insert rear
NODE insert_rear(NODE first) {
    NODE temp, next;
    temp = get_node();
    if (first == NULL)
        return temp;
    else {
        next = first;
        while (next->link != NULL)
            next = next->link;
        next->link = temp;
        return first;
    }
}

// Delete front
NODE del_front(NODE first) {
    NODE temp;
    if (first == NULL) {
        printf("\n No entries");
        return first;
    }
    temp = first;
    first = first->link;
    free(temp);
    return first;
}

// Delete rear
NODE del_rear(NODE first) {
    NODE temp, prev, cur;
    if (first == NULL) {
        printf("\n No entries \n");
        return first;
    } else if (first->link == NULL) {
        printf(" Deleted USN:%s \n", first->usn);
        free(first);
        return NULL;
    }
    cur = first;
    while (cur->link != NULL) {
        prev = cur;
        cur = cur->link;
    }
    prev->link = NULL;
    printf("Deleted USN: %s", cur->usn);
    free(cur);
    return first;
}

// Display
void display(NODE first) {
    NODE temp = first;
    int count = 0;
    if (temp == NULL) {
        printf("\n No entries \n");
        return;
    }
    printf("\n Student info: \n");
    while (temp != NULL) {
        printf("Name:%s\t", temp->name);
        printf("USN:%s\t", temp->usn);
        printf("Branch:%s\t", temp->branch);
        printf("Sem:%d\t", temp->sem);
        printf("Ph no:%s\t", temp->phno);
        printf("\n");
        count++;
        temp = temp->link;
    }
    printf("\n The number of nodes are %d", count);
}

// Main function
void main() {
    NODE first = NULL;
    int choice;
    for (;;) {
        printf("\n\n Enter choice 1.IF 2.IR 3.DF 4.DR 5.display 6.Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1: first = insert_front(first);
                    break;
            case 2: first = insert_rear(first);
                    break;
            case 3: first = del_front(first);
                    break;
            case 4: first = del_rear(first);
                    break;
            case 5: display(first);
                    break;
            case 6: exit(0);
        }
    }
}