// TC - O(2k)
class Solution {
public:
    int maxScore(vector<int>& cp, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int lsum=accumulate(begin(cp), begin(cp)+k, 0), maxi=lsum, rsum=0, n=cp.size(), r=n-1;
        for(int i=k-1; i>=0; i--){
            lsum -= cp[i];
            rsum += cp[r--];
            maxi = max(maxi, lsum + rsum);
        }
        return maxi;
    }
};


class Solution2 {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        // here we will find subarray of size = (n-k) with minimum sum
        // then we can subtract this with sum of all numbers which will give us the answer
        int n = cardPoints.size();
        k = n - k;
        if(k==0){
            return accumulate(cardPoints.begin(), cardPoints.end(), 0);
        }

        int l = 0, r = 0, ml = 0, mr = k-1, minSum = 0, sum = 0, ans = 0;
        while(r < k){
            sum += cardPoints[r];
            r++;
        }
        minSum = sum;
        r--;
        n--;
        while(r<n){
            sum -= cardPoints[l++];
            sum += cardPoints[++r];
            if(sum < minSum){
                minSum = sum;
                ml = l;
                mr = r;
            }
        }
        n++;
        for(int i=0; i<ml; i++){
            ans += cardPoints[i];
        }
        for(int i=mr+1; i<n; i++){
            ans += cardPoints[i];
        }
        return ans;
    }
};
