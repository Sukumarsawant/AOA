#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>


#define INF 100000
#define MAX 1000

int adj[MAX][MAX];

int min(int a, int b){
    if(a<b) return a;
    else return b;
}
int main(){

    int n; 

    scanf("%d",&n);


    //A0
    for(int i =0 ; i<n;++i){
        for(int j = 0;j<n;++j){
            scanf("%d",&adj[i][j]);

        }
    }

    for(int i =1 ;i<=n;++i){
        for(int j =0 ; j<n;++j){
            if((i-1)==j ) continue;
            for(int k =0 ; k<n;++k){
                if( k==(i-1)) continue;
                adj[j][k] = min(adj[j][k],adj[j][i-1]+adj[i-1][k]);

            }
        }
         for(int i =0 ; i<n;++i){
        for(int j =0 ; j<n;++j){
            printf("%d\t",adj[i][j]);
        }
        printf("\n");
    
    }
    printf("\n\n");
    }
    for(int i =0 ; i<n;++i){
        for(int j =0 ; j<n;++j){
            printf("%d\t",adj[i][j]);
        }
        printf("\n");
    }

}
// 4 
// 0 3 1000 7 
// 8 0 2 100
// 5 1000 0 1 
// 2 1000 1000 0
