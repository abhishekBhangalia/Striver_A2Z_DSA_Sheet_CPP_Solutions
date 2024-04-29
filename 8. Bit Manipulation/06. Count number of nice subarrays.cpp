class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int lEven = -1, lOdd = -1, prevOdd = -1, r = 0, n = nums.size(), totalOdds = 0, ans = 0;

        while(r < n){
            if(nums[r] & 1){ // odd
                totalOdds++;
                
                if(lOdd == -1){
                    lOdd = r;
                    prevOdd = r;
                    if(lEven == -1){
                        lEven = r;
                    }
                }
                else{
                    nums[prevOdd] = r;
                    prevOdd = r;
                }
                
            }else if(lEven == -1){
                lEven = r;
            }

            if(totalOdds == k){
                if(lOdd == -1){
                    ans += (r - lEven + 1);
                    r++;
                    continue;
                }
                ans += (lOdd - lEven + 1);
            }
            else if (totalOdds > k){
                totalOdds-=2;
                lEven = lOdd + 1;
                lOdd = nums[lOdd];
                continue;
            }
            r++;
        }
        return ans;
    }
};


class Solution2 {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        cout.tie(0),cin.tie(0),ios_base::sync_with_stdio(0);
        int n = nums.size();
        int i = 0, j = 0, ans = 0, count = 0;
        while(j < n) {
            if(nums[j] & 1) count++;
            while(count > k) {
                if(nums[i] & 1) count--;
                i++;
            }
            if(count == k) {
                int temp = i;
                while(temp < j && (nums[temp] & 1) == 0) temp++;
                ans += temp - i + 1;
            }
            j++;
        }
        return ans;
    }
};


class Solution3 {
public:
    int find(vector<int>& nums, int k){
        int i=0, j=0, ans=0, c=0;
        while(j < nums.size()){
            if(nums[j]%2) c++;

            while(c > k && i<=j){
                if(nums[i]%2) c--;
                i++;
            }
            ans += j-i+1;
            j++;
        }
        return ans;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        cin.tie(NULL);
        ios_base::sync_with_stdio(false);
        return find(nums,k)-find(nums,k-1);
    }
};
