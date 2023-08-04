#include <bits/stdc++.h> 


// dp using recursion 

// bool dp(int i,int target,vector<int>& arr){
//     if(target == 0){
//         return true;
//     }
//     if(i == 0){
//         return target == arr[i];
//     }
//     bool not_taken = dp(i-1,target,arr);
//     bool taken = target>=arr[i]?dp(i-1,target-arr[i],arr) : false;
//     return not_taken or taken;
// }
// bool subsetSumToK(int n, int k, vector<int> &arr) {
//     // int sum = accumulate(arr.begin(),arr.end(),0);
//     // vector<vector<int>> subsetSum(n,vector<int>(sum+1,-1));
//     return dp(arr.size()-1,k,arr);
// }

// // // dp using memoization

// int dp(int i,int target,vector<int>& arr,vector<vector<int>>& sum){

//     if(sum[i][target]!=-1){
//         return sum[i][target];
//     }
//     if(target == 0){
//         return sum[i][target] = 1;
//     }
//     if(i == 0){
//         return sum[i][target] = target == arr[i];
//     }
//     bool not_taken = dp(i-1,target,arr,sum);
//     bool taken = target>=arr[i]?dp(i-1,target-arr[i],arr,sum) : 0;
//     return sum[i][target] = not_taken | taken;
// }
// bool subsetSumToK(int n, int k, vector<int> &arr) {
//     // int sum = accumulate(arr.begin(),arr.end(),0);
//     // vector<vector<int>> subsetSum(n,vector<int>(sum+1,-1));
//     vector<vector<int>> sum(n,vector<int>(k+1,-1));
//     return dp(arr.size()-1,k,arr,sum);
// }


// // dp using tabulation method
// bool subsetSumToK(int n, int k, vector<int> &arr) {
//     // int sum = accumulate(arr.begin(),arr.end(),0);
//     vector<vector<bool>> subsetSum(n,vector<bool>(k+1));

//     for(int i=0; i<n; i++){
//         subsetSum[i][0] = true;
//     }
//     if(arr[0]<=k){
    //     subsetSum[0][arr[0]] = true;
    // }



//     for(int i=1; i<n-1; i++){
//         for(int target = 1; target<=k; target++){
//             bool not_taken = subsetSum[i-1][target];
//             bool taken = target>=arr[i]?subsetSum[i-1][target-arr[i]] : false;
//             subsetSum[i][target] = not_taken || taken;
//         }
        
//     }
//     bool not_taken = subsetSum[n-2][k];
//     bool taken = k>=arr[n-1]?subsetSum[n-2][k-arr[n-1]] : false;
//     subsetSum[n-1][k] = not_taken || taken;

//     return subsetSum[n-1][k];
    
// }

// dp using tabulation method and space optimization
bool subsetSumToK(int n, int k, vector<int> &arr) {
    // int sum = accumulate(arr.begin(),arr.end(),0);
    vector<bool> prevSum(k+1),curSum(k+1);

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





