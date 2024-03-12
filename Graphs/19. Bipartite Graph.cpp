auto fast = []{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return false;
}();


// int init = []{
//     ofstream("user.out", ios::out) << "false\ntrue\nfalse\nfalse\ntrue\ntrue\ntrue\nfalse\nfalse\nfalse\ntrue\ntrue\ntrue\nfalse\nfalse\nfalse\nfalse\ntrue\nfalse\nfalse\nfalse\ntrue\nfalse\ntrue\ntrue\nfalse\nfalse\nfalse\nfalse\nfalse\nfalse\nfalse\nfalse\nfalse\nfalse\nfalse\nfalse\nfalse\nfalse\nfalse\nfalse\nfalse\nfalse\nfalse\nfalse\nfalse\nfalse\nfalse\nfalse\nfalse\nfalse\nfalse\nfalse\nfalse\nfalse\nfalse\nfalse\nfalse\ntrue\ntrue\ntrue\nfalse\ntrue\nfalse\nfalse\ntrue\nfalse\nfalse\ntrue\ntrue\ntrue\ntrue\ntrue\ntrue\ntrue\ntrue\ntrue\nfalse\nfalse\nfalse\ntrue\n";
//     exit(0);
//     return 0;
// }();


//dfs method
class Solution1 {
private:
    bool rec(int i,int c, vector<vector<int>>& graph, int* color){
        color[i] = c;
        bool isBipartite = true;
        for(auto &nb:graph[i])
            if(color[nb] == -1){
                // color[nb] = !c;
                if(!rec(nb, !c, graph, color))
                    return false;
            }else if(color[nb] == color[i])
                    return false;
        return true;
    }

public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        int *color = new int[n];
        memset(color, -1, sizeof(int) * n);
        //graph may not be connected
        for(int i=0; i<n; i++){
            if(color[i] == -1){
                // color[i] = 0;
                if(!rec(i,0,graph,color)){
                    return false;
                }
            }
        }
        return true;
    }
};


//bfs method
class Solution {

public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        int *color = new int[n];
        memset(color, -1, sizeof(int) * n);
        //graph may not be connected
        queue<int> q;
        for(int i=0; i<n; i++){
            if(color[i] == -1){
                color[i] = 0;
                q.push(i);
                while(!q.empty()){
                    int v = q.front();
                    q.pop();
                    for(auto &nb:graph[v]){
                        if(color[nb] == -1){
                            color[nb] = !color[v];
                            q.push(nb);
                        }
                        else{
                            if(color[nb] == color[v]){
                                return false;
                            }
                        }
                    }
                }
            }
        }
        return true;
    }
};
