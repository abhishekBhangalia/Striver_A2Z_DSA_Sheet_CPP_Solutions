class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        int indegree[V]={0};
	    vector<int> ans;
	    
	    
	    for(int i=0; i<V; i++){
	        for(int v: adj[i]){
	            indegree[v]++;
	        }
	    }
	    
	    queue<int> q;
	    for(int i=0; i<V; i++){
	        if (indegree[i]==0){
	            q.push(i);
	            V--;
	        }
	    }
	    
	    while(!q.empty()){
	        int u = q.front();
	        q.pop();
	        ans.push_back(u);
	        for(int v:adj[u]){
	            if(--indegree[v] == 0){
	                q.push(v);
	                V--;
	            }
	        }
	    }
      //topo sort is possible for dag only. it always contains v vertices.
      //if topo sort contains vertices less than v then it means the graph has cycle
	    if (V!=0){
	        return true;
	    }
	    return false;
    }
};
