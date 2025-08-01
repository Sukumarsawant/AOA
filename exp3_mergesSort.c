#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<time.h>
#include<stdlib.h>

void minMax(int a[],int n,int *min,int *max){
    int i ;
   
    for(i =0 ;i<n;++i){
        if(a[i]>=(*max))(*max) = a[i];
        if(a[i]<=(*min))(*min) = a[i];

    }
    return;
}
void merge(int a[],int lb,int mid ,int ub){
    int i , j , k ;
    int temp[100000];
    i =lb ; j =mid+1 ;k=0;
    while(i<=mid && j<=ub){
        if(a[i]<a[j]){temp[k++] = a[i++];}
        else temp[k++]=a[j++];
    }
    while(j<=ub) temp[k++] = a[j++];
    while(i<=mid) temp[k++]  = a[i++];
     k =0 ;
    for(int i = lb ; i <ub;++i){
        a[i] = temp[k++];
    }
}
void mergeSort(int a[],int lb , int ub){
    int mid ;
    if(lb>=ub) return ;
    mid =(lb+ub)/2;
    mergeSort(a,lb,mid);
    mergeSort(a,mid+1,ub);
    merge(a,lb,mid,ub);
}

int main(){
	int n =10000;
	int a[n];
	int temp,min,max;
	int i , j ;
	clock_t start,end;
	double t;
	FILE *fptr1,*fptr2;
	fptr1 = fopen("input.txt","w");

	for( i =0 ; i<n;++i){
		fprintf(fptr1,"%d ",rand());	
	}
	fclose(fptr1);
		fptr1 = fopen("input.txt","r");
	for(i =0 ; i<n;++i){
		fscanf(fptr1,"%d",&temp);
		a[i] = temp;
	}
	fclose(fptr1);
    min = a[0];
    max = a[0];
    minMax(a,n,&min,&max);
    printf("min element:%d\n max element:%d\n",min, max);
	start = clock();
	mergeSort(a,0,n-1);
	end = clock();
	t = (double)(end-start)/CLOCKS_PER_SEC;
	;
	printf("merge sort: %lf\n",(double)(end-start)/CLOCKS_PER_SEC);

	fptr1 = fopen("output1.txt","w");
	
	for(int i =0 ; i<n;++i){
		fprintf(fptr1,"%d ",a[i]);
		
	}
	fclose(fptr1);
}

