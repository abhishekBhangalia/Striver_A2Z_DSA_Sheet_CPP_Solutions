class Solution{
    public:
    string findOrder(string dict[], int N, int K) {
        //code here
        unordered_map<char,vector<char>> adj;
        unordered_map<char,int> inc;
        for(int i=0; i<N-1; i++){
            for(int j=0; j<dict[i].length(); j++){
                if(dict[i][j]!=dict[i+1][j]){
                    adj[dict[i][j]].push_back(dict[i+1][j]);
                    inc[dict[i+1][j]]++;
                    break;
                }
            }
        }
        
        string order = "";
        queue<char> q;
        
        for(char c = 'a';c<'a'+K; c++){
            if(inc[c]==0){
                q.push(c);
            }
        }
        
        while(!q.empty()){
            char c = q.front();
            q.pop();
            order+=c;
            for(char d:adj[c]){
                if(--inc[d]==0){
                    q.push(d);
                }
            }
        }
        return order;
        
    }
};
