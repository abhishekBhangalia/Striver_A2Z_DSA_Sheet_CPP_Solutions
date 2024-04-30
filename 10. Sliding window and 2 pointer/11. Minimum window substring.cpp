class Solution {
public:
    string minWindow(string s, string t) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        vector<int> isInT(256);
        int l = 0, r = 0, minL = 0, minLen = INT_MAX, tLen = t.length(), sLen = s.length(), uniqueCharsInT = 0;

        for(auto &c : t){
            isInT[c]++;
            if(isInT[c] == 1){
                uniqueCharsInT++;
            }
        }

        while(r < sLen){
            int curCharIn = s[r];
            isInT[curCharIn]--;
            if(isInT[curCharIn] == 0){
                uniqueCharsInT--;
            }
            if(uniqueCharsInT == 0){
                while(uniqueCharsInT == 0){
                    curCharIn = s[l];
                    
                    isInT[curCharIn]++;
                    if(isInT[curCharIn] == 1)
                        uniqueCharsInT++;
                    
                    l++;
                }
                int curLen = r-l+2;
                if(curLen < minLen){
                    minL = l-1;
                    minLen = curLen;
                }
            }
            r++;
        }
        if(minLen == INT_MAX){
            return "";
        }
        return s.substr(minL, minLen);
    }
};

class Solution2 {
public:
    string minWindow(string s, string t) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        vector<int> isInT(58), isInWin(58);
        string ans = "";
        int l = 0, r = 0, minL = 0, minR = 0, minLen = INT_MAX, tLen = t.length(), sLen = s.length(), tCharsInWin = 0, uniqueCharsInT = 0;
        for(auto &c : t){
            isInT[c - 'A']++;
        }
        for(int i=0; i<58; i++){
            if(isInT[i] > 0){
                uniqueCharsInT++;
            }
        }

        while(r < sLen){
            int curCharIn = s[r] - 'A';
            if(isInT[curCharIn]){
                isInWin[curCharIn]++;
                if(isInWin[curCharIn] == isInT[curCharIn]){
                    tCharsInWin++;
                }
                if(tCharsInWin == uniqueCharsInT){
                    while(tCharsInWin == uniqueCharsInT){
                        curCharIn = s[l] - 'A';
                        if(isInT[curCharIn]){
                            if(isInT[curCharIn] == isInWin[curCharIn])
                                tCharsInWin--;
                            isInWin[curCharIn]--;
                        }
                        l++;
                    }
                    int curLen = r-l+2;
                    if(curLen < minLen){
                        minL = l-1;
                        minR = r;
                        minLen = curLen;
                    }
                }
            }
            r++;
        }
        if(minLen == INT_MAX){
            return "";
        }
        return s.substr(minL, minR-minL+1);

    }
};
