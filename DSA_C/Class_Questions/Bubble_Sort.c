#include<stdio.h>

int main() {
    int i,j,n,temp,a[20];
    int *p;
    printf("Enter the number of elements : \n");
    scanf("%d", &n);

    printf("Enter the elements : \n");
    for(i=0;i<n;i++){
        scanf("%d", a+i);
    }

    // bubble sort logic
    for(i=0;i<n;i++){
        for(j=0;j<(n-i)-1;j++){
            p = a + j ; // setting pointer to the current element of the array
            if(*p > *(p+1)){
                temp = *p;
                *(p) = *(p+1);
                *(p +1) = temp;
            }
        }
    }

    printf("The sorted array is  : \n");
    for(i=0;i<n;i++){
        printf("%d \t ", *(a+i));
    }
    return 0;
}