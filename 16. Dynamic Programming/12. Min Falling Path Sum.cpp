class Solution {
public:

    // DP using memoization

    // int minFallingPathSum(vector<vector<int>>& matrix) {
    //     int minSum = INT_MAX;
    //     vector<vector<int>> sum(matrix.size(),vector<int>(matrix[0].size(),0));
    //     for(int col=0; col<matrix[0].size(); col++){
    //         minSum = min(minSum,dp(0,col,matrix,sum));
    //         // cout<<minSum<<endl;
    //     }
    //     return minSum;
        
    // }

    // int dp(int r, int c, vector<vector<int>>& matrix,vector<vector<int>>& sum){
    //     if(r==matrix.size()-1){
    //         return matrix[r][c];
    //     }
    //     if(sum[r][c]){
    //         return sum[r][c];
    //     }
    //     int arr[] = {-1,0,1};
    //     int mini = INT_MAX;
    //     for(int i=0; i<3; i++){
    //         if(c+arr[i]>=0 and c+arr[i]<matrix[0].size()){
    //             mini =  min(mini,dp(r+1,c+arr[i],matrix,sum));
    //         }
    //     }
        
    //     return sum[r][c] = matrix[r][c] + mini;
    // }


    // // DP using tabulation method
    // int minFallingPathSum(vector<vector<int>>& matrix) {
    //     int minSum = INT_MAX;
    //     vector<vector<int>> sum(matrix.size(),vector<int>(matrix[0].size(),0));
    //     int r = matrix.size(); int c = matrix[0].size();
    //     for(int col = 0; col<c; col++){
    //         sum[r-1][col] = matrix[r-1][col];
    //     }

    //     for(int row = r-2; row>=0; row--){
    //         for(int col=0; col<c; col++){
    //             int arr[] = {-1,0,1};
    //             int mini = INT_MAX;
    //             for(int i=0; i<3; i++){
    //                 if(col+arr[i]>=0 and col+arr[i]<c){
    //                     mini = min(mini,sum[row+1][col+arr[i]]);
    //                 }
    //             }
    //             sum[row][col] = matrix[row][col]+mini;
    //         }
    //     }

    //     for(int col=0; col<matrix[0].size(); col++){
    //         minSum = min(minSum,sum[0][col]);
    //         // cout<<minSum<<endl;
    //     }
    //     return minSum;
        
    // }

    // DP using tabulation method and space optimization if matrix array can be changed
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int minSum = INT_MAX;
        
        int r = matrix.size(); int c = matrix[0].size();

        for(int row = r-2; row>=0; row--){
            for(int col=0; col<c; col++){
                int arr[] = {-1,0,1};
                int mini = INT_MAX;
                for(int i=0; i<3; i++){
                    if(col+arr[i]>=0 and col+arr[i]<c){
                        mini = min(mini,matrix[row+1][col+arr[i]]);
                    }
                }
                matrix[row][col] += mini;
            }
        }

        for(int col=0; col<matrix[0].size(); col++){
            minSum = min(minSum,matrix[0][col]);
        }
        return minSum;
        
    }
};
