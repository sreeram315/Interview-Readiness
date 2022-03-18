int n;
vector<bool>vis;
bool ans;

void search(int node, vector<int> adj[], int prev = -1){
    vis[node] = true;
    for(int n: adj[node]){
        if(!vis[n])
            search(n, adj, node);
        else if(prev != n)
            ans = true;
    }
}

//Function to return a list containing the DFS traversal of the graph.
bool isCycle(int V, vector<int> adj[])
{
    n = V;
    vis.clear(); 
    ans = false;
    vis.resize(n, false);
    for(int node = 0; node < V; node++){
        if(!vis[node])
            search(node, adj);
    }
    return ans;
}