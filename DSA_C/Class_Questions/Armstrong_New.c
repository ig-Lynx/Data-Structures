#include <stdio.h>
#include <math.h>

int main() {
    int num,first,second,digit;
    int count =0;
    int sum =0; 
    printf("Enter the number: ");
    scanf("%d",&num);

    first = num;
    
    while(first!=0){
        first = first/10;
        count++;
    }

    second = num;

    while(second!=0){
        digit = second%10;
        int d_n = (int)pow(digit,count);
        printf("d_n : %d \n",d_n);
        sum = sum + d_n;
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