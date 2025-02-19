#include<stdio.h>

void main() {
    int i, n, odd_sum = 0, even_sum = 0;
    int arr[10];

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements: ");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    for(i = 0; i < n; i++) {
        if(arr[i] % 2 == 0) {
            even_sum += arr[i];
        } else {
            odd_sum += arr[i];
        }
    }

    printf("Sum of odd numbers: %d\n", odd_sum);
    printf("Sum of even numbers: %d\n", even_sum);
    
}
