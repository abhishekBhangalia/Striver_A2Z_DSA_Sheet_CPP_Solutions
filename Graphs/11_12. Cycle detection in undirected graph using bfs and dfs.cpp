class Graph {

public:

    // //bfs
    // bool detectCycle(int V, vector<int> adj[]) {
    //     int vis[V] = {0};
    //     for(int i=0; i<V; i++){
    //         if (vis[i] == 0){
    //             vis[i] = 1;
    //             queue<pair<int,int>> q; //storing vertex and parent
    //             q.push({i,-1});

    //             while(not q.empty()){
    //                 int v = q.front().first;
    //                 int p = q.front().second;
    //                 q.pop();
    //                 for(auto &nb:adj[v]){
    //                     if (!vis[nb]){
    //                         vis[nb] = 1;
    //                         q.push({nb, v});
    //                     }
    //                     else if (nb != p){
    //                         return true;
    //                     }
    //                 }
    //             }
    //         }
    //     }
    //     return false;
    // }

    bool rec(int v,int p, vector<int> adj[], vector<int>& vis){
        for(auto &nb:adj[v]){
            if(!vis[nb]){
                vis[nb] = 1;
                if (rec(nb, v, adj, vis)){
                    return true;
                }
            }
            else if (nb != p){
                return true;
            }
        }
        return false;
    }

    //dfs
    bool detectCycle(int V, vector<int> adj[]) {
        vector<int> vis(V,0);
        bool res = false;
        for(int i=0; i<V; i++){
            if (!vis[i]){
                vis[i] = 1;
                if (rec(i,-1,adj,vis)){
                    return true;
                }
            }
        }
        return false;
    }
    
};
