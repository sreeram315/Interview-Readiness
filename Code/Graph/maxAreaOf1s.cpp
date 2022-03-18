class Solution {
public:
    int r, c, count;
    vector<vector<bool>>vis;
    vector<pair<int, int>>paths = {
                                    {0, 1}, {1, 1}, {1, 0},
                                    {1, -1}, {0, -1}, {-1, -1},
                                    {-1, 0}, {-1, 1}
                            };
    
    bool is_safe(pair<int, int>p){
        int x = p.first, y = p.second;
        return( (x>=0) && (y>=0) && (x<r) && (y<c) );
    }
    
    void util(pair<int, int>p, const vector<vector<int>>&arr){
        int i = p.first, j = p.second;
        vis[i][j] = true;
        count++;
        for(auto el: paths){
            int x = i+el.first, y = j+el.second;
            if(is_safe({x, y}) && arr[x][y]==1 && !vis[x][y]){
                util({x, y}, arr);
            }
        }
    }
    
    int findMaxArea(const vector<vector<int>>& arr) {
        r = arr.size(); c = arr[0].size();
        vis.resize(r, vector<bool>(c, false));
        int ans = INT_MIN;
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                count = 0;
                if(arr[i][j]==1 && !vis[i][j]){
                    util({i, j}, arr);
                }
                ans = max(ans, count);
            }
        }
        return ans;
    }
};