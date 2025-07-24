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
void selection(int a[],int n){
	int i , j , mini,idx ;
	
	for(i=0 ;i<n-1;++i){
		mini = a[i];
	idx = i;
		for( j =i+1  ; j<n;++j){
			if(mini>a[j]){
			mini = a[j];
			idx  = j;
		}
		}
		a[idx] = a[i];
		a[i] = mini;
	}
}
int main(){
	int n =10;
	int a[n],b[n];
	int temp;
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
		b[i] = temp;
	}
	fclose(fptr1);
	start = clock();
	insertion(a,n);
	end = clock();
	t = (double)(end-start)/CLOCKS_PER_SEC;
	start = clock();
	selection(b,n);
	end = clock();
	printf("selection sort: %lf\ninsertion sort: %lf\n",(double)(end-start)/CLOCKS_PER_SEC,t);

	fptr1 = fopen("output1.txt","w");
	fptr2 = fopen("output2.txt","w");
	for(int i =0 ; i<n;++i){
		fprintf(fptr1,"%d ",a[i]);
		fprintf(fptr2,"%d ",b[i]);
	}
	fclose(fptr1);
	fclose(fptr2);

	
	
	
	
	
	
}
