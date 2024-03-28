auto fast = []{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return false;
}();

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> graph(n+1, vector<pair<int,int>>());
        for(auto &conn: times){
            graph[conn[0]].push_back({conn[1],conn[2]});
        }

        priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> >minHeap;
        vector<int> dist(n+1,INT_MAX);
        dist[k] = 0;
        
        minHeap.push({0,k});
        while(not minHeap.empty()){
            int time = minHeap.top().first;
            int node = minHeap.top().second;
            minHeap.pop();

            for(auto &nb:graph[node]){
                int newTime = time+nb.second;
                int nbNode = nb.first;
                if(newTime < dist[nbNode]){
                    dist[nbNode] = newTime;
                    minHeap.push({newTime, nbNode});
                }
            }
        }
        int maxCost = 0;
        for(int i=1; i<=n; i++){
            maxCost = max(dist[i], maxCost);
        }
        return maxCost == INT_MAX ? -1 : maxCost;
    }
};
