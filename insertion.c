#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<time.h>

void insertion(int a[],int n){
	int i , j ,val ; 
	for(i =1 ; i<n;++i){
		val = a[i];
		for( j = i+1;j>=0;--j){
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
	mini = a[0];
	idx = 0;
	for(i=1 ;i<n-1;++i){
		for( j = 0 ; j<n;++j){
			if(mini<a[j]){
			mini = a[j];
			idx  = j;
		}
		a[idx] = a[i];
		a[i] = mini;
		
		}
	}
}
int main(){
	int i , j ,temp; 
	int n = 10000;
	int a[n],b[n];
	clock_t st ,ed ;
	FILE* fptr1,*fptr2,*fptr3;
	fptr1 = fopen("input.txt","w");
//	if(fptr1==NULL)printf("File not opened");
	
	for(i =0 ; i<n;++i){
		fprintf(fptr1,"%d ",rand());
	}
	fclose(fptr1);
		fptr1 = fopen("input.txt","r");
	
//	fscanf(fptr1,"%d",c);
//	fptr2 = fopen("text.txt","w");
//	for(i =0 ;i<n;++i){
//		
//		fprintf(fptr1,"%d ",c[i]);
//		
//	}
//	rewind(fptr1);
//	fclose(fptr2);
//fptr2 = fopen("output1.txt")
	for(i =0;i<n;++i){
		  fscanf(fptr1,"%d",&temp);
//		  printf("%d ",temp);
		a[i] = temp ;
		b[i] = temp ;
	}
//	printf("okkk");
	st =clock();
		insertion(a,n);
	ed = clock();
//	printf("%f\n",ed);
	printf("\n%lf\n",abs(ed-st)/1000.);
	st = clock();
		selection(b,n);
		ed =clock();
		printf("\n%lf\n",abs(ed-st)/1000.);
//		printf("ok\n");
		fclose(fptr1);
			fptr2 = fopen("output1.txt","w");
					fptr3 = fopen("output2.txt","w");
//					for( i =0 ; i<n;++i)printf("%d ",a[i]);
		for(i =0 ; i<n;++i){
			fprintf(fptr2,"%d ",a[i]);
			fprintf(fptr3,"%d ",b[i]);
		}
		fclose(fptr2);
		fclose(fptr3);
		printf("sorted");
		
	
	
	
	
	
}
