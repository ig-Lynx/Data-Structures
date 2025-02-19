// Lab program 10


#include<stdio.h>
#include<stdlib.h>
#define MAX 100

typedef struct node {
    int id;
    char Name[20];
    int sal;

} EMP;

EMP emp[MAX]; // ( array of structures where all the empolyee details are stored )
int a[100] ; // hash table
int empID[MAX];
int count = 0;

int get_details(EMP emp[], int key , int ID){
    FILE *fp;
    fp = fopen("out.txt","a+");
    emp[key].id = ID;
    printf("Enter the details of the employee name & salaray : ");
    scanf("%s %d",emp[key].Name , &emp[key].sal);
    fprintf(fp,"\n %d \t %s \t %d",emp[key].id,emp[key].Name,emp[key].sal);
    fclose(fp);
    return key;
}

void display(){
    int i;
    printf("Key \t ID \t Name \t Salary");
    for(i=0;i<100;i++){
        if(a[i] != -1){
            printf("\n %d \t %d \t %s \t %d",i ,emp[i].id,emp[i].Name,emp[i].sal);
        }
    }
}


void probe(int key , int ID){
    int i = key;
    if(count == 100){
        printf("hash table is full \n");
        exit(0);
    }
    if(a[key] == -1){
        a[key] = get_details(emp,key,ID);
        display();
        count++;
    }
    else {
        printf("Collision detected , Solving it with Linear Probing \n");
        while(a[i] != -1){
            i++;
            if(i == 100){
                i = 0;
                while(i<key && a[i] != -1){
                    i++;
                }
            }
        }

        a[i] = get_details(emp,i,ID);
        display();
        count++;
    }
}

void main(){
    int key;
    int i = 0 ; // used to assign the value into the hash table 
    int j = 0; // used to iterate through the array of empolyee ID's
    int ans = 1;
    
    // initialising the whole hash table to -1 
    for(i = 0 ; i< 100 ; i++){
        a[i] = -1;
    }

    do{
        printf("Enter the Employee ID  :");
        scanf("%d", &empID[j]);
        key = empID[j]%100;
        probe(key,empID[j]);
        printf(" \n Do you want to continue adding data  ( 1 - yes || 0 - NO) : ");
        scanf("%d",&ans);
        j++;
    }while(ans);

    display();
    // for(i = 0 ; i< 100 ; i++){
    //     if(a[i] != -1){
    //         printf("Key's where data is present : \t %d",a[i]);
    //     }
    // }
    printf("\n");
    
}