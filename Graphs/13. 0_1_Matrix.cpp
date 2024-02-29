static const auto fast = []{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return false;
}();


class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[i].size(); ++j) {
                if (!matrix[i][j]) {
                    continue;
                }
                matrix[i][j] = numeric_limits<int>::max();
                if (i > 0 && matrix[i - 1][j] != numeric_limits<int>::max()) {
                    matrix[i][j] = min(matrix[i][j], matrix[i - 1][j] + 1);
                }
                if (j > 0 && matrix[i][j - 1] != numeric_limits<int>::max()) {
                    matrix[i][j] = min(matrix[i][j], matrix[i][j - 1] + 1);
                }
            }
        }

        for (int i = matrix.size() - 1; i >= 0; --i) {
            for (int j = matrix[i].size() - 1; j >= 0; --j) {
                if (!matrix[i][j]) {
                    continue;
                }
                if (i < matrix.size() - 1 && matrix[i + 1][j] != numeric_limits<int>::max()) {
                    matrix[i][j] = min(matrix[i][j], matrix[i + 1][j] + 1);
                }
                if (j < matrix[i].size() - 1 && matrix[i][j + 1] != numeric_limits<int>::max()) {
                    matrix[i][j] = min(matrix[i][j], matrix[i][j + 1] + 1);
                }
            }
        }

        return matrix;
    }
};

class Solution2 {
public:

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int rows = mat.size(), cols = mat[0].size();
        vector<vector<int>> ans(rows, vector<int>(cols,-1));
        int row_diff[] = {1, -1, 0, 0};
        int col_diff[] = {0, 0, 1, -1};


        queue<pair<int,int>> q;
        //O(m*n)
        for(int i=0; i<mat.size(); i++){
            for(int j=0; j<mat[0].size(); j++){
                if(mat[i][j] == 0){
                    q.emplace(i,j);
                    ans[i][j] = 0;
                } 
            }
        }

        int dist = 0;
        while(not q.empty()){
            dist++;
            int size = q.size();
            while(size--){
                int r = q.front().first;
                int c = q.front().second;
                q.pop();
                for(int i = 0; i < 4; i++){
                    int nr = r + row_diff[i];
                    int nc = c + col_diff[i];
                    if (0<=nr and nr<rows and 0<=nc and nc<cols and ans[nr][nc]==-1){
                        ans[nr][nc] = dist;
                        q.push({nr, nc});
                    }
                }
            }
        }
        return ans;
    }
};



class Solution3 {
public:

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int rows = mat.size(), cols = mat[0].size();
        vector<vector<int>> ans(rows, vector<int>(cols,-1));
        int row_diff[] = {1, -1, 0, 0};
        int col_diff[] = {0, 0, 1, -1};


        queue<pair<int,int>> q;
        //O(m*n)
        for(int i=0; i<mat.size(); i++){
            for(int j=0; j<mat[0].size(); j++){
                if(mat[i][j] == 0){
                    q.emplace(i,j);
                    ans[i][j] = 0;
                } 
            }
        }
        
        while(not q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for(int i = 0; i < 4; i++){
                int nr = r + row_diff[i];
                int nc = c + col_diff[i];
                if (0<=nr and nr<rows and 0<=nc and nc<cols and ans[nr][nc]==-1){
                    ans[nr][nc] = ans[r][c] + 1;
                    q.push({nr, nc});
                }
            }
        }
        return ans;
    }
};



class Solution4 {
public:

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int rows = mat.size(), cols = mat[0].size();
        
        int row_diff[] = {1, -1, 0, 0};
        int col_diff[] = {0, 0, 1, -1};


        queue<pair<int,int>> q;
        //O(m*n)
        for(int i=0; i<mat.size(); i++){
            for(int j=0; j<mat[0].size(); j++){
                if(mat[i][j] == 0){
                    q.emplace(i,j);
                } 
                else{
                    mat[i][j] = -1;
                }
            }
        }
        
        while(not q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for(int i = 0; i < 4; i++){
                int nr = r + row_diff[i];
                int nc = c + col_diff[i];
                if (0<=nr and nr<rows and 0<=nc and nc<cols and mat[nr][nc]==-1){
                    mat[nr][nc] = mat[r][c] + 1;
                    q.push({nr, nc});
                }
            }
        }
        return mat;
    }
};

