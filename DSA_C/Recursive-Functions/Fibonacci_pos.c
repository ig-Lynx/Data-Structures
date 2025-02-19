#include<stdio.h>

int Fibonacci(int );

void main() {

    int n , res ;
    printf("Enter the postion of fibonacci series to be printed : \n");
    scanf("%d", &n);

    res = Fibonacci(n);
    printf("Element at %d postion of Fibonacci series is :%d ", n , res);

}


int Fibonacci( int n){

    if( n == 1)
        return 0;
    else if (n == 2)
    {
        return 1;
    }
    
    else 
        return(Fibonacci(n-1)+Fibonacci(n-2));
}