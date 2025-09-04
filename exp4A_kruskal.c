//kruskal =>dsu
#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<time.h>
#include<stdlib.h>
#define INT_MAX 1000
//parent array 
//rank
int rank[INT_MAX];
int parent[INT_MAX];
//  int adj[INT_MAX][INT_MAX];
 
void DSU(int n){
    for(int i = 0 ;i<=n;++i){
        parent[i] = i;
        rank[i] = 0;
    }
}
//find path compresion + master find
int findUParent(int n){
    if(parent[n] ==n) return n;
    return parent[n] = findUParent(parent[n]);
}
//union by rank 
void unionByRank(int u , int v){
    int pu = findUParent(u);
    int pv = findUParent(v);

    if(pu==pv) return ;//same parent
    else if(rank[pu]>rank[pv]){
        parent[pv] = pu;
    }
    else if(rank[pu]<rank[pv]) parent[pu] = pv;
    else if(rank[pu]==rank[pv]){
        parent[pu] = pv;
        rank[pv]++;//inc rank only when equal
    }
}
typedef struct edge{
    int weight,node,parent;
}edge;
//custom comp
void bubbleSort(edge edges[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (edges[j].weight > edges[j+1].weight) {
                edge temp = edges[j];
                edges[j] = edges[j+1];
                edges[j+1] = temp;
            }
        }
    }
}

int main(){
    int n ;int m ;
    int u ,  v,w;
    // int mst[INT_MAX][INT_MAX];
    edge e[INT_MAX];
    int weight =0;
    scanf("%d",&n);
    scanf("%d",&m);

   
    DSU(n);
    for(int i =0 ; i<m;++i){
        
        scanf("%d",&e[i].node);
        scanf("%d",&e[i].parent);
        scanf("%d",&e[i].weight);
        
    } 
//   sort(adj,adj+n);
bubbleSort(e,m);
        for(int i =0 ; i<m;++i){
        int u = e[i].node;
        int v = e[i].parent;
        int w = e[i].weight;
        if(findUParent(u)!=findUParent(v)){
            weight+=w;
            unionByRank(u,v);
          printf("%d %d %d\n",u,v,w);
        }   
        }
        

            // for(int j =0 ; j<;++j){
            //     if(mst[u][v]==1)
            //     printf("%d %d %d ",u,v,mst[u][v]);
            // }
        printf("total sum : %d",weight);
        // adj[u][v] = w;
        // adj[v][u] = w;

    
  


}