auto fast = []{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return false;
}();


// TC - O(2n)
// SC - O(1)
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long XOR = 0;
        for(auto &num : nums){
            XOR ^= num;
        }
        // XOR will store the xor of two numbers which are appearing once
        // now, we will find the right most set bit
        // this is the bit which is different in those two numbers
        // now, we will take two buckets and store xor of all numbers which has this bit set in one bucket
        // and store xor of all numbers which dont have this set bit in other bucket
        // as all other numbers appear twice and they will either go to bucket 1 or 2 so they will cancel each othe
        // ans finally we will left with those two numbers in these two buckets
        int rightmost_set_bit_no = XOR & -XOR; // if XOR is INT_MIN then XOR-1 will overflow if it is int so taking long
        int b1 = 0, b2 = 0;
        for(auto &num : nums){
            if (num & rightmost_set_bit_no){
                b1 ^= num;
            }
            else{
                b2 ^= num;
            }
        }
        return {b1, b2};
    }
};



// TC - O(2n)
// SC - O(1)
class Solution3 {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long XOR = 0;
        for(auto &num : nums){
            XOR ^= num;
        }
        // XOR will store the xor of two numbers which are appearing once
        // now, we will find the right most set bit
        // this is the bit which is different in those two numbers
        // now, we will take two buckets and store xor of all numbers which has this bit set in one bucket
        // and store xor of all numbers which dont have this set bit in other bucket
        // as all other numbers appear twice and they will either go to bucket 1 or 2 so they will cancel each othe
        // ans finally we will left with those two numbers in these two buckets
        int rightmost_set_bit_no = (XOR & (XOR-1)) ^ XOR; // if XOR is INT_MIN then XOR-1 will overflow if it is int so taking long
        int b1 = 0, b2 = 0;
        for(auto &num : nums){
            if (num & rightmost_set_bit_no){
                b1 ^= num;
            }
            else{
                b2 ^= num;
            }
        }
        return {b1, b2};
    }
};


// TC - O(n log n) + O(n)
// SC - O(1)
class Solution2 {
public:
    vector<int> singleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> ans;
        int n = nums.size();
        if(nums[0] != nums[1]){
            ans.push_back(nums[0]);
        }
        for(int i=1; i<n-1; i++){
            if(nums[i] != nums[i-1] and nums[i] != nums[i+1]){
                ans.push_back(nums[i]);
                if(ans.size() == 2){
                    return ans;
                }
            }
        }
        ans.push_back(nums[n-1]);
        return ans;
    }
};