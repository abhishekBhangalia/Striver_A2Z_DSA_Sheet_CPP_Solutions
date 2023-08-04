class Solution {
public:
    

    // //dp using memoization

    // int dp(int m, int n, vector<vector<int>>& paths,vector<vector<int>>& obstacleGrid){
    //     if(m<0 || n<0){
    //         return 0;
    //     }
    //     if(obstacleGrid[m][n]){
    //         return 0;
    //     }
    //     if(m==0 && n==0){
    //         return 1;
    //     }
        
    //     if(paths[m][n]){
    //         return paths[m][n];
    //     }
    //     int came_from_up = dp(m-1,n,paths,obstacleGrid);
    //     int came_from_left = dp(m,n-1,paths,obstacleGrid);
    //     return paths[m][n] = came_from_up + came_from_left;
    // }

    
    // int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    //     vector<vector<int>> paths(obstacleGrid.size(),vector<int>(obstacleGrid[0].size(),0));
    //     return dp(obstacleGrid.size()-1,obstacleGrid[0].size()-1,paths,obstacleGrid);
    // }

    // // dp using tabulation

    // int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    //     int m=obstacleGrid.size();
    //     int n=obstacleGrid[0].size();
    //     vector<vector<int>> paths(m,vector<int>(n,0));

    //     paths[0][0] = obstacleGrid[0][0] ? 0 : 1;
    //     for(int col=1; col<n; col++ ){
    //         paths[0][col] = obstacleGrid[0][col] ? 0 : paths[0][col-1];
    //     }
    //     for(int row=1; row<m; row++){
    //         paths[row][0] = obstacleGrid[row][0] ? 0 : paths[row-1][0];
    //     }
    //     for(int row=1; row<m; row++){
    //         for(int col=1; col<n; col++){
    //             paths[row][col] = obstacleGrid[row][col] ? 0 : paths[row-1][col]+paths[row][col-1];
    //         }
    //     }
    //     return paths[m-1][n-1];
    // }

    // dp using tabulation and space optimization

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();

        if(obstacleGrid[m-1][n-1]){
            return 0;
        }

        vector<int> up_paths(n,0);

        up_paths[0] = obstacleGrid[0][0] ? 0 : 1;
        for(int col=1; col<n; col++ ){
            up_paths[col] = obstacleGrid[0][col] ? 0 : up_paths[col-1];
        }
        int left=1,paths=0;
        for(int row=1; row<m; row++){
            left = obstacleGrid[row][0] ? 0 : up_paths[0];
            up_paths[0] = left;
            for(int col=1; col<n; col++){
                paths = obstacleGrid[row][col] ? 0 : left+up_paths[col];
                up_paths[col]=paths;
                left = paths;
            }
        }
        return up_paths[n-1];
    }
};
