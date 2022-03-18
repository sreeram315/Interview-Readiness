int findMinOpeartion(vector<vector<int> > m, int n) {
    vector<int>rs(n, 0), cs(n, 0);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            rs[i] += m[i][j];
            cs[j] += m[i][j];
        }
    }
    int s = max(*max_element(rs.begin(), rs.end()), *max_element(cs.begin(), cs.end()));
    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int aff = s-max(rs[i], cs[j]);
            ans += aff;
            m[i][j] += aff;
            rs[i] += aff;
            cs[j] += aff;
        }
    }
    return ans;
} 


// https://practice.geeksforgeeks.org/problems/make-matrix-beautiful-1587115620/1/?track=P100-Matrix&batchId=238