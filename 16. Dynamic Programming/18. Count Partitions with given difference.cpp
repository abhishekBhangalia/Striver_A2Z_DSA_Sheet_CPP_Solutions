#include <bits/stdc++.h> 


// dp using tabulation

int countPartitions(int n, int d, vector<int> &arr) {
    // Write your code here.
    int sum = accumulate(arr.begin(),arr.end(),0);
    // We know that,
    // s1 = sum - s2
    // and ATQ,
    // s1 - s2 = d
    // s1 - (sum - s1) = d
    // 2s1 - sum = d
    // s1 = (sum+d)/2

    // so, we can find total subsets having sum s1
    int target = (sum+d)/2;

    if(sum+d < 0 or (sum+d)%2!=0){// as all elements are integers so target can't be float
        return 0;
    }

    vector<int> prevSubsetSum(target+1,0),curSubsetSum(target+1,0);

    if(arr[0]==0){
        prevSubsetSum[0] = 2;
    }
    else{
        prevSubsetSum[0] = 1;
    }
    if(arr[0]!=0 and arr[0]<=target){
        prevSubsetSum[arr[0]] = 1;
    }
    curSubsetSum = prevSubsetSum;
    for(int i=1; i<n-1; i++){
        for(int t=0; t<=target; t++){
            int take = arr[i]<=t ? prevSubsetSum[t-arr[i]] : 0;
            int not_take = prevSubsetSum[t];
            curSubsetSum[t] = (take + not_take)%(int)(1e9+7);
        }
        prevSubsetSum = curSubsetSum;
    }
    int take = arr[n-1]<=target ? prevSubsetSum[target-arr[n-1]] : 0;
    int not_take = prevSubsetSum[target];
    curSubsetSum[target] = (take + not_take)%(int)(1e9+7);

    return curSubsetSum[target];
    
}



