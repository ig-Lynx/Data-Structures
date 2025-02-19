#include<stdio.h>

int Fact(int num);

int main() {

    int n ,r ;
    float result;

    printf("ENter the number of n : \n");
    scanf("%d",&n);

    printf("Enter the number of r: \n");
    scanf("%d",&r);


    if( n < 0 || r < 0){
        printf("Enter only +ve numbers \n");
    }
    else if(n < r){
        printf("n should be greater than r \n");
    }
    else {
    result = Fact(n)/(Fact(r)*Fact(n-r));

    }

    printf("The C(n/r) : C(%d)/(%d) = %.2f", n,r , result);
    return 0;
}

/*int Fact(int num){
    int f =1;
    int i;

    for(i=num ; i>=1; i--){
        f=f*i;
    }
    return f;
} */

// recursive logic
int Fact(int num){
    if(num == 1){
        return 1;
    }
    else {
        return (num*Fact(num-1));
    }
}