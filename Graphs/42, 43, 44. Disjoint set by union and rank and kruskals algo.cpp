// class DisjointSet {
// 	vector<int> parent, size, rank;

	

// 	public:
// 		DisjointSet(int n){
// 			parent.resize(n+1,-1);
// 			size.resize(n+1);
// 			// rank.resize(n+1);
// 		}

// 		int makeSet(int v){
// 			parent[v] = v;
// 			size[v] = 1;
// 			// rank[v] = 1;
// 		}

// 		//find ultimate parent with path compression
// 		int findUltPar(int v){
// 			if(parent[v] == v){
// 				return v;
// 			}
// 			return parent[v] = findUltPar(parent[v]);
// 		}

// 		void Union(int v1, int v2) {
// 			int p1 = findUltPar(v1), p2 = findUltPar(v2);
// 			if(p1 == p2)	return;

// 			//union by size
// 			if(size[p1] < size[p2]){
// 				size[p1] += size[p2];
// 				parent[p2] = p1;
// 			}
// 			else{
// 				size[p2] += size[p1];
// 				parent[p1] = p2;
// 			}

// 			// //union by rank
// 			// if(rank[p1] < rank[p2]){
// 			// 	parent[p1] = p2;
// 			// }
// 			// else if(rank[p2] < rank[p1]){
// 			// 	parent[p2] = p1;
// 			// }
// 			// else{
// 			// 	parent[p2] = p1;
// 			// 	rank[p1]++;
// 			// }
// 		}
// };

// bool comparator(vector<int> e1, vector<int> e2){
// 	return e1[2] < e2[2];
// }

// int kruskalMST(int n, vector<vector<int>> &edges)
// {
// 	DisjointSet set(n);
// 	for(int i=0; i<=n; i++){
// 		set.makeSet(i);
// 	}

// 	//sorting edges in ascending order of weights
// 	sort(edges.begin(), edges.end(), comparator);
// 	int cost = 0;

// 	for(auto &e : edges){
// 		int p1 = set.findUltPar(e[0]), p2 = set.findUltPar(e[1]);
// 		if(p1 != p2){
// 			set.Union(e[0], e[1]);
// 			cost += e[2];
// 		}
// 	}
// 	return cost;
// }



/*
    Time Complexity: O(m * log(m) + n)
    Space Complexity: O(n + m)

    Where 'n' and 'm' denotes the number of nodes and edges in the graph, respectively.

	Time Complexity
O(m * log(m) + n), Where ‘n’ and ‘m’ denote the number of nodes and edges in the graph, respectively.

Since we are sorting the array/list of edges, it will take O(m * log(m)) time. And then we are initialising the DSU which 
takes O(n) time. Along with that at each iteration of merging, we are checking if they belong to the same subtree, and 
merging them if they are not. This takes O(1) time. Thus the overall time complexity will be O(m * log(m) + n).

Space Complexity
O(n + m), Where ‘n’ and ‘m’ denotes the number of nodes and edges in the graph, respectively.

Since we are storing the array/list of edges in O(m) space and the DSU data structure consumes O(n) space, thus the overall space complexity will be O(n + m).
*/

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

// Custom comparator to sort the edges.
bool compare(vector <int> const &a, vector <int> const &b)
{
    return a[2] < b[2];
}

int kruskalMST(int n, vector<vector<int>> &edges)
{
    DSU d(n + 1);

    // To store the weight of MST.
    int cost = 0;

    // Sort the edges in ascending order by its weight.
    sort(edges.begin(), edges.end(), compare);

    // Start traversign through the edges.
    for (auto& edge: edges)
    {
        // Check if both vertices of current edge belong to different sets(subtrees).
        if (d.parent(edge[0]) != d.parent(edge[1]))
        {
            // Add the weight of the current edge.
            cost += edge[2];

            // Merge the two sets(subtrees).
            d.union_sets(edge[0], edge[1]);
        }
    }
    return cost;
}
