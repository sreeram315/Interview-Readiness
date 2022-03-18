int n;
vector<bool>vis, re;
bool ans;

void search(int node, vector<int> adj[]){
    vis[node] = true;
    re[node] = true;
    for(int n: adj[node]){
        if(!vis[n])
            search(n, adj);
        else if(re[n])
            ans = true;
    }
    re[node] = false;
}

//Function to return a list containing the DFS traversal of the graph.
bool isCyclic(int V, vector<int> adj[])
{
    n = V;
    vis.clear(); 
    ans = false;
    vis.resize(n, false);
    re.resize(n, false);
    for(int node = 0; node < V; node++){
        if(!vis[node])
            search(node, adj);
    }
    return ans;
}