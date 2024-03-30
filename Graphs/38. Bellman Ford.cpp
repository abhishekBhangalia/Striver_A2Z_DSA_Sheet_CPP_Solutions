// User function Template for C++

class Solution {
  public:
    /*  Function to implement Bellman Ford
    *   edges: vector of vectors which represents the graph
    *   S: source vertex to start traversing graph with
    *   V: number of vertices
    */
    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        vector<int> shrt_dist(V, 1e8);
        shrt_dist[S] = 0;
        
        int n = V-1;
        while(n--){
            for(auto& edge: edges){
                if(shrt_dist[edge[0]] != 1e8 and shrt_dist[edge[0]]+edge[2] < shrt_dist[edge[1]]){
                    shrt_dist[edge[1]] = shrt_dist[edge[0]]+edge[2];
                }
            }
        }
        //checking for negative cycle
        for(auto& edge: edges){
            if(shrt_dist[edge[0]] != 1e8 and shrt_dist[edge[0]]+edge[2] < shrt_dist[edge[1]]){
                return {-1};
            }
        }
        return shrt_dist;
    }
};
