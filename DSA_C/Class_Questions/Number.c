#include <stdio.h>
#include <math.h>

int main() {
    int num,first,second,digit;
    int count =0;
    int sum =0; 
    printf("Enter the number: ");
    scanf("%d",&num);

    first = num;
    second = num;

    while(first!=0){
        first = first/10;
        count++;
    }

    while(second!=0){
        digit = second%10;
        sum = sum + pow(digit,count);
        second = second/10;
    }

    printf("Sum : %d \n",sum);
    
    if(num == sum){
        printf("The number is armstrong number");
    }
    else{
        printf("The number is not armstrong number");
    }

    return 0; 
}
