
class disjointSet{
    vector<int>rank,parent;
public:
    //constructor
    disjointSet(int n){
        rank.resize(n+1,0); //for safety putting n+1
        parent.resize(n+1);
        for(int i =0 ;i<=n;i++) parent[i] = i;
    }
    int findUParent(int node){
        if(parent[node] == node) return node;
        return parent[node] = findUParent(parent[node]);//path compressed + Ultimate parent finder
    }
    void unionByRank(int u , int v){
        int up_of_u = findUParent(u);
        int up_of_v= findUParent(v);
        if(up_of_u==up_of_v) return ;
        if(rank[up_of_u]<rank[up_of_v]){
             parent[up_of_u] = up_of_v;
             //rank dosent change as smaller is attaching to larger not equal or more
        }
        else if(rank[up_of_u]>rank[up_of_v]){
            parent[up_of_v] = up_of_u;
        }
        else{
            parent[up_of_v] = up_of_u;
            rank[up_of_u]++;
        }
    }
    };
class Solution {
    
  public:
  
    int spanningTree(int V, vector<vector<int>>& edges) {
        // code here
        auto cmp = [&](auto &p1,auto &p2){
            return p1[2]<p2[2];
        };
       sort(edges.begin(),edges.end(),cmp);
        vector<pair<int,int>> mst;
        int sum =0 ;
           disjointSet ds(V);
        for(int i =0 ; i<edges.size();++i){
            int wt = edges[i][2];
            int u = edges[i][0];
            int v = edges[i][1];
            if(ds.findUParent(u)!=ds.findUParent(v)){
                sum+=wt;
                ds.unionByRank(u,v);
            }
         
        }
        return sum ;
    }
};