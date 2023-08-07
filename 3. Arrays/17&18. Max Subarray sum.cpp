class Solution {
public:

    // Brute force (TLE), TC-O(n^2), SC - O(1)
    // int maxSubArray(vector<int>& nums) {
    //     int max_sum = INT_MIN;
    //     int sum;
    //     for(int i=0; i<nums.size(); i++){
    //         sum = 0;
    //         for(int j=i; j<nums.size(); j++){
    //             sum += nums[j];
    //             max_sum = max(sum,max_sum);
    //         }
    //     }
    //     return max_sum;
    // }
 

    // Kadane's Algo, TC-O(n), SC-O(1)
    int maxSubArray(vector<int>& nums){
        int max_sum = INT_MIN;
        int sum=0;

        for(int i=0; i<nums.size();i++){
            sum+=nums[i];
            max_sum = max(max_sum,sum);
            if(sum<0){
                sum = 0;
            }
        }

        // if empty subarray can also be taken
        // if(max_sum<0)   return 0;//if all elements are negative then we can select empty subarray with sum 0

        return max_sum;
    }


    // if max subarray has to be printed also

    // int maxSubArray(vector<int>& nums){
    //     int max_sum = INT_MIN;
    //     int sum=0;

    //     int start,end;

    //     for(int i=0; i<nums.size();i++){
    //         sum+=nums[i];
    //         if(sum>max_sum){
    //             max_sum = sum;
    //             end = i;
    //         }
    //         if(sum<0){
    //             start = i+1;
    //             sum = 0;
    //         }
    //     }

    //     // print the subarray

    //     for(int i=start; i<=end; i++){
    //         cout<<nums[i];
    //     }



    //     // if empty subarray can also be taken
    //     // if(max_sum<0)   return 0;//if all elements are negative then we can select empty subarray with sum 0

    //     return max_sum;
    // }
};
