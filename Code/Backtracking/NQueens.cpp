// https://leetcode.com/problems/n-queens/

class Solution {
public:
    int n, k;
    vector<string>arr;
    vector<vector<string>>ans;
    
    bool is_safe(int r, int c){
        for(int i = 0; i < c; i++){
            if(arr[r][i] == 'Q')
                return false;
        }
        int i1, j1, i2, j2; // only need to check top diagnols, since adding column after column
        for(int k = 1; k <= c; k++){
            i1 = r-k; j1 = c-k;
            if(i1>=0 && j1>=0 && arr[i1][j1]=='Q') return false;
            i2 = r+k; j2 = c-k;
            if(i2<n && j2>=0 && arr[i2][j2]=='Q') return false;
        }
        
        // for(int i = r-1, j = c-1; i>=0&&j>=0; i--, j--){
        //     if(arr[i][j] == 'Q') return false;
        // }
        // for(int i = r+1, j = c-1; i<n&&j>=0; i++, j--){
        //     if(arr[i][j] == 'Q') return false;
        // }
        return true;
    }
    
    void solve(int col = 0){
        if(col == n){
            ans.push_back(arr);
            return;
        }
        for(int row = 0; row < n; row++){
            arr[row][col] = 'Q';
            if(is_safe(row, col))
                solve(col+1);
            arr[row][col] = '.';
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        string str;
        for(int i = 0; i < n; i++) str += ".";
        arr.resize(n, str);
        this->n = n;
        solve();
        return ans;
    }
};