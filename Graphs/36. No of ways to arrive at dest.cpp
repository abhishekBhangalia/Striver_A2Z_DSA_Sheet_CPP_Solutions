auto fast= []{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return false;
}();


class Solution {

    const int MOD = 1e9+7;

public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> graph(n);
        for(auto &road:roads){
            graph[road[0]].push_back({road[1],road[2]});
            graph[road[1]].push_back({road[0],road[2]});
        }

        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>> > minHeap;
        vector<long long > dist(n, LONG_MAX);
        vector<long long> ways(n,0);
        n--;
        dist[0] = 0;
        ways[0] = 1;
        minHeap.push({0,0});

        while(not minHeap.empty()) {

            long long d = minHeap.top().first;
            int v = minHeap.top().second;
            minHeap.pop();

            // can be used
            // if(d>dist[v]) continue;

            for(auto &nb:graph[v]){
                long long nd =  d + nb.second;

                // if(nb.first == n ){
                //     if(d + nb.second == dist[n]){
                //         ways[n] = (ways[n] + ways[v]) % MOD;
                //     }
                //     else if(nd < dist[n]){
                //         dist[n] = nd;
                //         ways[n] = ways[v] % MOD;
                //     }
                //     continue;
                // }

                if(nd < dist[nb.first]){
                    dist[nb.first] = nd;
                    ways[nb.first] = ways[v] % MOD;
                    minHeap.push({nd, nb.first});
                }
                else if(nd == dist[nb.first]){
                    ways[nb.first] = (ways[nb.first] + ways[v]) % MOD;
                }
            }
        }
        return ways[n];
    }
};
