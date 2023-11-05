#include <bits/stdc++.h>

// dp using memoization
// TC-O(n*k), SC-O(n) + O(n)(auxialiary stack space)
// int dp(int n, int k, vector<int>& height, vector<int>& cost){
//     if(n==1){
//         return 0;
//     }
//     if(n==2){
//         return abs(height[1]-height[0]);
//     }
//     int min_cost = INT_MAX;
//     for(int i=1; i<=k; i++){
//         if(n-i<1)   break;
//         if(cost[n-i]==0){
//             cost[n-i] = dp(n-i,k,height,cost);
//         }

       
//         min_cost = min(min_cost,cost[n-i]+abs(height[n-1]-height[n-1-i]));
//     }
//     return min_cost;
// }

// int minimizeCost(int n, int k, vector<int> &height){
//     // Write your code here.
//     vector<int> cost(n+1,0);
//     return dp(n,k,height,cost);

// }

// dp using tabulation method
// TC-O(n*k), SC-O(n)
// int minimizeCost(int n, int k, vector<int> &height){
//     // Write your code here.
//     vector<int> cost(n+1,0);
//     cost[2] = abs(height[1]-height[0]);

//     for(int stone = 3; stone<=n; stone++){
//         int min_cost = INT_MAX;
//         for(int i=1; i<=k; i++){
//             if(stone-i < 1) break;
//             int cur_cost = cost[stone-i]+abs(height[stone-1]-height[stone-1-i]);
//             min_cost = min(min_cost,cur_cost);
//         }
//         cost[stone] = min_cost;
//     }
//     return cost[n];
// }


// dp using tabulation and further space optimization
// TC-O(n*k), SC-O(k)
int minimizeCost(int n, int k, vector<int> &h){
    // Write your code here.
    int* cost = new int[k];
    cost[0] = 0;

    for(int stone = 1; stone<n; stone++){
        int min_cost = INT_MAX;
        for(int step=1; step<=k && stone-step>=0; step++){
            int cur_cost = cost[(stone-step)%k] + abs(h[stone]-h[stone-step]);
            min_cost = min(min_cost,cur_cost);
        }
        cost[stone%k] = min_cost;
    }
    return cost[(n-1)%k];
}

