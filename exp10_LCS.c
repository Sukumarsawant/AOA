#include<stdio.h>
#include<conio.h>  
#include<math.h>
#include<stdlib.h>

#define MAX 1000
#define max(a,b) (a>b?a:b)
  int dp[MAX][MAX];
int lcs(int i ,int j,char a[], char b[]){
    if(i<0 || j<0 ) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    if(a[i]==b[j]){
        return dp[i][j] = 1+ lcs(i-1,j-1,a,b);
    }
    else return dp[i][j] = max(lcs(i-1,j,a,b), lcs(i,j-1,a,b));
}
int main(){
    int n , m;
    char a[MAX], b[MAX];
  

   scanf("%d",&n);
scanf("%s",a);
scanf("%d",&m);
scanf("%s",b);

    for(int i =0 ; i<n;++i){
        for(int j =0 ; j<m;++j){
            dp[i][j] =-1;
        }
    }
    dp[n-1][m-1] = lcs(n-1,m-1,a,b );
    printf("%d",dp[n-1][m-1]);
    int len = dp[n-1][m-1];
    char ans[MAX];

    int i = n-1, j = m-1;
    ans[len] = '\0';
    for(;i>=0 && j>=0;){
        if(a[i]==b[j]){
            ans[len-1] = a[i];
            --i;--j;--len;
        }
        else{
            if(i>0 && (j==0 || dp[i-1][j]>=dp[i][j-1])) --i;
            else --j;
            
    }

}
printf("%s",ans);
}