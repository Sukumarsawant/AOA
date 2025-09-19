#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>

#define MAX 100
int max(int a,  int b){
    if(a>b) return a;
    else return b;
}
// int
int dp[MAX][MAX];
int func(int i,int p[],int w[],int capacity){
    if(i<0) return 0;

    if(capacity>=0 && dp[i][capacity]!=-1) return dp[i][capacity];
    if(capacity>=w[i]) return  dp[i][capacity]=max(func(i-1,p,w,capacity-w[i])+p[i],func(i-1,p,w,capacity));
    else return dp[i][capacity]=func(i-1,p,w,capacity);
 

}
int main(){
    int n, m ;
    int p[MAX],w[MAX]; 
    scanf("%d %d",&n,&m);
    for(int i =0 ;i<=n;++i){
        for(int j =0 ; j<=m;++j){
            dp[i][j] = -1;
        }
    }

    for(int i =0 ;i<n;++i){
        scanf("%d",&p[i]);
    }

    for(int i =0 ;i<n;++i){
        scanf("%d",&w[i]);
    }
    
    printf("%d",func(n-1,p,w,m));


}
