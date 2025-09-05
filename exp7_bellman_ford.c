#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>

#define MAX_INT 1000
#define INF 10000
int adj[MAX_INT][MAX_INT];
int dist[MAX_INT];
typedef struct edge{
    int src,des,weight;
}edge;

edge e[MAX_INT];
int main(){
    int n , m; 
    int u , v, w;
    scanf("%d %d",&n, &m);
    //assuming 0 is src node 
    
    for(int i =1 ; i<n;++i){
        dist[i] =INF; 
    }
    for(int i =0 ; i<m;++i){
        scanf("%d %d %d",&u,&v,&w);
        adj[u][v]= w;//directed
    }
    for(int i =0 ; i<n;++i){
        int check = 0;
    for(int i =0 ; i<n;++i){
        for(int j =0 ; j<n;++j){
            if(adj[i][j]!=0){
                if(dist[i]+adj[i][j]<dist[j]){
                    dist[j]= dist[i]+adj[i][j];
                    check = 1;
                }
            }
        }
        
    }
     for(int i =0 ; i<n;++i){
        printf("%d ",dist[i]);
    }
    printf("\n");
        if(check && i ==n-1) {
            if(i==n-1){
            printf("Negative weighted cycle formed\n");return 0 ;
            }
        }
        if(!check){
            break;
        }
   
    }
 for(int i =0 ; i<n;++i){
        printf("%d ",dist[i]);
    }
    printf("\n");
    





}

//inputs
// 4 5
// 1 2 4 
// 1 4 5
// 2 4 5
// 3 2 -10
// 4 3 3

// 7 10
// 0 1 6 
// 0 2 5
// 0 3 5
// 1 4 -1
// 2 1 -2 
// 2 4 1
// 3 2 -2
// 3 5 -1 
// 4 6 3
// 5 6 3