auto fast = []{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return false;
}();

class Solution {
private:
        bool detectCycle(int v, vector<vector<int>>& graph, vector<int>& vis, vector<int>& pathVis){
        if(vis[v] and pathVis[v] == 0){
            return false;
        }
        vis[v] = 1;
        pathVis[v] = 1;
        for(auto &nb:graph[v]){
            if(vis[nb] == 0){
                if(detectCycle(nb, graph, vis, pathVis))	return true;
            }
            else{
                if(pathVis[nb]==1){
                    return true;
                }
            }
        }
        pathVis[v] = 0;
        return false;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) { 
        int v = graph.size();
        vector<int> ans;       
        vector<int> vis(v,0);
        vector<int> pathVis(v,0);
        for(int i=0; i<v; i++){
            if(!detectCycle(i, graph, vis, pathVis)){
                ans.push_back(i);
            } 
        }
        return ans;
    }
};

class Solution2 {
public:
    bool dfs(int i,vector<vector<int>>& graph, vector<int> &vis, vector<int> &path, vector<int> &check){
        vis[i] = 1;
        path[i] = 1;
        check[i] = 0;
        for(auto &it:graph[i]){
            if(!vis[it]){
                if(dfs(it,graph,vis,path,check)){
                    return true;
                }
            }
            else if(path[it]) return true;
        }
        check[i] = 1;
        path[i] = 0;
        return false;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        // ios_base::sync_with_stdio(false);cin.tie(NULL);
        int n = graph.size();
        vector<int> vis(n,0),path(n,0),check(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,graph,vis,path,check);
            }
        }
        vector<int> res;
        for(int i=0;i<n;i++){
            if(check[i] == 1) res.push_back(i);
        }
        return res;
    }
};
