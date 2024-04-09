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


vector<int> numOfIslands(int n, int m, vector<vector<int>>& queries)
{
    DSU ds(n*m);
    int islands = 0;
    vector<int> ans;
    int diff[] = {1,0,-1,0,1}; //d,l, u,r
    int** grid = new int*[n];
    for(int i=0; i<n; i++){
        grid[i] = new int[m];
        memset(grid[i], 0, sizeof(int)*m);
    }

    for(auto &q : queries){
        if(grid[q[0]][q[1]] == 1){ //in case of duplicate query, no need to do further steps.
            ans.emplace_back(islands);
            continue;
        }
        islands++;
        grid[q[0]][q[1]] = 1;
        int curNode = q[0]*m + q[1];
        for(int i=1; i<5; i++){
            int nr = q[0]+diff[i-1];
            int nc = q[1]+diff[i];
            
            if(nr >=0 and nr <n and nc>=0 and nc<m and grid[nr][nc] == 1){
                int newNode = nr*m + nc;
                bool hadDiffComp = ds.union_sets(curNode, newNode);
                if(hadDiffComp){
                    islands--;
                }
            }
        }
        ans.emplace_back(islands);
    }
    return ans;
}
