class Solution {
public:
    int minBitFlips(int start, int goal) {
        int flips = 0;
        while(start > 0 or goal > 0){
            int start_rbit = start & 1;
            int goal_rbit = goal & 1;
            if (start_rbit ^ goal_rbit){
                flips++;
            }
            start = start >> 1;
            goal = goal >> 1;
        }
        return flips;
    }
};