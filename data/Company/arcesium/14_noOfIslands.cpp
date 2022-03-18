// https://leetcode.com/problems/number-of-islands/
class Solution {
public:
    int n, m;
    vector<vector<bool>>vis;
    vector<pair<int, int>>paths = {{0,1}, {0,-1}, {1,0}, {-1,0}};
    
    inline bool is_valid(int x, int y){
        return x>=0 && y>=0 && x<n && y<m;
    }
    
    void util(vector<vector<char>>& arr, int i, int j){
        vis[i][j] = true;
        for(pair<int, int>& path: paths){
            int x = i+path.first, y = j+path.second;
            if(!is_valid(x, y) || vis[x][y] || arr[x][y]=='0') continue;
            util(arr, x, y);
        }
    }
    
    int numIslands(vector<vector<char>>& arr) {
        n = arr.size(); m = arr[0].size();
        vis.resize(n, vector<bool>(m, false));
        int count = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(vis[i][j] || arr[i][j]=='0') continue;
                util(arr, i, j);
                count++;
            }
        }
        return count;
    }
};