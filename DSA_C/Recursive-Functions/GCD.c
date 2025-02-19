#include<stdio.h>

int GCD( int , int );

void main() {
    int c1, c2;
    int gcd;

    printf("ENter the number c1 & c2: \n");
    scanf("%d %d", &c1, &c2);
    gcd = GCD(c1,c2);
    printf("GCD of %d & %d is %d",c1,c2,gcd);
}

// int GCD(int x, int y){
//     int r;
//     while(y!=0){
//     r = x %y;
//     x = y;
//     y = r;
//     }

//     return x;
// }

// recursive Function 

int GCD(int x, int y) {
    if (y == 0)
        return x;
    else
        return GCD(y, x % y);  // Recursive call
}
