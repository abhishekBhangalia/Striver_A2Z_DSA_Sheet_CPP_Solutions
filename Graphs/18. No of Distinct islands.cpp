#include <bits/stdc++.h>
using namespace std;

int r_diff[4] = {1,-1,0,0};
int c_diff[4] = {0,0,1,-1};
int rows, cols;

string rec(int r, int c, int** arr){
    arr[r][c] = 0;
    string path = "";
    for(int i=0; i<4; i++){
        int nr = r+r_diff[i];
        int nc = c+c_diff[i];
        if(0 <= nr and nr < rows and 0<=nc and nc<cols and arr[nr][nc] == 1){
            path += to_string(i);
            path += rec(nr, nc, arr);
            path += "b"; // backtrack needed for detecting mirror images
        }
        // else path += "n";
    }
    return path;
}

//TC - O(m*n) + O(m*n*4)
//SC - O(2*m*n)
int distinctIslands(int** arr, int n, int m){
    map<string, bool> mp;
    rows = n;
    cols = m;
    int disIslands = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(arr[i][j] == 1){
                string path = rec(i, j, arr);
                if(!mp[path]){
                    mp[path] = true;
                    disIslands++;
                }
            }
        }
    }
    return disIslands;
}
