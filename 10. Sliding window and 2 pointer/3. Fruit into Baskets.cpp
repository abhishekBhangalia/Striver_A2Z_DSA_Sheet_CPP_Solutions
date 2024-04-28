//TC-O(n)
//SC-O(1)
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL); cout.tie(NULL);

        int n = fruits.size();
        if (n < 3) return n;
        int a = fruits[0], b = -1;
        int ca = 1, cb = 0;
        int l = 0, r = 1;
        int mx = 1;
        while (r < n) {
            if (fruits[r] == a) ca++;
            else if (b == -1) {
                b = fruits[r];
                cb = 1;
            }
            else if (fruits[r] == b) cb++;
            else {
                while (ca != 0 && cb != 0) {
                    if (a == fruits[l]) ca--;
                    else cb--;
                    l++;
                }
                if (!ca) {
                    a = fruits[r];
                    ca = 1;
                }
                else {
                    b = fruits[r];
                    cb = 1;
                }
            }
            mx = max(ca + cb, mx);
            r++;
        }
        return mx;
    }
};


// TC-O(n)
// SC-O(n)
class Solution2 {
public:
    int totalFruit(vector<int>& fruits) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL); cout.tie(NULL);

        int l = 0, r = 0, size = fruits.size(), unique_fruits = 0;
        vector<int> freq(size);
        while(r < size){
            freq[fruits[r]]++;
            if(freq[fruits[r]] == 1){
                unique_fruits++;
            }
            if(unique_fruits > 2){
                freq[fruits[l]]--;
                if(freq[fruits[l]] == 0){
                    unique_fruits--;
                }
                l++;
            } 
            r++;
        }
        return r-l;
    }
};



//TC-O(2n)
//SC-O(n)
class Solution3 {
public:
    int totalFruit(vector<int>& fruits) {
        int l = 0, r = 0, size = fruits.size(), unique_fruits = 0, ans = 0;
        vector<int> freq(size);
        while(r < size){
            freq[fruits[r]]++;
            if(freq[fruits[r]] == 1){
                unique_fruits++;
            }
            while(unique_fruits > 2){
                freq[fruits[l]]--;
                if(freq[fruits[l]] == 0){
                    unique_fruits--;
                }
                l++;
            } 
            ans = max(ans, r-l+1);
            r++;
        }
        return ans;
    }
};


