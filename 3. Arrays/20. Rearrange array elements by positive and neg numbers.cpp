class Solution {
public:

    // Brute - TC-O(2n), SC-O(n)
    // vector<int> rearrangeArray(vector<int>& nums) {
    //     vector<int> neg,pos;
    //     int i=0,j=0;
    //     for(int x:nums){
            
    //         if(x>=0){
    //             pos.push_back(x); 
    //         }
    //         else{
    //             neg.push_back(x);
                
    //         }
    //     }

       
    //     for(int i=0; i<nums.size()-1; i+=2){
    //         nums[i] = pos[i/2];
            
    //         nums[i+1] = neg[i/2];
            
    //     }
    //     return nums;
    // }


    //Optimal, TC-O(n), SC-O(n)
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> ans(nums.size());
        int i=0,j=1;
        for(int x:nums){
            if(x>=0){
                ans[i] = x;
                i+=2;
            }
            else{
                ans[j] = x;
                j+=2;
            }
        }
        return ans;
    }
};
