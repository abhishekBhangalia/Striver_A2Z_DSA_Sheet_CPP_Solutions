class Solution {
  public:
      // TC- O(v+e)
      // SC - O(e) for recursion stack space, O(v) for topo stack, vis, dist, O(v+e)
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here
        vector<int> dist(N,INT_MAX);
        vector<int> vis(N,0);
        stack<int> topo;
        vector<vector<pair<int,int>>> adj(N,vector<pair<int,int>>());

       //O(e)
        for(vector<int> v: edges){
            adj[v[0]].push_back({v[1],v[2]});
        }
       //O(v+e)
        for(int i=0; i<N;i++){
            if(!vis[i]){
                dfs(i,adj,topo,vis);
            }
        }
        
        dist[0]=0;

       //O(v+e)
        while(!topo.empty()){
            int v = topo.top();
            //cout<<v;
            topo.pop();
            if(dist[v]==INT_MAX){//nodes which can't be visited from vertex 0 skip them
                continue;
            }
            for(pair<int,int> u:adj[v]){
                // cout<<u.first<<","<<u.second;
                dist[u.first] = min(dist[u.first],dist[v]+u.second);
            }
            
        }
        //O(v)
        for(int i=0; i<N; i++){
            if(dist[i]==INT_MAX){
                dist[i]=-1;
            }
        }
        
        return dist;
    }
    
    void dfs(int v,vector<vector<pair<int,int>>>& adj, stack<int>& topo, vector<int>& vis){
        vis[v]=1;
        for(pair<int,int> u:adj[v]){
            if(!vis[u.first]){
                dfs(u.first,adj,topo,vis);
            }
        }
        topo.push(v);
    }
};
