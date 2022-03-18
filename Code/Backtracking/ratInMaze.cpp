// all ways to reach NN from 00 in matrix
// (this is not backtraking as all paths needed) https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1/?track=P100-Backtracking&batchId=238
// (backtraking for shortest path) SEE https://practice.geeksforgeeks.org/problems/rat-maze-with-multiple-jumps-1587115621/1/?track=P100-Backtracking&batchId=238

class Solution{
    public:
    int n;
    vector<string>ans;
    vector<vector<bool>>re;
    vector<pair<int, int>>paths = { {1, 0}, {0, -1}, {0, 1}, {-1, 0}};
    vector<char>mp = {'D','L','R','U'};
    
    inline bool is_valid(int x, int y){
        return x>=0 && y>=0 && x<n && y<n;
    }
    
    void util(pair<int, int> p, vector<vector<int>> &m, string s = ""){
        int i = p.first, j = p.second;
        if(i==n-1 && j==n-1){
            ans.push_back(s);
            return;
        }
        re[i][j] = true;
        for(int ind = 0; ind < paths.size(); ind++){
            pair<int, int>p = paths[ind];
            int x = i+p.first, y = j+p.second;
            if(is_valid(x, y) && !re[x][y] && m[x][y]==1)
                util({x, y}, m, s+mp[ind]);
        }
        re[i][j] = false;
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        if(!m[0][0]) return {};
        this->n = n;
        ans.clear();
        re.clear(); re.resize(n, vector<bool>(n, false));
        util({0, 0}, m);
        return ans;
    }
};