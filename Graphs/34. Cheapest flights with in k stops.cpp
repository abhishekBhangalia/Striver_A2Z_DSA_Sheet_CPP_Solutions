auto fast = []{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return false;
}();

// class Solution {
// public:
//     int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
//         vector<pair<int, int>> adjList[n];
//         vector<int> price(n, 1e9);
//         price[src] = 0;
//         for(int i = 0; i < flights.size(); i++){
//             adjList[flights[i][0]].push_back({flights[i][1], flights[i][2]});
//         }

//         priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

//         pq.push({0, {0, src}});

//         while(!pq.empty()){
//             int city = pq.top().second.second;
//             int cost = pq.top().second.first;
//             int stops = pq.top().first;

//             pq.pop();
             
//             for(auto it: adjList[city]){
//                 if(stops <= k){
//                     if(cost + it.second < price[it.first]){
//                         price[it.first] = cost + it.second;
//                         pq.push({stops + 1, {price[it.first], it.first}});
//                     }
//                 }
//             }
//         }
        
//         return price[dst] == 1e9? -1: price[dst];        
//     }
// };

//tc-4ms
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        vector<vector<pair<int,int>>> graph(n,vector<pair<int,int>>());
        for(auto &f : flights){
            graph[f[0]].push_back({f[1], f[2]});
        }

        int dist[n];
        memset(dist, 0x7f, sizeof(dist));
        //2147483200
        // same as above line 
        // memset(dist, INT_MAX, sizeof(int)*n);

        //pair will contain {total price of path, total nodes used in path}
        
        // priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>> mh;

        queue<pair<int, pair<int,int>>> mh;
        mh.push({0,{src,0}}); 
        dist[src] = 0;
        int minCost = INT_MAX;
        // stps in needed if minheap is used but it should not be used as tc will be very much 
        // vector<int> stps(n);
        
        while(not mh.empty()){
            int stops = mh.front().second.second;
            if(stops > k){
                mh.pop();
                continue;
            }
            int cost =  mh.front().first;
            int curStop = mh.front().second.first;
            mh.pop();

            // if(curStop == dst and stops-2 <= k){
            //     minCost = min(cost, minCost);
            // }
            for(auto &nb : graph[curStop]){
                int ncost = cost + nb.second;
                int nstop = nb.first;
                if(nstop == dst){
                    if(stops <= k){
                        minCost = min(ncost, minCost);
                    }
                    continue;
                }
                else if(ncost < dist[nstop] and stops<k){
                    dist[nstop] = ncost;
                    // stps[nstop] = stops+1;
                    mh.push({ncost, {nstop,stops+1}});
                }
            }
        }
        return minCost == INT_MAX ? -1 : minCost;
    }
};

//todo : understand this approach
class Solution2 {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<int> dp(n, 1e8);
        dp[src] = 0;
        for(int k = 0; k <= K; k++) {
            vector<int> temp = dp;
            for(auto& flight : flights) {
                int u = flight[0], v = flight[1], w = flight[2];
                temp[v] = min(temp[v], dp[u] + w);
            }
            dp = temp;
        }
        return dp[dst] == 1e8 ? -1 : dp[dst];
    }
};


