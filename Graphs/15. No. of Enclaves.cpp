auto fast = []{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return false;
}();

class Solution {
public:
    int r_diff[4] = {1,-1,0,0};
    int c_diff[4] = {0,0,1,-1};
    int rows, cols;

    void rec(int r, int c, vector<vector<int>>& grid){
        grid[r][c] = 0;
        
        for(int i=0; i<4; i++){
            int nr = r+r_diff[i];
            int nc = c+c_diff[i];
            if(0<=nr and nr<rows and 0<=nc and nc<cols and grid[nr][nc] == 1){
                rec(nr, nc, grid);
            }
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int cells = 0;
        rows = grid.size();
        cols = grid[0].size();
        for(int c = 0; c<cols; c++){
            if(grid[0][c] == 1){
                rec(0,c,grid);
            }
            if(grid[rows-1][c] == 1){
                rec(rows-1, c, grid);
            }
        }
        for(int r = 1; r<rows-1; r++){
            if(grid[r][0] == 1){
                rec(r,0, grid);
            }
            if(grid[r][cols-1] == 1){
                rec(r, cols-1, grid);
            }
        }

        for(int r = 1; r<rows; r++){
            for(int c = 1; c<cols; c++){
                if (grid[r][c] == 1){
                    cells++;
                }
            }
        }
        return cells;
    }
};
