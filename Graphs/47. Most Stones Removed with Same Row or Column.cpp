auto fast = []{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return false;
}();

class DisjointSet {

	public:
	vector<int> parent, size, rank;
		DisjointSet(int n){
			parent.resize(n+1,-1);
			size.resize(n+1);
			// rank.resize(n+1);
		}

        DisjointSet(){
            parent.resize(2*(1e4+1)+1,-1);
            size.resize(2*(1e4+1)+1);
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
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        DisjointSet set;
        //in set making each row no and col no as a node
        //0-1e4 are assigned to row nodes nd 1e4+1 - 2e4+2 are col nodes

        for(int i=0; i<=2*(1e4+1); i++){
            set.makeSet(i);
        }

        for(auto &s : stones){
            // if(set.findUltPar(s[0]) != set.findUltPar(s[1] + 1e4+1)){
            set.Union(s[0],s[1]+ 1e4+1);
            // }
        }
        // max stones removed = total stones - total connected components
        // if we remove any node from a components then all adjacent components will
        // be removed and only one node will be left behind
        int comp = 0;
        for(int i=0; i<=2*(1e4+1); i++){
            if (set.parent[i] == i and set.size[i] > 1){
                comp++;
            }
        }
        return n-comp;
    }
};
