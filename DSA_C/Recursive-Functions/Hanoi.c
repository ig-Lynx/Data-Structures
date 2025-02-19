#include<stdio.h>

void hanoi(int n , char from , char to , char via);

int main() {
    int n = 3 ;

    char from  = 'A';
    char to = 'B'; 
    char via  = 'C' ;

    // calling hanoi function 
    hanoi(n,from, to , via);
    
    
    return 0;
}


void hanoi(int n , char from , char to , char via){
    if(n ==1){
        printf("Move disk 1 from %c to %c \n",from, to);
    }
    else {
        hanoi(n-1,from , via , to);
        printf("Move disk %d from %c to %c \n",n,from,to);
        hanoi(n-1,via,to,from);
    }
}