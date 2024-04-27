auto fast = []{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return false;
}();


class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int x = 0;
        for(auto &num : nums){
            x ^= num;
        }
        return x;
    }
};