#include<stdio.h>

int Fact(int n);


int main() {

    int num,factorial;

    printf("Enter the number :\n");
    scanf("%d", &num);

    factorial = Fact(num);
    printf("Factorial of %d is : %d", num,factorial);
    return  0;

}

int Fact(int n){
    if(n==1){
        return 1;
    }
    else {
        return (n*Fact(n-1));
    }
}