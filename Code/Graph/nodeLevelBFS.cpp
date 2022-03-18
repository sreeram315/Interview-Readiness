class Solution{
	public:
	vector<bool>vis;
	int nodeLevel(int V, vector<int> adj[], int X) {
	    vis.resize(V, false);
	    queue<pair<int,int>>q;
	    q.push({0, 0});
	    while(!q.empty()){
	        int size = q.size();
	        while(size--){
	            auto x = q.front(); q.pop();
	            if(x.first == X) return x.second;
	            for(int node: adj[x.first]){
	                if(!vis[node]){
	                    q.push({node, x.second+1});
	                    vis[node] = true;
	                }
	            }
	        }
	    }
	    return -1;
	}
};