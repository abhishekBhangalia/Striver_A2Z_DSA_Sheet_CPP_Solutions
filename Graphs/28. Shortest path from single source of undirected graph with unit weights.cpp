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

    vector<int> shortestPath2(vector<vector<int>>& edges, int N,int M, int src){
        vector<vector<int>> graph(N, vector<int>());
        for(auto &edge:edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        
        queue<pair<int,int>> q;
        q.push({src,0});
        vector<int> ans(N, INT_MAX);
        ans[src] = 0;
        
        while(not q.empty()) {
            pair<int,int> v = q.front();
            q.pop();
            
            for(auto &nb:graph[v.first]){
                if(ans[nb] > v.second + 1){
                    ans[nb] = v.second+1;
                    q.push({nb,ans[nb]});
                }
            }
        }
        for(int i=0; i<N; i++){
            if (ans[i] == INT_MAX){
                ans[i] = -1;
            }
        }
        return ans;
    }
};

class Solution2 {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        vector<vector<int>> graph(N, vector<int>());
        for(auto &edge:edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        
        queue<int> q;
        q.push(src);
        vector<int> dist(N, INT_MAX);
        dist[src] = 0;
        
        while(not q.empty()) {
            int v = q.front();
            q.pop();
            
            for(auto &nb:graph[v]){
                if(dist[nb] > dist[v] + 1){
                    dist[nb] = dist[v] + 1;
                    q.push(nb);
                }
            }
        }
        for(int i=0; i<N; i++){
            if (dist[i] == INT_MAX){
                dist[i] = -1;
            }
        }
        return dist;
    }
};

