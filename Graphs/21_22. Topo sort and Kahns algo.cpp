class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
// 	vector<int> topoSort(int V, vector<int> adj[]) 
// 	{
// 	    // code here
// 	    //using DFS
// 	    int vis[V] = {0};
// 	    vector<int> st;
	    
// 	    for(int i=0; i<V; i++){
// 	        if(!vis[i]){
// 	            dfs(i,adj,st,vis);
// 	        }
// 	    }
// 	    reverse(st.begin(),st.end());
// 	    return st;
// 	}
	
// 	void dfs(int s,vector<int> adj[], vector<int>& st,int vis[]){
// 	    vis[s] = 1;
// 	    for(int v:adj[s]){
// 	        if(!vis[v]){
// 	            dfs(v,adj,st,vis);
// 	        }
// 	    }
// 	    st.push_back(s);
// 	}


    //Kahn's algorithm (topological sort using bfs)
    vector<int> topoSort(int V, vector<int> adj[]) 
	{
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
	        }
	    }
	    
	    while(!q.empty()){
	        int u = q.front();
	        q.pop();
	        ans.push_back(u);
	        for(int v:adj[u]){
	            if(--indegree[v] == 0){
	                q.push(v);
	            }
	        }
	    }
	    
	    return ans;
	}

};
