class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    //TC - O(E log(v)), h height of min heap
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> dis(V,INT_MAX);
        dis[S] = 0;
        pq.push({0,S});
        
        while(!pq.empty()){
            pair<int,int> v = pq.top();
            pq.pop();
            for(vector<int> u: adj[v.second]){
                if(dis[v.second]+u[1] < dis[u[0]]){
                    dis[u[0]] = dis[v.second] + u[1];
                    pq.push({dis[u[0]],u[0]});
                }
            }
        }
        
        return dis;
        
    }
};
