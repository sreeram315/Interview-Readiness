class Solution{
	public:
	
    int spanningTree(int V, vector<vector<int>> adj[]) {
        vector<int>dist(V, INT_MAX);
        vector<bool>done(V, false);
        dist[0] = 0;
        int ans = 0;
        for(int ind = 0; ind < V; ind++){
            int n, w = INT_MAX;
            for(int i = 0; i < V; i++){
                if(!done[i] && w > dist[i]){
                    n = i; w = dist[i];
                }
            }
            done[n] = true;
            ans += w;
            for(auto x: adj[n]){
                int m = x[0], w = x[1];
                dist[m] = min(dist[m], w);
            }
        }
        return ans;
    }
};