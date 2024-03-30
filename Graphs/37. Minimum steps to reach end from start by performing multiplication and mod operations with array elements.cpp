int MOD = 1e3;

int minimumOperations(int n, int start, int end, vector<int> &a)
{
    if(start == end)    return 0;
   queue<int> q;
   q.push(start);
   int steps = 0;
   int vis[MOD] = {0};

   while(not q.empty()){
       steps++;
       int size = q.size();
       while(size--){
           long long prod = q.front();
           q.pop();

           for(auto &x:a){
               int newProd = (prod * x) % MOD;
               if(newProd == end)   return steps;

               if(not vis[newProd]){ // it is important to check otherwise multiple same no with same steps will be push to queue (for eg 3 -> 5 -> 10 = 150, 5 -> 3 -> 10 = 150)
                   vis[newProd] = 1;
                   q.push(newProd);
               }
           }
       }
   }
   return -1;
}
