#include <bits/stdc++.h> 


//  Hashing , TC-O(n*log n), SC- O(n) 

int getLongestSubarray(vector<int>& a, int k){
    // Write your code here
    int max_subarray_size = 0;
    map<long long,int> prevSumMap;
    long long sum = 0;
    for(int i=0; i<a.size(); i++){
        sum += a[i];
        if(sum == k){
            max_subarray_size = max(max_subarray_size,i+1);
            
        }
        else{
            if(prevSumMap.find(sum-k)!=prevSumMap.end()){
                max_subarray_size = max(max_subarray_size,i-prevSumMap[sum-k]);
            }
            
        }
        if(prevSumMap.find(sum)==prevSumMap.end()){
            prevSumMap[sum] = i;
        }
    }
    return max_subarray_size;
}





