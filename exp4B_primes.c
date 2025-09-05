#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<time.h>
#include<stdlib.h>
#define INT_MAX 1000

int vis[INT_MAX];
int adj[INT_MAX][INT_MAX];
// int mst[INT_MAX];
typedef struct priority_queue{
    int w,node,parent; //{w,node,parent} form 
}priority_queue;

priority_queue pq[INT_MAX];
int idx =0;
void push(int w, int node , int parent){
    pq[idx].w =w;
    pq[idx].node =node;
    pq[idx++].parent=parent;
}
//pq is a struct //pq[] arr
priority_queue pop(){
    int mini_idx = 0;
    for(int i = 0;i<idx;++i){
        if(pq[i].w<pq[mini_idx].w)
        mini_idx = i;
        
    }
    priority_queue temp = pq[mini_idx];
    // pq[mini_idx].w = INT_MAX;
    for(int i = mini_idx+1;i<idx;++i){
        pq[i-1] = pq[i];
    }
    idx--;//size reduced to use pq.empty()
    return temp;
}
int empty() {return (idx==0);}

// typedef struct edge{
//     int weight,node,parent;
// }edge;
int main(){
    // priority_queue pq//alredy in global

int n , m;
int u ,v,w;
int sum =0;
scanf("%d %d",&n,&m);

for(int i =0 ; i<m;++i){
  scanf("%d",&u);
  scanf("%d",&v);
  scanf("%d",&w);
  adj[u][v] = w;
  adj[v][u] = w;
}
push(0,0,-1);
while(!empty()){
    priority_queue temp = pop();
    int cur = temp.node;
    int par = temp.parent;
    int wt = temp.w;

    if(vis[cur]==1)continue;
    vis[cur] = 1;
    if(par!=-1){
        printf("%d %d %d\n",cur,par,wt);
        sum+=wt;
    }
    for(int i =0;i<n;++i){
        if(adj[cur][i]==0 || vis[i]) continue;
        push(adj[cur][i],i,cur);
    }

 
}
printf("Total sum : %d",sum );


}

