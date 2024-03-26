auto fast = []{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return false;
}();

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        int weights[101][101];
        int d[5] = {0, 1, 0, -1, 0};

        //when you use memset with 0x7f, it sets each byte of the array to 0x7f, which effectively initializes each integer in the array to 0x7f7f7f7f in hexadecimal or 2139062143 in decimal.

// 0x7f7f7f7f in two's complement representation is equivalent to INT_MAX (the maximum value for a signed integer).

        memset(weights, 0x7f, sizeof(weights));
        weights[0][0] = 0;
        priority_queue<pair<int, int>> pq; pq.push({0, 0});
        while (!pq.empty()) {
            int r = pq.top().second/100, c = pq.top().second%100, w = pq.top().first; pq.pop();
            if (r == m-1 && c == n-1) return -w;
            for (int i = 0; i < 4; ++i) {
                int nr = r + d[i], nc = c + d[i+1];
                if (nr < 0 || nc < 0 || nr > m-1 || nc > n-1) continue;
                int nw = max(-w, abs(heights[nr][nc] - heights[r][c]));
                if (nw < weights[nr][nc]) {
                    weights[nr][nc] = nw;
                    pq.push({-nw, nr*100 + nc});
                }
            }
        }
        return -1;
    }
};

class Solution2 {
    private:
    int rowDiff[4] = {1,-1,0,0};
    int colDiff[4] = {0,0,1,-1};

public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>> minEff;
        minEff.push({0,{0,0}});
        int rows = heights.size();
        int cols = heights[0].size();
        // vector<vector<int>> dist(rows, vector<int>(cols,INT_MAX));
        int** dist = new int*[rows];
        for(int i=0; i<rows; i++){
            dist[i] = new int[cols];
            for(int j=0; j<cols; j++){
                dist[i][j] = INT_MAX;
            }
        }
        dist[0][0] = 0;

        while(not minEff.empty()){
            int effort = minEff.top().first;
            int r = minEff.top().second.first, c = minEff.top().second.second;
            if(r==rows-1 and c==cols-1){
                return effort;
            }
            minEff.pop();

            for(int i=0; i<4; i++){
                int nr = r + rowDiff[i];
                int nc = c + colDiff[i];
                if(0<=nr and nr<rows and 0<=nc and nc<cols ){
                    int eff = max(effort,abs(heights[nr][nc] - heights[r][c]));
                    if (dist[nr][nc] > eff){
                        dist[nr][nc] = eff;
                        minEff.push({eff, {nr,nc}});
                    }
                }
            }
        }
        return -1;

    }
};

