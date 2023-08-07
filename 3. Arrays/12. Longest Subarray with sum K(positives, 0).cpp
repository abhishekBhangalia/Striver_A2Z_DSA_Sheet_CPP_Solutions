#include <bits/stdc++.h>


// Not working 

// int longestSubarrayWithSumK(vector<int> a, long long k) {
//     // Write your code here
//     int cur_target = k;
//     int max_subarray_size = 0,cur_subarray_size=0;
//     for(int i=0; i<a.size(); i++){
//         if(a[i]<=cur_target){
//             cur_target-=a[i];
//             cur_subarray_size++;
//             if(cur_target == 0){
//                 max_subarray_size = max(max_subarray_size,cur_subarray_size);
                
//             }
//         }
//         else{
//             if(a[i]==k){
//                 max_subarray_size = max(max_subarray_size,1);
//             }
//             cur_target = k;
//             cur_subarray_size = 0;
//         }
//     }
//     return max_subarray_size;
// }


// // Brute Force(TLE) - O(N^2), SC- O(1) 
// int longestSubarrayWithSumK(vector<int> a, long long k) {
//     int max_subarray_size = 0;
//     for(int i=0; i<a.size(); i++){
//         long sum = 0;
//         for(int j=i; j<a.size(); j++){
//             sum+=a[j];
//             if(sum==k){
//                 max_subarray_size = max(max_subarray_size,j-i+1);
                
//             }
//             if(sum>k){
//                 break;
//             }
//         }
//     }
//     return max_subarray_size;
// }



// // Hashing -(TLE) O(N), SC- O(N) 
// int longestSubarrayWithSumK(vector<int> a, long long k) {
//     int max_subarray_size = 0;
//     map<long long,int> prevSumMap;
//     long long sum = 0;
//     for(int i=0; i<a.size(); i++){
//         sum += a[i];
//         if(sum == k){
//             max_subarray_size = max(max_subarray_size,i+1);
            
//         }
//         else{
//             if(prevSumMap.find(sum-k)!=prevSumMap.end()){
//                 max_subarray_size = max(max_subarray_size,i-prevSumMap[sum-k]);
//             }
            
//         }
//         if(a[i]!=0){
//             prevSumMap[sum] = i;
//         }
//     }
//     return max_subarray_size;
// }


// Two pointer, TC- O(2n), SC-(1)

int longestSubarrayWithSumK(vector<int> a, long long k) {
    // Write your code here
    int max_subarray_size = 0;
    
    long long sum = 0;
    int i=0,j=0;

    while(j<a.size()){
        sum+=a[j];
        while(sum>k){
            sum-=a[i++];
        }
        if(sum == k){
            max_subarray_size = max(max_subarray_size,j-i+1);
        }
        j++;
    }
    return max_subarray_size;
}
