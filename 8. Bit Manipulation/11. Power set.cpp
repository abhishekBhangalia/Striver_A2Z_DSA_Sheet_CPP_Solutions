auto fast = []{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return false;
}();

class Solution2 {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        int total_subsets = 1 << n; //2^n
        for(int i=0; i<total_subsets; i++){
            int j = 0;
            int k = i;
            vector<int> tmp;
            while(k>0){
                if(k & 1){
                    tmp.push_back(nums[j]);
                }
                j++;
                k = k >> 1;
            }
            ans.push_back(tmp);
        }
        return ans;
    }
};

class Solution3 {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size(), k = (1 << n);
        vector<vector<int>> ans(k);
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < n; j++) {
                if ((1 << j) & i) {
                    ans[i].push_back(nums[j]);
                }
            }
        }
        return ans;
    }
};


class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size(), k = (1 << n);
        vector<vector<int>> ans(k);
        for (int i = 0; i < k; i++) {
            int j = 0;
            int k = i;
            while(k>0){
                if ( k & 1) {
                    ans[i].push_back(nums[j]);
                }
                k = k >> 1;
                j ++;
            }
        }
        return ans;
    }
};