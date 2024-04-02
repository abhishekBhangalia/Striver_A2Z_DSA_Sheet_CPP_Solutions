auto fast = []{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return false;
}();


class DisjointSet {
	vector<int> parent, size, rank;

	public:
		DisjointSet(int n){
			parent.resize(n+1,-1);
			size.resize(n+1);
			// rank.resize(n+1);
		}

		void makeSet(int v){
			parent[v] = v;
			size[v] = 1;
			// rank[v] = 1;
		}

		//find ultimate parent with path compression
		int findUltPar(int v){
			if(parent[v] == v){
				return v;
			}
			return parent[v] = findUltPar(parent[v]);
		}

		void Union(int v1, int v2) {
			int p1 = findUltPar(v1), p2 = findUltPar(v2);
			if(p1 == p2)	return;

			//union by size
			if(size[p1] < size[p2]){
				size[p1] += size[p2];
				parent[p2] = p1;
			}
			else{
				size[p2] += size[p1];
				parent[p1] = p2;
			}

			// //union by rank
			// if(rank[p1] < rank[p2]){
			// 	parent[p1] = p2;
			// }
			// else if(rank[p2] < rank[p1]){
			// 	parent[p2] = p1;
			// }
			// else{
			// 	parent[p2] = p1;
			// 	rank[p1]++;
			// }
		}
};



class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        
        DisjointSet set(n);
        for(int i=0; i<n; i++){
            set.makeSet(i);
        }

        int extra_edges = 0;
        for(auto &conn : connections){
            if(set.findUltPar(conn[0]) != set.findUltPar(conn[1])){
                set.Union(conn[0], conn[1]);
            }
            else{
                extra_edges++;
            }
        }
        vector<int> vis(n);
        int comp = 0;
        for(int i=0; i<n; i++){
            int p = set.findUltPar(i);
            if (not vis[p]){
                vis[p] = 1;
                comp++;
            }
        }
        
        if (extra_edges + 1 >= comp ){
            return comp-1;
        }
        return -1;

    }
    
};
