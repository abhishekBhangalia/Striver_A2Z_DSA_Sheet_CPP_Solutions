class Solution {
public:
    // void sortColors(vector<int>& nums) {
    //     int red=0;
    //     for(int i=0; i<nums.size();i++){
    //         if(nums[i]==0){
    //             swap(nums[red++],nums[i]);
    //         }
    //     }
    //     int white = red;
    //     for(int i=white; i<nums.size(); i++){
    //         if(nums[i]==1){
    //             swap(nums[white++],nums[i]);
    //         }
    //     }
    // }

    //Dutch National Flag Algorithm, TC- O(n), SC- O(1)

    void sortColors(vector<int>& nums) {
        int low=0,mid=0,high=nums.size()-1;
        while(mid<=high){
            if(nums[mid]==0){
                swap(nums[low],nums[mid]);
                low++;
                mid++;
            }
            else if(nums[mid]==1){
                mid++;
            }
            else{
                swap(nums[mid],nums[high]);
                high--;
            }
        }
        
    }

    // TC- O(2n), SC-O(3)
    // void sortColors(vector<int>& nums) {
    //     vector<int> count(3, 0);

    //     for (auto num: nums) {
    //         count[num] += 1;
    //     }

    //     int i = 0;
    //     for (int j = 0; j < 3; j++) {
    //         while (count[j]--) {
    //             nums[i] = j;
    //             i++;
    //         }
    //     }
    // }
};
