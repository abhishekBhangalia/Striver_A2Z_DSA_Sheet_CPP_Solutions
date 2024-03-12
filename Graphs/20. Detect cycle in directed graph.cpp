bool rec(int v, vector<vector<int>>& graph, vector<int>& vis, vector<int>& pathVis){
	vis[v] = 1;
	pathVis[v] = 1;
	for(auto &nb:graph[v]){
		if(vis[nb] == 0){
			// vis[nb] = 1;
			// pathVis[nb] = 1;
			if(rec(nb, graph, vis, pathVis))	return true;
			// pathVis[nb] = 0;
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

bool isCyclic(vector<vector<int>>& edges, int v, int e)
{
	vector<vector<int>> graph(v,vector<int>());
	for(int i=0; i<edges.size(); i++){
		graph[edges[i][0]].push_back(edges[i][1]);
	}
	vector<int> vis(v,0);
	vector<int> pathVis(v,0);
	for(int i=0; i<v; i++){
		if(vis[i] == 0){
			if(rec(i, graph, vis, pathVis)){
				return true;
			}
		}
	}
	return false;
}
