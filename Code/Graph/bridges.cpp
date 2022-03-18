// https://leetcode.com/problems/critical-connections-in-a-network/
class Solution {
public:
    int t;
	vector<int>low, disc;
	vector<bool>vis, re;
    map<int, vector<int>>mp;
	int V;
	
	void util(int node, int p = -1){
	    vis[node] = true;
	    low[node] = t; disc[node] = t++;
	    for(int n: mp[node]){
	        if(!vis[n]){
	            util(n, node);
	            low[node] = min(low[node], low[n]);
	        } else if(p!=n)
	            low[node] = min(low[node], disc[n]);
	    }
	}
    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& adj) {
        t = 0;
        this->V = n;
        low.clear(); low.resize(V);
        disc.clear(); disc.resize(V);
        vis.resize(V, false);
        re.resize(V, false);
        for(auto x: adj){
            mp[x[0]].push_back(x[1]);
            mp[x[1]].push_back(x[0]);
        }
        for(int node = 0; node < V; node++)
            if(!vis[node])
                util(node);
        
        vector<vector<int>>ans;
        for(int i = 0; i < V; i++)
            for(int j: mp[i])
                if(disc[i] < low[j]) ans.push_back({i, j});
        return ans;
    }
};




















