// https://practice.geeksforgeeks.org/problems/minimum-cost-path3833/1/?track=P100-Graph&batchId=238
class Solution
{
    public:
    
    vector<pair<int, int>>paths = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    
    struct Node{
        int x, y, d;
        Node(int x, int y, int d){
            this->x = x;
            this->y = y;
            this->d = d;
        }
    };
    
    struct comp{
        bool operator()(Node *n1, Node *n2){
            return (n1->d > n2->d);
        }
    };
    
    inline bool is_valid(int x, int y, int n){
        return x>=0 && y>=0 && x<n && y<n;
    }
    
    int minimumCostPath(vector<vector<int>>& arr) {
        int n = arr.size(), ind = 0, i, j, x, y, d, nd;
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        vector<vector<bool>> vis(n, vector<bool>(n, false));
        dist[0][0] = arr[0][0];
        vector<Node*> temp(n*n);
        for(int i = 0; i < n; i++) for(int j = 0; j < n; j++)
            temp[ind++] = (i==0 && j==0) ? (new Node(i, j, arr[0][0])) :  (new Node(i, j, INT_MAX));
        priority_queue<Node*, vector<Node*>, comp>pq(temp.begin(), temp.end());
        int t = n*n;
        while(t--){
            Node *p = pq.top(); pq.pop();
            i = p->x; j = p->y; d = p->d;
            if(i==n-1 && j==n-1) return d; // reached solution
            if(vis[i][j]) continue; // already processed, skip.
            vis[i][j] = true;
            for(pair<int, int>path: paths){
                x = i+path.first; y = j+path.second;
                if(is_valid(x, y, n)){
                    if(dist[x][y] > d+arr[x][y]){
                        nd = d+arr[x][y];
                        dist[x][y] = nd;
                        pq.push(new Node(x, y, nd));
                    }
                }
            }
        }
        return -1;
    }
};