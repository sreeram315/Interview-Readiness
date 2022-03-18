
int n;
vector<bool>vis;
vector<int>ans;

void search(int node, vector<int> adj[]){
    vis[node] = true;
    ans.push_back(node);
    for(int n: adj[node]){
        if(!vis[n])
            search(n, adj);
    }
}

vector<int>dfsOfGraph(int V, vector<int> adj[])
{
    n = V;
    vis.clear(); ans.clear();
    vis.resize(n, false);
    for(int node = 0; node < V; node++){
        if(!vis[node])
            search(node, adj);
    }
    return ans;
}