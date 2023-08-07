class Solution {
public:

    // Brute Force (TLE), TC-O(n^2), SC-O(1)
    // int maxProfit(vector<int>& prices) {
    //     int max_profit = 0;
    //     for(int i=prices.size()-1; i>0;i--){
    //         for(int j=i-1; j>=0; j--){
    //             if(prices[i]>prices[j]){
    //                 max_profit = max(max_profit,prices[i]-prices[j]);
    //             }
    //         }
    //     }
    //     return max_profit;
    // }

    // DP, TC-O(n), SC-O(1)
    int maxProfit(vector<int>& prices) {
        int max_profit = 0;
        int min_price = prices[0];
        for(int i=1; i<prices.size();i++){
            max_profit = max(max_profit,prices[i]-min_price);
            min_price = min(min_price,prices[i]);
        }
        return max_profit;
    }
};
