// TC - O(2n)
// SC - O(3)
class Solution {
public:
    int numberOfSubstrings(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n = s.size(), l = 0, r = 0, ans = 0, uniques = 0;
        int freq[3] = {0};

        while(r < n){
            freq[s[r] - 'a']++;
            if(freq[s[r] - 'a'] == 1){
                uniques++;
            }
            if(uniques < 3){
                r++;
                continue;
            }
            int tmp = 0;
            while(uniques == 3){
                uniques -= --freq[s[l++] - 'a'] == 0;
                tmp++;
            }
            ans += (n-r) * tmp;
            r++;
        }
        return ans;
    }
};

class Solution2 {
public:
    int numberOfSubstrings(string s) {
        int cnt = 0, n = s.length();
        int a = -1, b = -1, c = -1;
        for(int i = 0; i < n; i++){
            if(s[i] == 'a') a = i;
            else if(s[i] == 'b') b = i;
            else c = i;
            cnt += (min(a, min(b, c)) + 1);
        }
        return cnt;
    }
};


// TC - O(3n)
// SC - O(3)
class Solution3 {
public:
    int numberOfSubstrings(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n = s.size(), l = 0, r = 0, ans = 0;
        vector<int> lastIndex(3, -1);

        while(r < n){
            lastIndex[s[r] - 'a'] = r;
            r++;
            int minIndex = *min_element(lastIndex.begin(), lastIndex.end());
            
            if(minIndex < 0){ // window does not contain all three characters
                continue;
            }
            ans += minIndex+1;
        }
        return ans;
    }
};


