#include <bits/stdc++.h>

//  dp using memoization

// int dp(int n, int prev_act, vector<vector<int>>& points, vector<vector<int>>& max_points){
//     if(n==0){
//         if(prev_act == 0){
//             return max(points[0][1],points[0][2]);
//         }
//         if(prev_act == 1){
//             return max(points[0][0],points[0][2]);
//         }
//         if(prev_act == 2){
//             return max(points[0][0],points[0][1]);
//         }
//     }
    

//     if( max_points[n][prev_act]){
//         return max_points[n][prev_act];
//     }
    
    
    
//     int max_point = INT_MIN;

//     for(int i=0; i<3; i++){
//         if(prev_act!=i){
            
//             int point = points[n][i] + dp(n-1,i,points,max_points);
//             max_point = max(max_point,point);
//         }
//     }
//     return max_points[n][prev_act] = max_point;
// }


// int ninjaTraining(int n, vector<vector<int>> &points)
// {
//     // Write your code here.
//     vector<vector<int>> max_points(n,vector<int>(4,0));
//     if (n==1){
//         int max_point = max(points[0][0],points[0][1]);
//         max_point = max(points[0][2],max_point);
//         return max_point;
//     }
//     return dp(n-1,3,points,max_points);
// }


// // dp using tabulation


// int ninjaTraining(int n, vector<vector<int>> &points)
// {
//     // Write your code here.
//     vector<vector<int>> dp(n,vector<int>(4,0));
//     if (n==1){
//         int max_point = max(points[0][0],points[0][1]);
//         max_point = max(points[0][2],max_point);
//         return max_point;
//     }
    
//     dp[0][0] = max(points[0][1],points[0][2]);
//     dp[0][1] = max(points[0][0],points[0][2]);
//     dp[0][2] = max(points[0][0],points[0][1]);

//     int max_points = 0;
//     for(int i=1; i<n; i++){
//         for(int act = 0; act<3; act++){
//             dp[i][act] = max(points[i][(act+1)%3] + dp[i-1][(act+1)%3],points[i][(act+2)%3]+dp[i-1][(act+2)%3]);
//             max_points = max(max_points,dp[i][act]);
//         }
//     }

//     return max_points;
// }


// dp using tabulation and space optimization


int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
    
    if (n==1){
        int max_point = max(points[0][0],points[0][1]);
        max_point = max(points[0][2],max_point);
        return max_point;
    }

    int prev_max_0,prev_max_1,prev_max_2;
    
    prev_max_0 = max(points[0][1],points[0][2]);
    prev_max_1 = max(points[0][0],points[0][2]);
    prev_max_2 = max(points[0][0],points[0][1]);

    int cur_max_0,cur_max_1,cur_max_2;

    int max_points = 0;
    for(int i=1; i<n; i++){
        int cur_max;
        cur_max_0 = max(points[i][1]+prev_max_1,points[i][2]+prev_max_2);
        cur_max_1 = max(points[i][0]+prev_max_0,points[i][2]+prev_max_2);
        cur_max_2 = max(points[i][0]+prev_max_0,points[i][1]+prev_max_1);
        prev_max_0 = cur_max_0;
        prev_max_1 = cur_max_1;
        prev_max_2 = cur_max_2;
        
        cur_max = max(cur_max_0,cur_max_1);
        cur_max = max(cur_max,cur_max_2);
        max_points = max(max_points,cur_max);

    }

    return max_points;
}

