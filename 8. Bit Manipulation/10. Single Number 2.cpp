auto fast = []{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return false;
}();


// TC - O(n)
// SC - O(1)
class Solution {
public:

    int singleNumber(vector<int>& nums) {
        // ones will store bits which appear 3x + 1 times  in nums
        // twos will store bits which appear 2x times in nums
        // threes will store bits which appear 3x times in nums
        // threes is not needed here because 
        // we will store bits of num in ones if it is not in twos
        // we will store bits of num in twos if it is not in threes 
        // and we need to store bits of num in threes if it is not in twos.
        // but here when bits are not in twos
        // we are adding then to ones
        // then if a bit appears second time, then we are removing it from ones and then adding it to twos
        // similary if bit appears third time, then we are removing it from twos first and then adding it to threes.
        // but adding it to threes is not necessary because if bit appears 4th time then we need to store it to ones and for that we just need to check whether it is present in twos or not. 
        // so, there is no need to store bit which appears third time to threes, just removing it from twos will be sufficient

        // since it is bitwise so after iterating through all numbers the bits that appear 3x+1 times will be stored in ones
        // as all numbers except one are appearing 3x times so bits of these numbers will not be set in ones
        // only the bits which appear once will remaing as set atlast
        int ones = 0, twos = 0, threes = 0;
        for(auto & num : nums){
            ones = (ones ^ num) & ~twos;
            twos = (twos ^ num) & ~ones;
            // threes = (threes ^ num) & ~twos;
        }
        return ones;
    }
};


// TC - O(n log(n)) + O(n/3)
// this will be better than solution 3 when log (n) < 32
// -> n < 2^32
// here n < 2^32, so it is better than solution 3 
// SC - O(1)
class Solution2 {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i=1; i<n; i+=3){
            if(nums[i] != nums[i-1]){
                return nums[i-1];
            }
        }
        // if single number is at last postion then return it
        return nums[n-1];
    }
};



// TC - O(32 * n)
// SC - O(1)
class Solution3 {
public:

    int singleNumber(vector<int>& nums) {
        int cnt = 0;
        int ans = 0;
        while(cnt < 32){ // we need to right shift 32 times because number can be negative also
            int total_set_bits = 0; // total set bits at postion cnt of all numbers in num
            for(auto &num : nums){
                if(num & 1){
                    total_set_bits++;
                }
                num = num >> 1;
            }
            if(total_set_bits % 3 != 0){
                ans = ans | (1 << cnt);
            }
            cnt++;
        }
        return ans;
    }
};