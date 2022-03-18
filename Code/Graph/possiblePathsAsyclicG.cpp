class Solution 
{
    public:
    void search(vector<int> adj[], int node, int &ans, int &d){
        if(node == d) ans++;
        for(int n: adj[node]) search(adj, n, ans, d);
    }
	
	int countPaths(int V, vector<int> adj[], int source, int destination) {
	    int ans = 0;
	    search(adj, source, ans, destination);
	    return ans;
	}
};