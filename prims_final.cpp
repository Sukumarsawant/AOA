
    int spanningTree(int V, vector<vector<int>>& edges) {
        // code here
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        //min heap pq;
        vector<int> vis(V+1,-1);
        pq.push({0,{0,-1}});// o dist 0 node parent -1
        vector<vector<pair<int,int>>> adj(V+1);
        for(int i =0 ; i<edges.size();++i){
            int a = edges[i][0];
            int b = edges[i][1];
            int dist = edges[i][2];
            adj[a].push_back({b,dist});
            adj[b].push_back({a,dist});
            
        }
        vector<pair<int,int>> mst;
        int sum =0 ;
        while(!pq.empty()){
            auto temp = pq.top();
            int dist = temp.first;
            int node = temp.second.first;
            int parent = temp.second.second;
            pq.pop();
            if(vis[node]==1) continue;
            
            vis[node] = 1;
            if(parent!=-1)
            {
                mst.push_back({dist,node});
                sum+=dist;
                
            }
            for(int i =0 ; i<adj[node].size();++i){
                // int par = node;
                pq.push({adj[node][i].second,{adj[node][i].first,node}});
                
            }
        }
        return sum ;
    }
