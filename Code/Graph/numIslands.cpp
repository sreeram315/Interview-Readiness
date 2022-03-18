class Solution {
public:
    int n, m;
    vector<vector<bool>> vis;
    vector<pair<int, int>> paths = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    
    bool is_valid(int x, int y){
        return (x>=0 && y>=0 && x<n && y<m);
    }
    
    void search(const vector<vector<char>>& grid, pair<int, int> p){
        int x = p.first, y = p.second;
        vis[x][y] = true;
        for(pair<int, int> path: paths){
            int i = x+path.first, j = y+path.second;
            if(is_valid(i, j) && !vis[i][j] && grid[i][j]=='1')
                search(grid, {i, j});
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        n = grid.size(); m = grid[0].size();
        vis.resize(n, vector<bool>(m, false));
        int count = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(vis[i][j] || grid[i][j]=='0') {
                    vis[i][j] = true;
                    continue;
                }
                search(grid, {i, j});
                count++;
            }
        }
        return count;
    }
};
// https://leetcode.com/problems/number-of-islands/