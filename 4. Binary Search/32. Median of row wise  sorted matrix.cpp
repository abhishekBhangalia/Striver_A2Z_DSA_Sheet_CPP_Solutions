#include <bits/stdc++.h>


int smallerEquals(int x, vector<vector<int>>& matrix){
    int rows = matrix.size();
    int ans = 0;
    for(int i=0; i<rows; i++){
        ans += upper_bound(matrix[i].begin(), matrix[i].end(), x) - matrix[i].begin();
    }
    return ans;
}


// Time Complexity
// O(32 * m * log(n)), where ‘m’ denotes the number of rows and ‘n’
//  denotes the number of matrix columns.

 

// The maximum number in the matrix can be of 32 bits so the worst case will be 
// that we will search from 1 to 2 ^ 32 so in the worst case binary search will 
// run at most log(2 ^ 32) = 32 times and we are searching for count in each row 
// also using binary search that will given us O(m * log(n)). 

 

// Thus, the total time complexity will be O(32 * m * log(n))

//SC-O(1)

int median(vector<vector<int>> &matrix, int m, int n) {
    // Write your code here.

    // it will take O(m) extra time
    // int lo=matrix[0][0], hi=matrix[0][n-1];
    // for(int r = 1; r<m; r++){
    //     if(matrix[r][0] < lo){
    //         lo = matrix[r][0];
    //     }
    //     if(matrix[r][n-1] > hi){
    //         hi = matrix[r][n-1];
    //     }
    // }

    int lo = 1, hi = 1e9;
    int median_index = (m*n)/2 + 1;

    while(lo <= hi){
        int mid = lo+(hi-lo)/2;
        int smaller_equals = smallerEquals(mid, matrix);
        if(smaller_equals < median_index){
            lo = mid+1;
        }
        else{
            hi = mid-1;
        }
    }
    return lo;
}



