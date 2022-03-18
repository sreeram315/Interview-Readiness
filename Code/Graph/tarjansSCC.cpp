class Solution
{
	public:
	int t, V;
	vector<bool>vis, re;
	stack<int>st;
	vector<int>low, disc;
	vector<vector<int>> ans;
	
	void util(int node, vector<int> adj[]){
	    vis[node] = true;
	    re[node] = true;
	    st.push(node);
	    low[node] = t; disc[node] = t++;
	    for(int n: adj[node]){
	        if(!vis[n]){
	            util(n, adj);
	            low[node] = min(low[node], low[n]);
	        } else if(re[n]){
	            low[node] = min(low[node], disc[n]);
	        }
	    }
	    if(low[node] == disc[node]){
            vector<int>arr;
            while(!st.empty() && st.top() != node){
                arr.push_back(st.top());
                re[st.top()] = false;
                st.pop();
            }
            re[st.top()] = false;
            arr.push_back(st.top()); st.pop();
            ans.push_back(arr);
        }
	}
	
    vector<vector<int>> tarjans(int V, vector<int> adj[]) {
        t = 0;
        this->V = V;
        while(!st.empty()) st.pop();
        low.clear(); low.resize(V);
        disc.clear(); disc.resize(V);
        vis.resize(V, false);
        re.resize(V, false);
        for(int node = 0; node < V; node++)
            if(!vis[node])
                util(node, adj);
        for(auto &x: ans)
            sort(x.begin(), x.end());
        sort(ans.begin(), ans.end());
        return ans;
    }
};
// https://practice.geeksforgeeks.org/problems/strongly-connected-component-tarjanss-algo-1587115621/1/?track=P100-Graph&batchId=238