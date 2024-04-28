// TC - O(n)
// SC - O(26)
class Solution {
public:
    int characterReplacement(string s, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        vector<int> freq(26,0);
        int l = 0, r = 0, n = s.size(), max_freq = 0, ans = 0, total_chars_to_replace;
        while(r < n){
            freq[s[r] - 'A']++;
            max_freq = max(max_freq, freq[s[r] - 'A']);
            total_chars_to_replace = r-l+1 - max_freq;
            // there is no need to decrease window further current max window size. we will keep window size as current max till new some new larger window comes.
            if(total_chars_to_replace > k){
                if(total_chars_to_replace > k){
                    freq[s[l++] - 'A']--;
                    // there is no need to calculate max again because we need to maximize max_freq so there is no need to decrease it further than current max_freq
                }
            }
            r++;
        }
        return r-l;
    }
};


// TC - O(2n * 26)
// SC - O(26)
class Solution2 {
public:
    int characterReplacement(string s, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        vector<int> freq(26,0);
        int l = 0, r = 0, n = s.size(), max_freq = 0, ans = 0, total_chars_to_replace;
        while(r < n){
            freq[s[r] - 'A']++;
            max_freq = max(max_freq, freq[s[r] - 'A']);
            total_chars_to_replace = r-l+1 - max_freq;
            if(total_chars_to_replace > k){
                while(total_chars_to_replace > k){
                    freq[s[l++] - 'A']--;
                    max_freq = *max_element(freq.begin(), freq.end());
                    total_chars_to_replace = r-l+1 - max_freq;
                }
            }
            ans = max(ans, r-l+1);
            r++;
        }
        return ans;
    }
};

