//dijstra -> single source shortes path 
#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>


#define MAX 1000
#define INF 100000

//priority queue in c 
int vis[MAX];
int dist[MAX];
int adj[MAX][MAX];



//min heap pq
typedef struct priority_queue{
    int node,dist; //{w,node,parent} form 
}priority_queue;


priority_queue pq[MAX];
int idx =0;
void push(int dist , int node){
    pq[idx].node = node;
    pq[idx].dist = dist;
    idx++; // Increment idx after inserting
}
//pq is a struct //pq[] arr
priority_queue pop(){
    int mini_idx = 0;
    for(int i = 0;i<idx;++i){
        if(pq[i].dist < pq[mini_idx].dist)
        mini_idx = i;
        
    }
    priority_queue temp = pq[mini_idx];
    // pq[mini_idx].w = MAX;
    for(int i = mini_idx+1;i<idx;++i){
        pq[i-1] = pq[i];
    }
    idx--;//size reduced to use pq.empty()
    return temp;
}
int empty() {return (idx==0);}

///end


int main(){
    // priority_queue pq//alredy in global

int n , m;
int u ,v,w;
int src =0;
int sum =0;
scanf("%d %d",&n,&m);

for(int i =0 ; i<m;++i){
  scanf("%d",&u);
  scanf("%d",&v);
  scanf("%d",&w);
  adj[u][v] = w;
  adj[v][u] = w;
}
//adj matrix not adc list

for(int i =0 ; i<n;++i){
    dist[i] = INF;
    vis[i] = 0;
}

scanf("%d",&src);
dist[src]= 0;

push(dist[src],src);
while(!empty()){
    priority_queue var = pop();
    int cur = var.node ;
    vis[cur] = 1;
    int d = var.dist;
    
    for(int i =0 ;i<n;++i){
        if(adj[cur][i]==0) continue;
        else{
            if(vis[i]==1) continue;
            if(dist[i]>adj[cur][i]+d){
                dist[i] = adj[cur][i]+d;
            push(dist[i],i);
            }
        }
    }
}
for(int i =0 ; i<n;++i) printf("%d\t",dist[i]);






}


