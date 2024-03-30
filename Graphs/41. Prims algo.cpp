#include <bits/stdc++.h>

//Prims algorithm
int minimumSpanningTree(vector<vector<int>>& edges, int n)
{
    vector<vector<pair<int,int>>> graph(n);
    for(auto &e:edges){
        graph[e[0]].push_back({e[1],e[2]});
        graph[e[1]].push_back({e[0],e[2]});
    }

    int cost = 0;
    vector<int> vis(n);
    priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int,int>> > mh;
    // vis[0] = 1;
    mh.push({0,0}); //{cost, vertex}

    while(not mh.empty()){
        int v = mh.top().second;
        int c = mh.top().first;
        mh.pop();
        if( vis[v] == 0){
            vis[v] = 1;
            cost += c;
            for(auto &nb:graph[v]){
                if(vis[nb.first] == 0){
                    mh.push({nb.second,nb.first});
                }
            }
        }
    }
    return cost;
}
