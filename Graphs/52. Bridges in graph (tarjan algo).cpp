auto fast = []{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return false;
}();

class Solution {

    void dfs(int v,int parent, int t,  vector<int>& time, vector<int>& minTime, vector<vector<int>>& graph, vector<int>& vis, vector<vector<int>>& critConn){
        vis[v] = 1;
        time[v] = t;
        minTime[v] = t;
        for(auto &nb : graph[v]){

            // this is also correct
            // if(nb != parent){
            //     if(not vis[nb]){
            //         dfs(nb, v, t+1, time, minTime, graph, vis, critConn);
            //     }
            //     minTime[v] = min(minTime[v], minTime[nb]);
            //     if(minTime[nb] > time[v]){
            //         critConn.push_back({v,nb});
            //     }
            // }

            if(not vis[nb]){
                dfs(nb, v, t+1, time, minTime, graph, vis, critConn);
                minTime[v] = min(minTime[v], minTime[nb]);
                if(minTime[nb] > time[v]){
                    critConn.push_back({v,nb});
                }
            }else if(nb != parent){
                minTime[v] = min(minTime[v], minTime[nb]);
            }
        }
    }


public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int> vis(n,0), time(n), minTime(n);
        vector<vector<int>> critConn;
        vector<vector<int>> graph(n);
        for(auto &c: connections){
            graph[c[0]].push_back(c[1]);
            graph[c[1]].push_back(c[0]);
        }
        dfs(0,-1,0,time, minTime, graph, vis, critConn);
        return critConn;
    }
};

//takes less space
class Solution2 {
    typedef vector<vector<int>> matrix_t;
public:
    void dfs(int node, int prev, matrix_t& matrix, vector<bool>& visited, vector<int>& distance, int counter, vector<vector<int>>& answer) {
        visited[node] = true;
        distance[node] = counter;
        int cnt = distance[node];
        for (int adj : matrix[node]) {
            if (adj == prev) {
                continue;
            }
            if (visited[adj]) {
                distance[node] = min(distance[adj], distance[node]);
            } else {
                dfs(adj, node, matrix, visited, distance, cnt + 1, answer);
                distance[node] = min(distance[adj], distance[node]);
                if (cnt < distance[adj]) {
                    answer.push_back({node, adj});
                }
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        matrix_t matrix(n, vector<int>{});
        for (auto& conn : connections) {
            matrix[conn[0]].push_back(conn[1]);
            matrix[conn[1]].push_back(conn[0]);
        }
        connections.clear();
        vector<int> distance(n, 0);
        int counter = 0;
        vector<bool> visited(n, false);
        vector<vector<int>> answer{};
        dfs(0, -1, matrix, visited, distance, counter, answer);
        return answer;
    }
};
