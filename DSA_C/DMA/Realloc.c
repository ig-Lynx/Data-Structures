#include<stdio.h>
#include<stdlib.h>
int main() {

	int n, *p, m,i;

	printf("Enter the number of elements : ");
	scanf("%d", &n);
	
	// Allocation of memory through malloc
	p = (int *)malloc(n*sizeof(int));

	if (p == NULL){
		printf("Failed to create Memory ");
		return 1;
	}
	
	for(i=0 ; i<n ;i++){
	scanf("%d", p+i);
	}
	
	printf("\n");
	
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

	for(i=n;i<m+n;i++){
	scanf("%d", p+i);
	}
	
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
