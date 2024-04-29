// 4ms
// TC - O(n)
// SC - O(1)
// but this approach is using nums array so SC is O(n)
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int lZero = -1, lOne = -1, prevOne = -1, r = 0, n = nums.size(), sum = 0, ans = 0;

        if(goal == 0){
            while(r < n){
                long long cnt = 0;
                while(r<n and nums[r] == 0){
                    r++;
                    cnt++;
                }
                ans += (cnt * (cnt+1) )/ 2;
                r++;
            }
            return ans;
        }

        while(r < n){
            if(nums[r]){
                sum++;
                
                if(lOne == -1){
                    lOne = r;
                    prevOne = r;
                    if(lZero == -1){
                        lZero = r;
                    }
                }
                else{
                    nums[prevOne] = r;
                    prevOne = r;
                }
                
            }else if(lZero == -1){
                lZero = r;
            }

            if(sum == goal){
                if(lOne == -1){
                    ans += (r - lZero + 1);
                    r++;
                    continue;
                }
                ans += (lOne - lZero + 1);
            }
            else if (sum > goal){
                sum-=2;
                lZero = lOne + 1;
                lOne = nums[lOne];
                continue;
            }
            r++;
        }
        return ans;
    }
};


// TC - O(n^2)
class Solution2 {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        
        int lZero = -1, rZero = -1, lOne = -1, rOne = -1, r = 0, n = nums.size(), sum = 0, ans = 0;
        while(r < n){
            if(nums[r]){
                sum++;
                
                if(lOne == -1){
                    lOne = r;
                    rOne = r;
                    if(lZero == -1){
                        lZero = r;
                    }
                }
                else{
                    rOne = r;
                }
                
            }else{
                if(lZero == -1){
                    lZero = r;
                    rZero = r;
                }
                else{
                    rZero = r;
                }
            }
            if(sum == goal){
                if(lOne == -1){
                    ans += (r - lZero + 1);
                    r++;
                    continue;
                }
                ans += (lOne - lZero + 1);
                
            }else if(sum > goal){
                sum = 0;
                r = lOne + 1;
                lZero = -1;
                lOne = -1;
                continue;
            }

            r++;
        }
        return ans;
    }
};



//TODO : Understand

// TC - O(2n)
// SC - O(1)
class Solution3 {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int i = 0, count = 0, res = 0;
        for (int j = 0; j < nums.size(); ++j) {
            if (nums[j] == 1) {
                goal--;
                count = 0;
            }
            
            while (goal == 0 && i <= j) {
                goal += nums[i];
                i++;
                count++;
                if (i > j - goal + 1)
                    break;
            }
            
            while (goal < 0) {
                goal += nums[i];
                i++;
            }
            
            res += count;
        }
        return res;
    }
};

// TC - O(4n)
// SC - O(1)
class Solution4 {
public:
    int solve(vector<int>& nums, int goal) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        if(goal < 0)    return 0;
        int n = nums.size(), i = 0, ans = 0;
        for(int j=0; j<n; j++) {
            goal -= nums[j];
            while(goal < 0) {
                goal += nums[i];
                i++;
            }
            ans += (j - i + 1);
        }
        return ans;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return solve(nums, goal) - solve(nums, goal-1);
    }
};
