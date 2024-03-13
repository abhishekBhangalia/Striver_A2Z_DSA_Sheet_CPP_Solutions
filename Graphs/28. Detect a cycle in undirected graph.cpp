// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        // code here
        vector<int> dist(N,-1);
        vector<vector<int>> adj(N,vector<int>());
        vector<int> vis(N,0);
        
        for(vector<int> edge:edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        queue<int> q;
        q.push(src);
        dist[src] = 0;
        int dis = 0;
        vis[src] = 1;
        while(!q.empty()){
            dis++;
            int size = q.size();
            while(size--){
                int v = q.front();
                q.pop();
                
                for(int u:adj[v]){
                    if(vis[u]==0){
                        vis[u] = 1;
                        dist[u]=dis;
                        q.push(u);
                    }
                }
            }
        }
        return dist;
    }
};
