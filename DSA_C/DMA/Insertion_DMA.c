#include<stdio.h>
#include<stdlib.h>
int main() {

	int n, *p, m,i,key,index;

	printf("Enter the number of elements : ");
	scanf("%d", &n);
	
	// Allocation of memory through malloc
	p = (int *)malloc(n*sizeof(int));

	if (p == NULL){
		printf("Failed to create Memory ");
		return 1;
	}
	
	printf("Enter the elements of the array : ");
	for(i=0 ; i<n ;i++){
	scanf("%d", p+i);
	}
	
	printf("\n");
	
	printf("The entered  Array is :");
	for(i=0; i <n ; i++){
	printf("%d \t", *(p+i));
	}

	// reallocation of memory 
	
	printf("\n");

	printf("Enter the extar elements to be added in the array : ");
	scanf("%d",&m);

	p = (int*)realloc(p,(m+n)*sizeof(int));
	
	if(p == NULL){
		printf("Failed to create a memory");
		return 1;
	}

    printf("Enter the element index");
    scanf("%d",&index);

    printf("Enter the element");
    scanf("%d",&key);


	for(i=(n+m);i>=index;i--){
        *((p+i)+1) = *(p+i);
    }

    *(p+i+1) = key;
	
	printf("\n");
	// printing the whole array from the first
	for(i =0 ; i< (m + n) ;i++){
	printf("%d \t",*(p+i));
	} 

	printf("\n");

	free(p);

	if(p == NULL){
	printf("Fail");
}
}
