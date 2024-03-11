auto fast = []{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return false;
}();

class Solution {
public:
    int rows, cols;
    
    void rec(int r, int c, array<int,4>& rd, array<int,4>& cd, vector<vector<char>>& b){
        for(int i=0; i<4; i++){
            int nr = r + rd[i];
            int nc = c + cd[i];
            if (0<=nr and nr<rows and 0<=nc and nc<cols and b[nr][nc] == 'O'){
                b[nr][nc] = '*';
                rec(nr, nc,rd, cd, b);
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        rows = board.size();
        cols = board[0].size();
        
        array<int,4> rd = {1,-1,0,0};
        array<int,4> cd = {0,0,1,-1};
        for (int c=0; c<cols; c++){
            if(board[0][c] == 'O'){
                board[0][c] = '*';
                rec(0,c,rd, cd, board);
            }
            if(board[rows-1][c] == 'O'){
                board[rows-1][c] = '*';
                rec(rows-1,c,rd, cd,board);
            }
        }
        for (int r=1; r<rows-1; r++){
            if(board[r][0] == 'O'){
                board[r][0] = '*';
                rec(r,0,rd, cd,board);
            }
            if(board[r][cols-1] == 'O'){
                board[r][cols-1] = '*';
                rec(r,cols-1,rd, cd,board);
            }
        }

        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                } else if(board[i][j] == '*'){
                    board[i][j] = 'O';
                }
            }
        }

    }
};
