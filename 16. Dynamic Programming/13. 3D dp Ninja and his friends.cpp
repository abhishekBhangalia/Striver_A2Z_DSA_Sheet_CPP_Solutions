#include <bits/stdc++.h>

// dp using memoization

// int dp(int r, int c1, int c2, vector<vector<int>>& grid, vector<vector<vector<int>>>& sum){
//     if(r==grid.size()-1){
//         if(c1==c2){
//             return grid[r][c1];
//         }
//         else{
//             return grid[r][c1]+grid[r][c2];
//         }
//     }
//     if(sum[r][c1][c2]){
//         return sum[r][c1][c2];
//     }
//     int maxi = INT_MIN;
//     vector<int> arr = {-1,0,1};
//     for(int i=0; i<3; i++){
//         if(c1+arr[i]>=0 and c1+arr[i]<grid[0].size()){
//             for(int j=0; j<3; j++){
//                 if(c2+arr[j]>=0 and c2+arr[j]<grid[0].size()){
//                     maxi = max(maxi,dp(r+1,c1+arr[i],c2+arr[j],grid,sum));
//                 }
//             }
//         }
//     }
//     if(c1==c2){
//         return sum[r][c1][c2] = grid[r][c1] + maxi;
//     }
//     else{
//         return sum[r][c1][c2] = grid[r][c1]+grid[r][c2]+maxi;
//     }
// }


// int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
//     // Write your code here.
//     vector<vector<vector<int>>> sum(grid.size(),vector<vector<int>>(grid[0].size(),vector<int>(grid[0].size(),0)));
//     return dp(0,0,grid[0].size()-1,grid,sum);
// }


// dp using tabulation -TC - O(r*c*c*3*3) , SC - O(r*c*c) + O(r)auxiliary stack space

int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    // Write your code here.
   
    vector<vector<vector<int>>> sum(r,vector<vector<int>>(c,vector<int>(c,0)));
    for(int c1 = 0; c1<c; c1++){
        for(int c2 = 0; c2<c; c2++){
            if(c1==c2){
                sum[r-1][c1][c2] = grid[r-1][c1];
            }
            else{
                sum[r-1][c1][c2] = grid[r-1][c1]+grid[r-1][c2];
            }
        }
    }

    for(int row = r-2; row>0;row-- ){
        for(int c1 = 0; c1<c; c1++){
            for(int c2=0; c2<c; c2++){
                int maxi = INT_MIN;
                int arr[] = {-1,0,1};
                for(int i=0; i<3; i++){
                    if(c1+arr[i]>=0 and c1+arr[i]<c){
                        for(int j=0; j<3; j++){
                            if(c2+arr[j]>=0 and c2+arr[j]<c){
                                maxi = max(maxi,sum[row+1][c1+arr[i]][c2+arr[j]]);
                            }
                        }
                    }
                    
                }
                if(c1==c2){
                    sum[row][c1][c2] = grid[row][c1] + maxi;
                }
                else{
                    sum[row][c1][c2] = grid[row][c1] + grid[row][c2] + maxi;
                }
            }
        }
    }

    int maxi = INT_MIN;

    int arr[] = {-1,0,1};
    for(int i=0; i<3; i++){
        if(0+arr[i]>=0 and 0+arr[i]<c){
            for(int j=0; j<3; j++){
                if(c-1+arr[j]>=0 and c-1+arr[j]<c){
                    maxi = max(maxi,sum[1][0+arr[i]][c-1+arr[j]]);
                }
            }
        }
        
    }

    sum[0][0][c-1] = grid[0][0] + grid[0][c-1] + maxi;


    return sum[0][0][c-1];
}









