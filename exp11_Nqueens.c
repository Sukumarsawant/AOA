#include<stdio.h>
#include<math.h>
#include<stdlib.h>


#define MAX 1000

int ans[MAX];
int matrix[MAX];
int diag1[MAX];
int diag2[MAX];
void func(int i , int n){
    if(i==n){
        for(int i =0 ;i<n;++i){
            printf("%d\t",ans[i]);
        }
        printf("\n");
        return ;
    }
    for(int col =0 ;col<n;++col){
    if(( matrix[col]!=1) && (diag1[col-i+n-1]!=1) && diag2[col+i]!=1){  
        // printf("%d %d\n",i,col+1);
    diag1[col-i+n-1] = 1;
    diag2[col+i] = 1;
    matrix[col] = 1;
    ans[i] = col+1;
    func(i+1,n);
    ans[i] = 0;
    diag1[col-i+n-1] = 0;
    diag2[col+i] = 0;
    matrix[col] = 0;
    }
    // if(i==n-1){
    //     for(int i =0 ;i<n;++i){
    //         printf("%d\t",ans[i]);
    //     }
    //     return ;
    // // }
    // else return ;
    }
    

    

}

int main(){
    int n ; 
    scanf("%d",&n);

    func(0,n);
}