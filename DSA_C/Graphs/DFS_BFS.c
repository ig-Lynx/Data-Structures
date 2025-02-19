// LAb program 9

#include<stdio.h>
#include<stdlib.h>

//global decalrations
int city[10][10] ; // adjacency matrix
int visited[10] ;  
int queue[10] , f = 1 , r= 0 ;
int n ; // n to store the number of cites

void dfs(int s){
    int i;
    visited[s] = 1;
    for(i = 1 ; i <= n ; i++){
        if(city[s][i] && !visited[i]){
            printf("%d \t", i);
            visited[i] = 1;
            dfs(i);
        }
    }
}

void bfs(int s){
    int i;
        
    for(i = 1 ; i <= n ; i++){
        if(city[s][i] && !visited[i]){
            queue[++r] = i;
            visited[i] = 1;
            printf("%d\t",i);
        }    
    }    
    
    if(f <= r){
        visited[s] = 1; 
        s = queue[f++];
        bfs(s);
    }
    
}

void bfs_2(int s){
    int i;

    visited[s] = 1;
    // printf("%d",s); // first node

    while(f <= r){
        s = queue[f++];
        for(i = 1 ; i <= n ; i++){
            if(city[s][i] && !visited[i]){
                queue[++r] = i; // loading the element to queue 
                // so that it will get explored next 
                visited[i] = 1; // then marking that element as visited 
                printf("%d\t",i);
            }
        }
    }

}


void main(){
    int choice , s ,i , j ;
    int count = 0;

    printf("Enter the number oc citites : ");
    scanf("%d",&n);

    printf("Enter the adjacency Matrix :\n");
    for(i = 1 ; i <= n ; i++){
        visited[i] = 0;
        queue[i] = 0 ;
        for( j = 1 ; j  <= n ; j ++){
            scanf("%d", &city[i][j]);
        }
    }

    printf(" \n Enter 1 for DFS & 2 for BFS : ");
    scanf("%d",&choice);

    printf("\n Enter the city to check connectivity : ");
    scanf("%d",&s);

    if(choice == 1){
        dfs(s);
    }
    if(choice == 2){
        queue[++r] = s;
        bfs_2(s);

    }

    printf("\n");

    for(i = 1 ; i <= n ; i++){
        count = count + visited[i];
    }
    if(count == n){
        printf(" \n All cities are interconnected \n");
    }
    else {
        printf("All cities are not interconnected \n");
    }
}
