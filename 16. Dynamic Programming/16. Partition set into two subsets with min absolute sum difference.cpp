// Recursive sol, TC- O(2^n), SC- O(N)


// int dp(int i, int s1, int s2, vector<int>& nums){
// 	if(i==0){
// 		return min(abs(s1+nums[0]-s2),abs(s1-s2-nums[0]));
// 	}
// 	int one = dp(i-1,s1+nums[i],s2,nums);
// 	int two = dp(i-1,s1,s2+nums[i],nums);
// 	return min(one,two);
// }


// int minSubsetSumDifference(vector<int>& nums, int n)
// {
// 	return dp(n-1,0,0,nums);
// }


// // DP using memoization

// int dp(int i, int s1, int s2, vector<int>& nums,vector<vector<vector<int>>>  subsetSum){
// 	if(subsetSum[i][s1][s2]!=-1){
// 		return subsetSum[i][s1][s2];
// 	}
// 	if(i==0){
// 		return min(abs(s1+nums[0]-s2),abs(s1-s2-nums[0]));
// 	}
// 	int one = dp(i-1,s1+nums[i],s2,nums,subsetSum);
// 	int two = dp(i-1,s1,s2+nums[i],nums,subsetSum);
// 	return subsetSum[i][s1][s2] =  min(one,two);
// }


// int minSubsetSumDifference(vector<int>& nums, int n)
// {
// 	int totalSum = accumulate(nums.begin(),nums.end(),0);
// 	vector<vector<vector<int>>> subsetSum(n,vector<vector<int>>(totalSum,vector<int>(totalSum,-1)));

// 	return dp(n-1,0,0,nums,subsetSum);
// }

// DP using tabulation

int minSubsetSumDifference(vector<int>& arr, int n)
{

	if(n==1)	return arr[0];
	int totalSum = accumulate(arr.begin(),arr.end(),0);
	vector<bool> prevSum(totalSum/2+1),curSum(totalSum/2+1);

    prevSum[0] = true;
    if(arr[0]<=totalSum){
        prevSum[arr[0]] = true;
    }
    curSum = prevSum;
    
    for(int i=1; i<n; i++){
        for(int target = 1; target<=totalSum/2; target++){
            bool not_taken = prevSum[target];
            bool taken = target>=arr[i]?prevSum[target-arr[i]] : false;
            curSum[target] = not_taken || taken;
        }
        prevSum = curSum;
        
    }
	int mini = 1e9;
    for(int target = 1; target<=totalSum/2; target++){
		if(curSum[target]){//subset with sum = target is possible
			int set1_sum = target;
			int set2_sum = totalSum-target;
			mini = min(mini,abs(set1_sum-set2_sum));
		}
	}

	return mini;
}



