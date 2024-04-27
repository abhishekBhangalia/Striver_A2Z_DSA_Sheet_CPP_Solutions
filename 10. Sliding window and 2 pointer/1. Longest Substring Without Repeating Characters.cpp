static const auto speed=[]{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    return false;
}();


class Solution {
public:

    // int lengthOfLongestSubstring(string s) {
    //     int n=s.size();
    //     if(n==0)    return 0;
    //     if(n==1)    return 1;
    //     int ans = 0;
    //     for(int i=0; i<n; i++){
    //         set<char> m;
    //         for(int j=i; j<n; j++){
    //             if(m.find(s[j]) == m.end()){
    //                 m.insert(s[j]);
    //             }
    //             else{
    //                 break;
    //             }
    //         }
    //         ans = max(ans, (int)m.size());
    //     }
        
    //     return ans;
    // }


    // //TC-O(2n log n)
    // int lengthOfLongestSubstring(string s) {
    //     int n = s.size();
    //     int l = 0, r = 0;
    //     set<int> st;
    //     int ans = 0;
    //     while(r<n){
    //         if(st.find(s[r]) == st.end()){
    //             st.insert(s[r]);
    //             ans = max(ans, r-l+1);
    //             r++;
    //         }
    //         else{
    //             st.erase(s[l]);
    //             l++;
    //         }
    //     }
    //     return ans;
    // }


    //11 ms
    //TC-O(2n log n)
    // int lengthOfLongestSubstring(string s) {
    //     int n = s.size();
    //     int l = 0, r = 0;
    //     map<int,int> m;
    //     int ans = 0;
    //     while(r<n){
    //         if(m.find(s[r]) == m.end()){                
    //             ans = max(ans, r-l+1);
    //         }
    //         else{
    //             if(m[s[r]] >= l){
    //                 l = m[s[r]]+1;
    //             }
    //             else{
    //                 ans = max(ans, r-l+1);
    //             }
    //         }
    //         m[s[r]] = r;
    //         r++;
    //     }
    //     return ans;
    // }

//4ms
//TC-O(n)
int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int l = 0, r = 0;
        vector<int> m(256,-1);
        int ans = 0;
        while(r<n){
            if(m[s[r]] == -1){                
                ans = max(ans, r-l+1);
            }
            else{
                if(m[s[r]] >= l){
                    l = m[s[r]]+1;
                }
                else{
                    ans = max(ans, r-l+1);
                }
            }
            m[s[r]] = r;
            r++;
        }
        return ans;
    }




};