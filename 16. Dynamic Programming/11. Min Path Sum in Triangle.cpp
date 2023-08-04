class Solution {
public:

//     //dp using memoization

//     int minimumTotal(vector<vector<int>>& triangle) {
//         vector<vector<int>> sum(triangle.size(),vector<int>(triangle.size(),0));
//         if(triangle.size()==1){
//             return triangle[0][0];
//         }
//         return dp(0,0,triangle,sum);
//     }


//     int dp(int r,int c, vector<vector<int>>& triangle,vector<vector<int>>& sum){
//         if(r==triangle.size()-1){
//             return triangle[triangle.size()-1][c];
//         }
//         if(sum[r][c]){
//             return sum[r][c];
//         }
//         int left = triangle[r][c]+dp(r+1,c,triangle,sum);
//         int right = triangle[r][c]+dp(r+1,c+1,triangle,sum);
//         return sum[r][c] = min(left,right);
//     }
// };

// //dp using tabulation

//     int minimumTotal(vector<vector<int>>& triangle) {
//         vector<vector<int>> sum(triangle.size(),vector<int>(triangle.size(),0));
//         if(triangle.size()==1){
//             return triangle[0][0];
//         }
//         for(int col=0; col<triangle.size(); col++){
//             sum[triangle.size()-1][col] = triangle[triangle.size()-1][col];
//         }
//         for(int row = triangle.size()-2; row>=0; row--){
//             for(int col=0; col<= row; col++){
//                 sum[row][col] = triangle[row][col]+min(sum[row+1][col],sum[row+1][col+1]);
//             }
//         }
//         return sum[0][0];
//     }

//dp using tabulation with space optimization if triangle array can't be changed

    int minimumTotal(vector<vector<int>>& triangle) {
        if(triangle.size()==1){
            return triangle[0][0];
        }
        vector<int> sum(triangle.size(),0);
        for(int col=0; col<triangle.size(); col++){
            sum[col] = triangle[triangle.size()-1][col];
        }
        for(int row = triangle.size()-2; row>=0; row--){
            for(int col=0; col<= row; col++){
                sum[col] = triangle[row][col]+min(sum[col],sum[col+1]);
            }
        }
        return sum[0];
    }


// //dp using tabulation with space optimization if triangle array can be changed

//     int minimumTotal(vector<vector<int>>& triangle) {
        
//         if(triangle.size()==1){
//             return triangle[0][0];
//         }
        
//         for(int row = triangle.size()-2; row>=0; row--){
//             for(int col=0; col<= row; col++){
//                 triangle[row][col] += min(triangle[row+1][col],triangle[row+1][col+1]);
//             }
//         }
//         return triangle[0][0];
//     }

};
