class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    //TC - O(E log(v)), h height of min heap
    vector<int> dijkstra(int n, vector<vector<int>> edges, int S)
    {
        // Code here
	    S = 0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<vector<pair<int,int>>> graph(n);
        for(auto &e : edges){
            graph[e[0]].push_back({e[1],e[2]});  
            graph[e[1]].push_back({e[0],e[2]});  
        }
        
        vector<int> dis(n,INT_MAX);
        dis[0] = 0;
        pq.push({0,0});
        
        while(!pq.empty()){
            pair<int,int> v = pq.top();

            pq.pop();
            
            if(v.first != dis[v.second])
                continue;
            for(auto &u: graph[v.second]){
                
                int newDis = dis[v.second]+u.second;
                if(newDis < dis[u.first] and newDis < disappear[u.first]){
                    dis[u.first] = newDis;
                    pq.push({dis[u.first],u.first});
                }
            }
        }
        
        for(auto &x : dis){
            if(x == INT_MAX){
                x = -1;
            }
        }
        return dis;
        
        // set<pair<int,int>> st; 

        // vector<int> dist(n, INT_MAX); 
        
        // st.insert({0, 0}); 

        // dist[0] = 0;
        
        // while(!st.empty()) {
        //     auto it = *(st.begin()); 
        //     int node = it.second; 
        //     int dis = it.first; 
        //     st.erase(it); 
            
        //     for(auto &it : graph[node]) {
        //         int adjNode = it.first; 
        //         int edgW = it.second; 
        //         int newDis = dis + edgW;
                
        //         if(newDis < dist[adjNode] and newDis < disappear[adjNode]) {

        //             if(dist[adjNode] != INT_MAX) 
        //                 st.erase({dist[adjNode], adjNode}); 

        //             dist[adjNode] = newDis; 
        //             st.insert({dist[adjNode], adjNode}); 
        //          }
        //     }
        // }
       
        // for(auto &x : dist){
        //     if(x == INT_MAX){
        //         x = -1;
        //     }
        // }
        // return dist; 
        
    }
};
