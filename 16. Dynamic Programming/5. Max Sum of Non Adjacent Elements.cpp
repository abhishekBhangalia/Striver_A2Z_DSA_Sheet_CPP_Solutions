#include <bits/stdc++.h> 


// int dp(vector<int>& nums, int cur_in,vector<int>& sums){
//     if(cur_in < 0){
//         return 0;
//     }
//     if(cur_in == 0){
//         return nums[0];
//     }
   
//     if(sums[cur_in]){
//         return sums[cur_in];
//     }
//     int not_selected_sum = dp(nums,cur_in-1,sums);
    
//     int selected_sum = nums[cur_in] + dp(nums,cur_in-2,sums); 
//     return sums[cur_in] = max(selected_sum,not_selected_sum);
// }


// //dp using memoization
// int maximumNonAdjacentSum(vector<int> &nums){
//     // Write your code here.
//     vector<int> sums(nums.size(),0);
//     return dp(nums,nums.size()-1,sums);

// }




// //dp using tabulation 
// int maximumNonAdjacentSum(vector<int> &nums){
//     // Write your code here.
//     vector<int> dp(nums.size(),0);
//     dp[0] = nums[0];
//     dp[1] = max(nums[1],nums[0]);

//     for(int i=2; i<nums.size(); i++){
//         int selected = nums[i]+dp[i-2];
//         int not_selected = dp[i-1];
//         dp[i] = max(selected,not_selected);
//     }
    
//     return dp[nums.size()-1];

// }

//dp using tabulation and space optimization
int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    if(nums.size()==1){
        return nums[0];
    }
    
    
    int prev1_cost,prev2_cost,max_cost;
    prev2_cost = nums[0];
    prev1_cost = max(nums[1],nums[0]);

    if(nums.size()==2){
        return prev1_cost;
    }

    for(int i=2; i<nums.size(); i++){
        int selected = nums[i]+prev2_cost;
        int not_selected = prev1_cost;
        max_cost = max(selected,not_selected);
        prev2_cost = prev1_cost;
        prev1_cost = max_cost;
    }
    
    return max_cost;

}





