class Solution{
	public:
	int V, ind;
	vector<int>arr, vis;

	void dfs(int node, vector<int> adj[], bool flag = true){
	    vis[node] = true;
	    for(int n: adj[node]){
	        if(!vis[n])
	            dfs(n, adj, flag);
	    }
	    if(flag)
	        arr[--ind] = node;
	}
	
    int kosaraju(int V, vector<int> adj[]) {
        this->V = V; ind = V;
        arr.resize(V); vis.resize(V, false);
        
        vector<int>radj[V];
	    for(int v1 = 0; v1 < V; v1++){
	        for(int v2: adj[v1]){
	            radj[v2].push_back(v1);
	        }
	    }
	    
        for(int n = 0; n < V; n++){
            if(!vis[n])
                dfs(n, adj);
        }
        vis.clear(); vis.resize(V, false);
        int count = 0; ind = V;
        for(int node: arr){
            if(!vis[node]){
                dfs(node, radj, false);
                count++;
            }
        }

        return count;
    }
};