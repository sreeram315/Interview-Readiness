class Solution {
public:
    vector<bool>vis;
    int N, ans = -1;
    
    void util(int node, vector<int>adj[]){
        vis[node] = true;
        for(int n: adj[node]){
            if(!vis[n])
                util(n, adj);
        }
        ans = node;
    }
    
    bool check_it(int node, vector<int>adj[]){
        vis.clear();
        vis.resize(N, false);
        util(node, adj);
        for(bool b: vis){
            if(!b) return false;
        }
        return true;
    }
    
	int findMotherVertex(int V, vector<int>adj[]){
	    N = V;
	    vis.resize(V, false);
	    for(int i = 0; i < V; i++){
	        if(!vis[i])
	            util(i, adj);
	    }
	    if(check_it(ans, adj)) 
	        return ans;
	    return -1;
	}

};