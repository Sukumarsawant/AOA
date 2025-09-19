#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<time.h>
#include<stdlib.h>
void insertion(int a[],int n){
	int i , j ,val ; 
	for(i =1 ; i<n;++i){
		val = a[i];
		for( j = i-1;j>=0;--j){
			if(val<a[j]){
				a[j+1] = a[j];
			}
			else break;
		}
		a[j+1] = val;
	}
}
int binarySearch(int a[],int x,int n){
    int lo , hi ;
    int mid =-1;
    lo = 0 ; 
    hi = n-1;
    while(lo<=hi){
        mid = lo+(hi-lo)/2;
        if(a[mid]==x) return mid ;
        else if(a[mid]<x)lo = mid +1;
        else hi = mid-1;
    }
    return -1;
}
int main(){
    int i , j; 
    int n ; 
   
    int ans ;
    int x;
    printf("Enter the number of elements : \n");
    scanf("%d",&n);
     int a[n];
    printf("Enter the array: ");
    for(i=0 ; i<n;++i) scanf("%d",&a[i]);
    printf("Enter the number to be serached \n");
    scanf("%d",&x);
    insertion(a,n);
    for(i=0 ;i<n;++i) printf("%d ",a[i]);
    ans = binarySearch(a,x,n);
    if(ans==-1)printf("\nNOT FOUND");
    else printf("\nfound at %d",ans+1);
// printf("HELLO");
}