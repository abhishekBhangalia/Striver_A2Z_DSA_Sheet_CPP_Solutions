class Solution {
public:

    // dp using memoization

    // int minPathSum(vector<vector<int>>& grid) {
    //     int r = grid.size();
    //     int c = grid[0].size();
    //     vector<vector<int>> sum(r,vector<int>(c,0));
    //     return dp(r-1,c-1,grid,sum);
    // }

    // int dp(int r, int c, vector<vector<int>>& grid, vector<vector<int>>& sum){
    //     if(r==0 and c==0){
    //         return grid[0][0];
    //     }
        
    //     if(sum[r][c]){
    //         return sum[r][c];
    //     }

    //     int up_sum =r>0 ? grid[r][c]+dp(r-1,c,grid,sum) : INT_MAX;
    //     int left_sum =c>0 ? grid[r][c]+dp(r,c-1,grid,sum) : INT_MAX;
    //     return sum[r][c] = min(up_sum,left_sum);

    // }


    // // dp using tabulation

    // int minPathSum(vector<vector<int>>& grid) {
    //     int r = grid.size();
    //     int c = grid[0].size();
    //     vector<vector<int>> sum(r,vector<int>(c,0));

    //     sum[0][0] = grid[0][0];
    //     for(int col=1; col<c; col++){
    //         sum[0][col] = grid[0][col] + sum[0][col-1];
    //     }
    //     for(int row=1; row<r; row++){
    //         sum[row][0] = grid[row][0] + sum[row-1][0];
    //     }

    //     for(int row = 1; row<r; row++){
    //         for(int col = 1; col<c; col++){
    //             sum[row][col] = grid[row][col] + min(sum[row-1][col],sum[row][col-1]);
    //         }
    //     }

    //     return sum[r-1][c-1];
    // }

// dp using tabulation and space optimization

    int minPathSum(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        
        for(int col=1; col<c; col++){
            grid[0][col] += grid[0][col-1];
        }

        for(int row=1; row<r; row++){
            grid[row][0] += grid[row-1][0];
        }

        for(int row = 1; row<r; row++){
            for(int col = 1; col<c; col++){
                grid[row][col] += min(grid[row-1][col],grid[row][col-1]);
            }
        }

        return grid[r-1][c-1];
    }
    
};
