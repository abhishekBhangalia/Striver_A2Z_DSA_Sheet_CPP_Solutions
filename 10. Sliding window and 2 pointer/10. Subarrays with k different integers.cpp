// TC - O(2n)
// SC - O(n)
class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        return subarraysWithLessThanEqualToKDistinct(nums, k) - subarraysWithLessThanEqualToKDistinct(nums, k-1);
    }

    int subarraysWithLessThanEqualToKDistinct(vector<int>& nums, int k){
        int n = nums.size(), l = 0, r = 0, distincts = 0, ans = 0;
        vector<int> freq(n+1);
        
        while(r < n){
            distincts += ++freq[nums[r]] == 1;
            while(distincts > k){
                distincts -= --freq[nums[l++]] == 0;
            }
            ans += r-l+1;
            r++;
        }
        return ans;
    }
};



// TLE
// TC - O(n^2)
// SC - O(n)
class Solution2 {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n = nums.size(), l = 0, r = 0, distincts = 0, ans = 0;
        vector<int> freq(n+1);
        
        for(int i=0; i<n; i++){
            fill(freq.begin(), freq.end(), 0);
            l = i;
            r = i;
            distincts = 0;
            for(int j=i; j<n; j++){
                freq[nums[j]]++;
                if(freq[nums[j]] == 1){
                    distincts++;
                }
                if(distincts == k){
                    ans++;
                }
                else if(distincts > k){
                    break;
                }
            }
        }
        return ans;
    }
};




