#include<stdio.h>

//Calling Ackemans Function 
int A(int , int);

void main(){

    int c1, c2 , result;

    printf("Enter the numbers \n");
    scanf("%d %d",&c1,&c2);

    result = A(c1,c2);
    printf("The result of A(%d,%d) is %d",c1,c2,result);
}

int A( int m , int n ){
    
    if( m == 0){
        return n+1;
    }
    else if(n == 0){
        return (A(m-1,1));
    }
    else {
        return (A(m-1,A(m,n-1)));
    }
    
}
