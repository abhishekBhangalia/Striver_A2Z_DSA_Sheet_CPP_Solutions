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
    int longestOnes(vector<int>& nums, int k) {
        int cnt = 0, l = 0, r = 0;
        while(r < nums.size())
        {
            if(nums[r] == 0) cnt++;
            // we will not use while loop here because only size is needed and this will save time
            if(cnt > k)
            {
                cnt -= nums[l] == 0;
                l++;
            }
            r++;
        }
        return r-l;
    }
};


// TC - O(n)
// SC - O(k)
class Solution2 {
public:
    int longestOnes(vector<int>& nums, int k) {
        deque<int> zeros_index;
        int l = 0, r = 0, n = nums.size(), ans = 0;

        if(k==0){
            while(r<n){
                if(nums[r] == 0){
                    r++;
                    l = r;
                    continue;
                }
                ans = max(ans, r-l+1);
                r++;
            }
            return ans;
        }

        while(r<n){
            if(nums[r] == 0){
                if(zeros_index.size() == k){
                    l = zeros_index.front()+1;
                    zeros_index.pop_front();
                    zeros_index.push_back(r);   
                }
                else{
                    zeros_index.push_back(r);
                }
            }
            ans = max(ans, r-l+1);
            r++;
        }
        return ans;
    }
};


// TC - O(2n)
// SC - O(1)
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int cnt = 0, l = 0, r = 0;
        while(r < nums.size())
        {
            if(nums[r] == 0) cnt++;
            while(cnt > k)
            {
                cnt -= nums[l] == 0;
                l++;
            }
            r++;
        }
        return r-l;
    }
};
