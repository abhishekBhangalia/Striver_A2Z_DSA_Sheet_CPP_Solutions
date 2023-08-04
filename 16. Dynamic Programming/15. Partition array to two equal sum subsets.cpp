class Solution {
public:

    //  recursive sol , TC-O(2^n), SC- O(n)

    // bool dp(int i,int sum1, int sum2, vector<int>& nums){
    //     if(i==0){
    //         return sum1+nums[i]==sum2 or sum2+nums[i]==sum1;
    //     }
    //     bool one = dp(i-1,sum1+nums[i],sum2,nums);
    //     bool two = dp(i-1,sum1,sum2+nums[i],nums);
    //     return one or two;
    // }

    // bool canPartition(vector<int>& nums) {
    //     return dp(nums.size()-1,0,0,nums);
    // }

    // dp using memoization

    // int dp(int i,int sum1, int sum2, vector<int>& nums,vector<vector<vector<int>>>& isSumEqual){
    //     if(isSumEqual[i][sum1][sum2]!=-1){
    //         return isSumEqual[i][sum1][sum2];
    //     }
    //     if(i==0){
    //         return isSumEqual[i][sum1][sum2] = sum1+nums[i]==sum2 or sum2+nums[i]==sum1;
    //     }
    //     int one = dp(i-1,sum1+nums[i],sum2,nums,isSumEqual);
    //     int two = dp(i-1,sum1,sum2+nums[i],nums,isSumEqual);
    //     return isSumEqual[i][sum1][sum2] = one or two;
    // }

    // bool canPartition(vector<int>& nums) {
    //     int sum = accumulate(nums.begin(), nums.end(),0);
    //     vector<vector<vector<int>>> isSumEqual(nums.size(),vector<vector<int>>(sum+1,vector<int>(sum+1,-1)));
    //     return dp(nums.size()-1,0,0,nums,isSumEqual);
    // }

   // dp using tabulation method and space optimization
    bool subsetSumToK( int k, vector<int> &arr) {
        // int sum = accumulate(arr.begin(),arr.end(),0);
        vector<bool> prevSum(k+1),curSum(k+1);
        int n = arr.size();
        prevSum[0] = true;
        if(arr[0]<=k){
            prevSum[arr[0]] = true;
        }
        curSum = prevSum;
        
        for(int i=1; i<n-1; i++){
            for(int target = 1; target<=k; target++){
                bool not_taken = prevSum[target];
                bool taken = target>=arr[i]?prevSum[target-arr[i]] : false;
                curSum[target] = not_taken || taken;
            }
            prevSum = curSum;
        }
        bool not_taken = prevSum[k];
        bool taken = k>=arr[n-1]?prevSum[k-arr[n-1]] : false;
        curSum[k] = not_taken || taken;

        return curSum[k];
    }


    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(),0);
        if(sum%2 != 0){
            return false; // if sum is odd then nums can't be parititioned into 2 equal sum partitions
        }
        return subsetSumToK(sum/2,nums);
    }
};
