class Solution {
    class DisjointSet{
        public:
        int n;
        vector<int>parent, height;
        DisjointSet(int n): n(n){
            height.resize(n);
            parent.resize(n);
            for(int i = 0; i < n; i++)
                parent[i] = i;
        }
        int getParent(int node){
            if(parent[node] == node) return node;
            parent[node] = getParent(parent[node]);
            return parent[node];
        }
        void combine(int node1, int node2){
            node1 = getParent(node1); node2 = getParent(node2);
            if(node1 == node2) return;
            if(height[node1]>height[node2]){
                parent[node2] = node1;
            }else if(height[node1]<height[node2]){
                parent[node1] = node2;
            }else{
                parent[node1] = node2;
                height[node2]++;
            }
        }
        int getNoOfComponents(){
            for(int node = 0; node < n; node++) this->getParent(node);
            return unordered_set<int>(parent.begin(), parent.end()).size();
        }
    };
    
public:
    int minimumCost(int n, vector<vector<int>>& connections) {
        DisjointSet mySet(n);
        sort(connections.begin(), connections.end(), [](vector<int>& e1, vector<int>& e2){return e1[2]<e2[2];});
        int cost = 0, count = 0;
        for(vector<int>& edge: connections){
            int u = edge[0]-1, v = edge[1]-1, w = edge[2];
            if(mySet.getParent(u) != mySet.getParent(v)){
                mySet.combine(u, v);
                cost += w;
                count++;
            }
            if(count == n-1) break;
        }
        return (count == n-1) ? cost : -1;
    }
};