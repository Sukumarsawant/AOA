#include<bits/stdc++.h>
 using namespace std;
//  #define min_pq 
 void debugadj(vector<vector<pair<int,int>>> &adj){
         for (int i = 0; i < adj.size(); i++) {
        cout << i << ": ";
        for (int j = 0; j < adj[i].size(); j++) {
            cout << "{"<<adj[i][j].first<<","<<adj[i][j].second <<"}"<< " ";
        }
        cout << "\n";
    }
}

 int main(){
 	int n ; cin>>n ;
 	int m ; cin>>m; 
 	
 	
// 	vector<vector<int>> edges(n,vector<int>(m,0));
 	
 	
	  
 	//vert//eges//joints and weight 
 	// startihng node 
 	vector<vector<pair<int,int>>> adj (n);
 	for(int i =0 ; i<m;++i){
 		int a, b, c; 
 		cin>>a>>b>>c;
 		
		adj[a].push_back({b,c});
 		adj[b].push_back({a,c});
 		
	 }
// 	 debugadj(adj);
	 //pair<int,pair<int,int>>
priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>>
  pq ;
	 vector<int> vis(n+1,0);
	 int weight =0;
	 //w,node,parent
	 pq.push({0,{0,-1}});
	 vector<pair<int,int>> mst ;
	 while(!pq.empty()){
	     int a = pq.top().first;
	     int b = pq.top().second.first;
	     int c = pq.top().second.second;
	     pq.pop();
	     for(int i =0 ; i<adj[c].size();++i){
	         pq.push(a,{})
	     }
	     if(vis[b]==1) continue;
	     else{
	         vis[b]= 1;
	         mst.push_back({b,c});
	         weight+=a;
	     }
	 }
	 for(auto &x: mst) cout<<"{"<<x.first<<","<<x.second<<"}"<<" ";
	 cout<<endl;
	 cout<<"weight : "<<weight<<endl;
	 
	 
	 
 	
 }
