#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>


#define MAX 1000
int adj[MAX][MAX];
char color[MAX];
char ans[MAX];
void func(int i,int n,int m){
    if(i==n) {
        printf("\n\nans\n\n");
        for(int i =0;i<n;++i){
            printf("%c ",ans[i]);
        }
        printf("\n");return;
    }
    for(int h=0;h<m;++h){
        int check=1;
        for(int k =0;k<n;++k){
            if(adj[i][k]==1 && ans[k]==color[h]) {check = 0;break;}
        }
        if(check){
            ans[i] = color[h];
            func(i+1,n,m);
        //    ans[i]=' ';
        return;
         }
    }
    // // cout<<color[j]<<" ";
    // printf("%c ",color[j]);
    //  func(i+1,(j+1)%m,n,m);
}
int main(){
    int n;
    scanf("%d",&n);

    for(int i= 0;i<n;++i){
        for(int j =0;j<n;++j)
        scanf("%d",&adj[i][j]);
    }

    int m ; scanf("%d",&m);
    // char trash;
    // scanf("%c",&trash);
    for(int i=0;i<m;++i){
        scanf(" %c",&color[i]);
    }


    func(0,n,m);
}