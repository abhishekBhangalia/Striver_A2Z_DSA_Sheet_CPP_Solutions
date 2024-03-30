auto fast = []{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return false;
}();

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        // vector<vector<int>> matrix(n, vector<int>(n,1e9));
        // not using vector saves 13 ms 
        int matrix[n][n];
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                matrix[i][j] = 10001;
            }
        }
        for(auto &edge:edges){
            matrix[edge[0]][edge[1]] = edge[2];
            matrix[edge[1]][edge[0]] = edge[2];
        }
	    int minCities = n;
        int city = 0;
        // n--;
        int i;
        int is = n-1;
	    for(i=0; i<is; i++){
	        for(int r = 0; r<n; r++){
	            for(int c = 0; c<n; c++){
	                if(r == i or c == i or r==c)    continue;
	                matrix[r][c] = min(matrix[r][c], matrix[r][i] + matrix[i][c] );
	            }
	        }
	    }
        
	    for(int r = 0; r<n; r++){
            int cities = 0;
            for(int c = 0; c<n; c++){
                if(r==c)    continue;
                matrix[r][c] = min(matrix[r][c], matrix[r][i] + matrix[i][c] );
                if(matrix[r][c] <= distanceThreshold){
                    cities++;
                }
            }
            if(cities <= minCities){
                minCities = cities;
                city = r;
            }
        }
        return city;
    }
};

class Solution2 {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        int dist[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dist[i][j] = i == j ? 0 : 10001;
            }
        }
        for (auto &e : edges) {
            dist[e[0]][e[1]] = dist[e[1]][e[0]] = e[2];
        }
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
        int res = -1, resCount = INT_MAX;
        for (int i = 0; i < n; i++) {
            int count = 0;
            for (int j = 0; j < n; j++) {
                if (dist[i][j] <= distanceThreshold) {
                    count++;
                }
            }
            if (count <= resCount) {
                resCount = count;
                res = i;
            }
        }
        return res;
    }
};
