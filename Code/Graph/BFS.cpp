vector<int>bfsOfGraph(int n, vector<int> adj[])
{
    queue<int>q;
    q.push(0);
    vector<bool>vis(n, false);
    vis[0] = true;
    vector<int> ans(n); 
    int ind = 0, node;
    while(!q.empty()){
        node = q.front(); q.pop();
        ans[ind++] = node;
        for(int x: adj[node]){
            if(!vis[x]){
                vis[x] = true;
                q.push(x);
            }
        }
    }
    ans.resize(ind);
    return ans;
}