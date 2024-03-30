//User function template for C++

class Solution {
  public:
	void shortest_distance(vector<vector<int>>&matrix){
	    int v = matrix.size();
	    
	    for(int r = 0; r<v; r++){
            for(int c = 0; c<v; c++){
                if(matrix[r][c] == -1){
                    matrix[r][c] = 1e9;
                }
            }
        }
	    //i->via
	    for(int i=0; i<v; i++){
	        for(int r = 0; r<v; r++){
	            for(int c = 0; c<v; c++){
	                if(r == i or c == i or r==c)    continue;
	                matrix[r][c] = min(matrix[r][c], matrix[r][i] + matrix[i][c] );
	            }
	        }
	    }
	    
	    for(int r = 0; r<v; r++){
            for(int c = 0; c<v; c++){
                if(matrix[r][c] == 1e9){
                    matrix[r][c] = -1;
                }
            }
        }

    //if matrix[i][i] < 0, then it means there is a negative cycle
	}
};
