

class Solution {
public:

    //BFS
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int provinces = 0;
        int *vis = new int[n];
        memset(vis, 0, n*sizeof(int));
        queue<int> q;

        for(int i=0; i<n; i++){
            if(vis[i] != 1){
                provinces++;
                vis[i] = 1;
                q.push(i);

                while(not q.empty()){
                    int x = q.front();
                    q.pop();
                    
                    for(int nb = 0; nb<n; nb++){
                        if(vis[nb] == 0 and isConnected[x][nb]){

                            //it is important to update state of neighbor to visited
                            //this neighbor can be pushed many times to the queue
                            //and tc will increase
                            //although the ans will be same whether we update vis array
                            //before pushing to q or after popping from q
                            vis[nb] = 1;
                            q.push(nb);
                        }
                    }
                }
            }
        }
        return provinces;
    }
};
