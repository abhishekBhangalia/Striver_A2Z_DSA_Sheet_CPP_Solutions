auto fast = []{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return false;
}();

class Solution2 {
public:

    //tc - O(n^2 * log(n^2) * 4)
    //sc - O(n^2)
    int swimInWater(vector<vector<int>>& grid) {
        priority_queue< pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> minHeap;
        //n X n matrix
        int n = grid.size();
        minHeap.push({grid[0][0],{0,0}});
        int maxElevInPath = grid[0][0];
        grid[0][0] = -1; // -1 indicates this element is visited 
        int rdiff[] = {1,-1,0,0};
        int cdiff[] = {0,0,1,-1};

        while(not minHeap.empty()){
            int curElev = minHeap.top().first;
            maxElevInPath = max(curElev, maxElevInPath);

            int r = minHeap.top().second.first;
            int c = minHeap.top().second.second;
            minHeap.pop();

            for(int i=0; i<4; i++){
                int nr = r+rdiff[i];
                int nc = c+cdiff[i];

                if(0<=nr and nr<n and 0<=nc and nc<n and grid[nr][nc] != -1){
                    if(nr == n-1 and nc == n-1){
                        return max(grid[nr][nc], maxElevInPath);
                    }
                    minHeap.push({grid[nr][nc], {nr, nc}});
                    grid[nr][nc] = -1;
                }
            }
        }
        return maxElevInPath;
    }
};

// tc-O(log(n^2) * n^2 * 4)
// sc-O(2 * n^2)
class Solution {
    int vis[51][51];
    vector<vector<int>> dir = {{0,1}, {1,0}, {0,-1}, {-1,0}};
    bool dfs(int i,int j,int n,vector<vector<int>>& grid,int limit)
    {
        if(grid[i][j] > limit)
            return false;
        if(i == n-1 && j == n-1)
            return true;

        vis[i][j] = 1;
        
        for(int k = 0; k < 4; k++)
        {
            int nx = i + dir[k][0];
            int ny = j + dir[k][1];
            
            if (nx < n && nx >= 0 && ny < n 
                && ny >= 0 && vis[nx][ny] == -1)
            {
                if (grid[nx][ny] <= limit)
                {
                    if (dfs(nx, ny, n, grid, limit)) 
                        return true;
                }
            }
        }
        return false;
    }
public:
    int swimInWater(vector<vector<int>>& grid){
        int n = grid[0].size();
        int l = 0;
        int r = (n*n) - 1;

        while (l < r)
        {
            int mid = (r-l)/2 + l;
            memset (vis, -1, sizeof(vis));
            if (!dfs(0, 0, n, grid, mid)) l = mid + 1;
            else r = mid;
        }
        return l;
    }
};
