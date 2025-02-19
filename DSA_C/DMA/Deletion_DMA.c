#include<stdio.h>
#include<stdlib.h>


int main() {

	 int n , *p, i = 0;
	int  index , m ;

	printf("Enter the number of elements in the array : " );
	scanf("%d",&n);
	
	p = (int *)malloc(n*sizeof(int));

	if(p == NULL){
		printf("Error in creation of memory \n ");
		return 1;
	}

	printf("Enter the elements to be stored in the array \n " );
	for( i=0;i<n;i++){
		scanf("%d",(p+i));
	}
	
	// display the array 

	printf("The Elements of the array are :");
	for(i=0;i<n;i++){
		printf("%d \t",*(p+i));
	}
	
	printf("\n");

	// reallocation of memory
	
	printf("Enter the number of elements to be removed from the array : ");
	scanf("%d",&m);
	p = (int *)realloc(p,(n-m)*sizeof(int));
	
	printf("Entr the index of the element to be popped : ");
	scanf("%d",&index);
	
	for( i = index ; i < (n-m) ; i++){
		*(p+i) = *((p+i)+1);
	}

	printf(" The new array : \t ");
	for(i = 0; i < (n-m) ; i++){
		printf("%d \t",*(p+i));
		
	}
	printf("\n");

}	
