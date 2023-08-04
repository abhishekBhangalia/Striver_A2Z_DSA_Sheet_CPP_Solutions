class Solution {
public:

    // dp using memoization

    // int dp(int m, int n, vector<vector<int>>& paths){
    //     if(m==0 && n==0){
    //         return 1;
    //     }
    //     if(m<0 || n<0){
    //         return 0;
    //     }
    //     if(paths[m][n]){
    //         return paths[m][n];
    //     }
    //     int came_from_up = dp(m-1,n,paths);
    //     int came_from_left = dp(m,n-1,paths);
    //     return paths[m][n] = came_from_up + came_from_left;
    // }

    // int uniquePaths(int m, int n) {
    //     vector<vector<int>> paths(m,vector<int>(n,0));
    //     return dp(m-1,n-1,paths);
    // }

    // // dp using tabulation

    // int uniquePaths(int m, int n) {
    //     vector<vector<int>> paths(m,vector<int>(n,0));

    //     paths[0][0] = 1;
    //     for(int col=1; col<n; col++ ){
    //         paths[0][col] = 1;
    //     }
    //     for(int row=1; row<m; row++){
    //         paths[row][0] = 1;
    //     }
    //     for(int row=1; row<m; row++){
    //         for(int col=1; col<n; col++){
    //             paths[row][col] = paths[row-1][col]+paths[row][col-1];
    //         }
    //     }
    //     return paths[m-1][n-1];
    // }

    // dp using tabulation and space optimization

    int uniquePaths(int m, int n) {
        int left=1,paths=1;
        vector<int> up(n,1);
        for(int row=1; row<m; row++){
            left=1;
            for(int col=1; col<n; col++){
                paths = up[col]+left;
                up[col] = paths;
                left = paths;
            }
        }
        return paths;
    }

};
