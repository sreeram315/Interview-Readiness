// https://practice.geeksforgeeks.org/problems/rotten-oranges2536/1/?track=P100-Graph&batchId=238#
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    vector<pair<int, int>> paths = {
        {0, 1}, {0, -1}, {1, 0}, {-1, 0}
    };
    
    void change(vector<vector<int>>& arr, queue<pair<int, int>>& q, int &f){
        int n = arr.size(), m = arr[0].size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                switch(arr[i][j]){
                    case 0: arr[i][j] = -2; // empty
                    break;
                    case 1: arr[i][j] = -1; f++; // fresh
                    break;
                    case 2: arr[i][j] = 0; q.push({i, j}); // rotten
                    break;
                }
            }
        }
    }
    
    inline bool is_valid(int x, int y, int n, int m){
        return (x>=0 && y>=0 && x<n && y<m);
    }
    
    int orangesRotting(vector<vector<int>>& arr) {
        int n = arr.size(), m = arr[0].size(), f = 0, x, y, i, j, max_time = 0;
        queue<pair<int, int>>q;
        change(arr, q, f);
        pair<int, int> p;
        while(!q.empty()){
            p = q.front(), q.pop();
            i = p.first; j = p.second;
            for(const pair<int, int>& path: paths){
                x = i+path.first; y = j+path.second;
                if(is_valid(x, y, n, m) && arr[x][y]==-1){
                    arr[x][y] = arr[i][j]+1;
                    max_time = max(max_time, arr[x][y]);
                    f--;
                    q.push({x, y});
                }
            }
        }
        return (f==0) ? max_time : -1;
    }
};