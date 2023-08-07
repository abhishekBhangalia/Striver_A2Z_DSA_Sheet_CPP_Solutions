class Solution {
public:

    // // Brute force, TC-O(2n), SC - O(n)
    // int majorityElement(vector<int>& nums) {
    //     unordered_map<int,int> map;
    //     for(int i:nums){
    //         map[i]++;
    //     }
    //     int n = nums.size();
    //     n/=2;
        
    //     for(auto i:map){
    //         if(i.second > n){
    //             return i.first;
    //         }
    //     }
    //     return -1;
    // }

    
    // Moore's Voting Algo, TC-O(n), SC- 

    int majorityElement(vector<int>& nums){
        int maj_el=nums[0];
        int count = 1;
        for(int i=1; i<nums.size(); i++){
            if(count==0){
                maj_el = nums[i];
                count = 1;
            }
            else if(nums[i]==maj_el){
                count++;
            }
            else{
                count--;
            }
        }

        //if there may or may not be the majority element then we need to check again whether the maj_el is actually the majority element or not.
        //But as it is given that majority element will exist always so the code below is not needed

        // count = 0;
        // for(int i=0; i<nums.size(); i++){
        //     if(nums[i]==maj_el){
        //         count++;
        //     }
        // }
        // if(count>nums.size()/2){
        //     return maj_el;
        // }
        // else{
        //     return -1;
        // }

        return maj_el;
    }


};
