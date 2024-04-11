class Solution {
     void dfs(int v,int parent, int t,  vector<int>& time, vector<int>& minTime, vector<int> graph[], vector<int>& vis, set<int>& artcPoints){
        vis[v] = 1;
        time[v] = t;
        minTime[v] = t;
        int children = 0;
        for(auto &nb : graph[v]){
            if(not vis[nb]){
                children++;
                dfs(nb, v, t+1, time, minTime, graph, vis, artcPoints);
                minTime[v] = min(minTime[v], minTime[nb]);
                if(minTime[nb] >= time[v] and parent != -1){
                    artcPoints.insert(v);
                }
            }else if(nb != parent){
                minTime[v] = min(minTime[v], time[nb]);
            }
        }
        if(parent == -1 and children > 1){
            artcPoints.insert(v);
        }
    }
    
    void dfs2(int v, vector<int> graph[], vector<int>& vis){
        vis[v] = 1;
        for(auto &nb : graph[v]){
            if(not vis[nb]){
                dfs2(nb, graph, vis);
            }
        }
    }

  public:
    vector<int> articulationPoints(int n, vector<int>adj[]) {
        vector<int> vis(n,0), time(n), minTime(n);
        set<int> artcPoints;
        vector<int> ans;
        //checking for root only
        // int children = 0; //total children of root which belong to different components
        // vis[0] = 1;
        // for(auto &nb : adj[0]){
        //     if(not vis[nb]){
        //         children++;
        //         dfs2(nb, adj, vis);
        //     }
        // }
        // if(children > 1){
        //     ans.push_back(0);
        // }
        
        
        // fill(vis.begin(), vis.end(), 0);
        for(int i=0; i<n; i++){
            if(not vis[i]){
                dfs(i,-1,0,time, minTime, adj, vis, artcPoints);
            }
        }
        
        copy(artcPoints.begin(), artcPoints.end(), std::back_inserter(ans));
        if (ans.empty()){
            return {-1};
        }
        return ans;
    }
};
