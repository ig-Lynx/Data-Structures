// Lab program 5

#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int deque[MAX];
int front = -1;
int rear = -1;

int isfull() {
    return ((front == 0 && rear == MAX - 1) || (front == (rear + 1) % MAX));  // Corrected assignment to equality check and modular condition
}

int isempty() {
    return (front == -1);
}

void insertfront(int value) {
    if (isfull()) {  // Corrected to use isfull()
        printf("Double ended queue is full\n");
    } else {
        if (isempty()) {  // Corrected to use isempty()
            front = rear = 0;
        } else if (front == 0) {
            front = MAX - 1;
        } else {
            front--;
        }
        deque[front] = value;
        printf("Element enqueued at front is %d\n", value);
    }
}

void insertrear(int value) {
    if (isfull()) {  // Corrected to use isfull()
        printf("Double ended queue is full\n");
    } else {
        if (isempty()) {  // Corrected to use isempty()
            front = rear = 0;
        } else if (rear == MAX - 1) {  // Corrected assignment to equality check
            rear = 0;
        } else {
            rear++;
        }
        deque[rear] = value;
        printf("Element enqueued at rear is %d\n", value);
    }
}

int deletefront() {
    if (isempty()) {
        printf("Double ended Queue is empty\n");
        return -1;
    }
    int value = deque[front];
    if (front == rear) {
        front = rear = -1;  // Queue is now empty
    } else if (front == MAX - 1) {
        front = 0;
    } else {
        front++;
    }
    printf("Element dequeued from front is %d\n", value);
    return value;
}

int deleterear() {
    if (isempty()) {
        printf("Double ended Queue is empty\n");
        return -1;
    }
    int value = deque[rear];
    if (front == rear) {
        front = rear = -1;  // Queue is now empty
    } else if (rear == 0) {
        rear = MAX - 1;
    } else {
        rear--;
    }
    printf("Element dequeued from rear is %d\n", value);
    return value;
}

void display() {
    if (isempty()) {
        printf("Double ended Queue is empty\n");
        return;
    }

    printf("Elements of the Double ended Queue are: ");
    int i = front;
    while (1) {
        printf("%d ", deque[i]);
        if (i == rear) break;
        i = (i + 1) % MAX;  // circular increment
    }
    printf("\n");
}

int main() {
    int choice, value;

    while (1) {
        printf("\nMenu for Double-ended Queue\n 1.InsertFront\t2.Insert Rear\t3.DeleteFront\t4.DeleteRear\t5.Display\t6.Exit\n");
        printf("Enter your Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to be inserted at front: ");
                scanf("%d", &value);
                insertfront(value);
                break;
            case 2:
                printf("Enter the value to be inserted at rear: ");
                scanf("%d", &value);
                insertrear(value);
                break;
            case 3:
                deletefront();
                break;
            case 4:
                deleterear();
                break;
            case 5:
                display();
                break;
            case 6:
                exit(0);

            default:
                printf("Invalid Choice\n");
        }
    }
    return 0;
}
