class Solution
{
	public:
	int n;
	vector<int>parent, height;
	
	int Rank(int x){
	    if(x==parent[x]) return x;
	    parent[x] = Rank(parent[x]);
	    return parent[x];
	}
	
	void merge(int x, int y){
	    x = Rank(x); y = Rank(y);
	    if(x == y) return;
	    if(height[x] > height[y])
	        parent[y] = x;
	    else if(height[x] < height[y])
	        parent[x] = y;
	    else{
	        parent[x] = y;
	        height[y]++;
	    }
	}
	
	struct Node{
	    int u, v, w;
	    Node(int u, int v, int w){
	        this->u = u;
	        this->v = v;
	        this->w = w;
	    }
	};
	
	vector<Node*> calc(int N, vector<vector<int>> adj[]){
	    int ind = 0, v, w;
	    n = N;
	    vector<Node*>arr(n);
	    parent.resize(n);
	    height.resize(n, 0);
	    for(int i = 0; i < n; i++) parent[i] = i;
	    for(int u = 0; u < n; u++){
	        for(auto el: adj[u]){
	            v = el[0]; w = el[1];
	            if(u>v) continue;
	            arr[ind++] = new Node(u, v, w);
	        }
	    }
	    return arr;
	}
	
	struct comp{
	    bool operator()(Node *n1, Node *n2){
	        return n1->w > n2->w;
	    }
	};
    
    int spanningTree(int V, vector<vector<int>> adj[]) {
        vector<Node*>arr = calc(V, adj);
        priority_queue<Node*, vector<Node*>, comp>pq(arr.begin(), arr.end());
        int u, v, w, ans = 0;
        while(!pq.empty()){
            Node* p = pq.top(); pq.pop();
            u = p->u; v = p->v; w = p->w;
            if(Rank(u)==Rank(v)) continue;
            merge(u, v);
            ans += w;
        }
        return ans;
    }
};