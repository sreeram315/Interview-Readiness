class Solution{
	public:
    
    int min_index(const vector<int>&arr, const vector<bool>&done){
        bool flag =  true;
        int el, ind;
        for(int i = 0; i < arr.size(); i++){
            if(!done[i] && (flag || el > arr[i])){
                el  = arr[i];
                ind = i;
                flag = false;
            }
        }
        return ind;
    }
    
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S) {
        vector<int>dist(V, INT_MAX);
        vector<bool>done(V, false);
        dist[S] = 0;
        for(int i = 0; i < V-1; i++){
            int node = min_index(dist, done);
            for(auto x: adj[node]){
                int n = x[0], w = x[1];
                if(!done[n])
                    dist[n] = min(dist[n], dist[node]+w);
            }
            done[node] = true;
        }
        return dist;
    }
};