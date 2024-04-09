#pragma GCC optimize("O3")

auto fast = []{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return false;
}();


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

class Solution1 {
    
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DSU ds(n);
        map<string,int> m;

        for(int i = 0; i<n; i++){
            for(int j=1; j<accounts[i].size(); j++){
                if(m.find(accounts[i][j]) == m.end()){
                    m[accounts[i][j]] = i;
                } else {
                    ds.union_sets(i,m[accounts[i][j]]);
                }
            }
        }

        vector<vector<string>> ans;
        vector<int> isVecInit(n);
        for(auto i = m.begin(); i!=m.end(); i++){
            int rparent = i->second;
            if(ds.parent(i->second) != i->second){ // root parent
                rparent = ds.parent(i->second);   
            }
            if(not isVecInit[rparent]){
                isVecInit[rparent] = true;
                vector<string> tmp;
                tmp.push_back(accounts[rparent][0]);
                tmp.push_back(i->first);
                ans.push_back(tmp);
                ds.e[rparent] = -ans.size();
            }else{
                int j = - ds.e[rparent] - 1;
                ans[j].push_back(i->first);
            }
        }
        // no need to sort as keys are stored in sorted order in map
        // for(auto &v : ans){
        //     sort(v.begin(), v.end());
        // }
        return ans;
    }
};



#pragma GCC optimize("O3")
int find_root(vector<int>& root,int root_id){
    if(root[root_id]!=root_id){
        root[root_id] = find_root(root,root[root_id]);
    }
    return root[root_id];
}

class Solution2 {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        vector<vector<string>> ans;
        unordered_map<string,int> email_id;
        vector<int> root(accounts.size(),0);
        for(int i=0;i<accounts.size();i++){
            root[i]=i;
            for(int j=1;j<accounts[i].size();j++){
                if(email_id.find(accounts[i][j])!=email_id.end()){
                    root[find_root(root,email_id[accounts[i][j]])]=i;
                }
                else{
                    email_id[accounts[i][j]]=i;
                }
            }
        }

        unordered_map<int, vector<string>> temp_map;
        for(auto& email:email_id){
            temp_map[find_root(root,email.second)].emplace_back(email.first);
        }

        for(auto& account:temp_map){
            ans.push_back({accounts[account.first][0]});
            sort(account.second.begin(),account.second.end());
            ans.back().insert(ans.back().end(),account.second.begin(), account.second.end());
        }

        return ans;
    }
};


class Solution3 {
public:
    class DisjointSet {
    
public:
    vector<int> rank,parent,size;
    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        size.resize(n+1,1);
        for(int i=0;i<=n;i++){
            parent[i] = i;
        }
    }

    int findUPar(int node){
        if(parent[node] == node){
            return node;
        }
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if(ulp_u == ulp_v){
            return;
        }

        if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v; 
        }
        else if(rank[ulp_v] < rank[ulp_u]){
            parent[ulp_v] = ulp_u;
        }
        else{
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

        void unionBySize(int u, int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if(ulp_u == ulp_v){
            return;
        }

        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u]; 
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }

    }
};
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DisjointSet ds(n);
        unordered_map<string, int> mail_name;
        for(int i=0;i<accounts.size();i++){
            for(int j=1;j<accounts[i].size();j++){
                if(!mail_name.count(accounts[i][j])){
                    mail_name[accounts[i][j]] = i;
                }
                else{
                    ds.unionBySize(mail_name[accounts[i][j]], i); //
                }
            }
        }

        vector<string> mailStore[n];

        for(auto x:mail_name){
            int node = ds.findUPar(x.second);
            string mail = x.first;

            mailStore[node].push_back(mail);
        }

        vector<vector<string>> ans;
        for(int i=0;i<n;i++){
           if(mailStore[i].size() == 0){
                continue;
            }
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            sort(mailStore[i].begin(), mailStore[i].end());

            for(int j=0;j<mailStore[i].size();j++){
                temp.push_back(mailStore[i][j]);
            }

            ans.push_back(temp);
        }
        return ans;
    }

};
