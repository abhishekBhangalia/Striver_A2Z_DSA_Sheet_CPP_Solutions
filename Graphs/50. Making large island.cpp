auto fast = []{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return false;
}();

class Solution2 {
struct DSU
{
    vector<int> e;
    DSU(int n)
    {
        e = vector<int>(n, -1);
    }

    int parent(int x)
    {
        return e[x] < 0 ? x : e[x] = parent(e[x]);
    }

    int size(int x)
    {
        return -e[parent(x)];
    }

    bool union_sets(int x, int y)
    {  // union by size
        x = parent(x);
        y = parent(y);
        if (x == y) 
            return false;
        if (e[x] > e[y])
            swap(x, y);
        e[x] += e[y];
        e[y] = x;
        return true;
    }
};


public:
    int largestIsland(vector<vector<int>>& grid) {
        int r = grid.size(), c = grid[0].size();
        DSU ds(r*c);
        // int diff[] = {1,0,-1,0,1};//d,l,u,r
        int rdiff[] = {0,0,1,-1};
        int cdiff[] = {1,-1,0,0};

        //making all islands with their sizes stored in root of each island
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if(grid[i][j] == 1){
                    int curNode = i*c+j;
                    for(int k=0; k<4; k++){
                        int nr = i+rdiff[k];
                        int nc = j+cdiff[k];
                        if(0<=nr and nr<r and 0<=nc and nc<c and grid[nr][nc] == 1){
                            int newNode = nr*c+nc;
                            ds.union_sets(curNode,newNode);
                        }
                    }
                }
            }
        }
        int maxIslandSize = 0;

        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                int curNode = i*c+j;
                if(grid[i][j] == 0){
                    int curIslandSize = 1;
                    unordered_map<int,int> hasSameIsland;
                    for(int k=0; k<4; k++){
                        int nr = i+rdiff[k];
                        int nc = j+cdiff[k];
                        if(0<=nr and nr<r and 0<=nc and nc<c and grid[nr][nc] == 1){
                            int newNode = nr*c+nc;
                            int parent = ds.parent(newNode);
                            if(hasSameIsland.count(parent) == 0){
                                hasSameIsland[parent] = 1;
                                curIslandSize += ds.size(parent);
                            }
                        }
                    }
                    maxIslandSize = max(curIslandSize, maxIslandSize);
                }
                else{
                    maxIslandSize = max(ds.size(curNode), maxIslandSize);
                }
            }
        }
        return maxIslandSize;
    }
};


//TODO :- understand logic of this approach
auto $$ = [] { return ios::sync_with_stdio(0), cin.tie(0), 0; }();
int uf[500 * 500];
int find_(int i) {
    return uf[i] < 0 ? i : uf[i] = find_(uf[i]);
}
void unite_(int i, int j) {
    i = find_(i), j = find_(j);
    if (i == j) return;
    if (-uf[i] > -uf[j]) swap(i, j);
    uf[j] += uf[i], uf[i] = j;
}
const int dirs[][2] = {0, 1, 1, 0, 0, -1, -1, 0};
vector<int> ex(4);

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        memset(uf, -1, sizeof(uf[0]) * n * n);
        for (int y = 0; y < n; y++) {
            for (int x = 0; x < n; x++) {
                if (!grid[y][x]) continue;
                for (int i : {0, 1}) {
                    int ay = y + dirs[i][0], ax = x + dirs[i][1];
                    if (ay == n || ax == n) continue;
                    if (grid[ay][ax]) unite_(y * n + x, ay * n + ax);
                }
            }
        }
        int ans = 0;
        for (int y = 0; y < n; y++) {
            for (int x = 0; x < n; x++) {
                if (grid[y][x]) {
                    ans = max(ans, -uf[find_(y * n + x)]);
                    continue;
                }
                int c = 0;
                ex.clear();
                for (auto [dy, dx] : dirs) {
                    int ay = y + dy, ax = x + dx;
                    if (!~ay || !~ax || ay == n || ax == n) continue;
                    if (!grid[ay][ax]) continue;
                    int i = find_(ay * n + ax);
                    if (find(ex.begin(), ex.end(), i) == ex.end())
                        ex.push_back(i);
                }
                for (int i : ex)
                    c += -uf[i];
                ans = max(ans, c + 1);
            }
        }
        return ans;
    }
};
