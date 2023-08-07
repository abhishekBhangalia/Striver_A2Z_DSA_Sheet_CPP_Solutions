class Solution {
public:

    // TC-O(3n), SC-O(1)
    void nextPermutation(vector<int>& nums) {
        int i=-1;
        for(int j=nums.size()-2; j>=0; j--){
            if(nums[j]<nums[j+1]){
                i=j;
                break;
            }
        }
        if(i==-1){
            reverse(nums.begin(),nums.end());
            return;
        }
        for(int j=nums.size()-1; j>i; j--){
            if(nums[j]>nums[i]){
                swap(nums[i],nums[j]);
                break;
            }
        }
        reverse(nums.begin()+i+1,nums.end());

    }
};
