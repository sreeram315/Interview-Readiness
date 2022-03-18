vector<int> topoSort(int n, vector<int> adj[]) {
   vector<int>in(n, 0), ans;
   for(int node = 0; node < n; node++)
       for(int n: adj[node])  in[n]++;
   queue<int>q;
   for(int i = 0; i < n; i++)
        if(in[i] == 0) q.push(i);
   int node;
   while(!q.empty()){
       node = q.front(); q.pop();
       for(int n: adj[node]){
           in[n]--;
           if(in[n] == 0) q.push(n);
       }
       ans.push_back(node);
   }
   return ans;
}