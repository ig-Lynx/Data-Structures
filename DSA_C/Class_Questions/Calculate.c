#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
        int n,i,*p;
        float  sum =0 ,mean= 0,var =0 ,stddiv =0;
        printf("Enter the Number of elements ");
        scanf("%d",&n);
        p=(int*)malloc(n*sizeof(int));
        for(i=0;i<n;i++){
                printf("enter the element no %d ", i+1);
                scanf("%d",p+i);
        }

        for(i=0;i<n;i++){
                sum += *(p+i);
        } 
        printf(" the sum = %.2f ",sum);

        mean=sum/n;
        printf(" the mean = %.2f ",mean);

        for(i=0;i<n;i++)
                var=var+pow((*(p+i)-mean),2);
        
        var = var /n;

        
        printf(" the variance = %.2f ",var);

        stddiv=sqrt(var);
        printf(" the stddiv = %.2f ",stddiv);


        return 0;




}