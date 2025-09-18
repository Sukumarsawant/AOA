#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>

#define MAX 1000


typedef struct pair{
    double ratio;
    int w, idx;
    double val;
}pair;
void sort( pair a[], int n){
    for(int i =0 ; i<n-1;++i){
        for(int j = 0 ; j<n-i-1;++j){
            if(a[j].ratio<a[j+1].ratio){
                pair temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}
void sortidx( pair a[], int n){
    for(int i = 0; i < n-1; ++i) {
        for(int j = 0; j < n - i-1; ++j) {
            if(a[j].idx > a[j+1].idx) {
                pair temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}

int main(){

    int n , m ; //m is capacity of knapsack
    int p[MAX],w[MAX];
    pair r[MAX];
    scanf("%d %d",&n,&m);

    for(int i =0 ; i<n;++i) r[i].val =0;
    for(int i =0 ; i<n;++i){
        scanf("%d",&p[i]);
    }

    for(int i =0 ; i<n;++i){
        scanf("%d",&w[i]);
    }

    for(int i =0 ;i<n;++i){
        r[i].ratio = (p[i]*1./w[i]);
        r[i].w = w[i];
        r[i].idx = i;
    }

    sort(r,n);
    double bag =0 ;
    double profit = 0;
    for(int i =0 ; i<n;++i){
        if(bag+r[i].w<=m){
            bag+=r[i].w;
            profit+=(r[i].ratio*r[i].w);
            r[i].val = 1.0;
        }
        else{
            // temp -> capacity-bag;
            // w = temp/ratio 
            double temp = m-bag;
            double included =temp*1./r[i].w;
            profit+=(r[i].ratio *(temp));
            r[i].val= included;
            break;

        }
    }
    printf("%.2lf\n",profit);
    sortidx(r,n);
    for(int i =0 ; i<n;++i){
        printf("%.2lf\t", r[i].val);
    }
    






}