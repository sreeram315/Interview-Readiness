 

vector<vector<int>> get_cofac(vector<vector<int> > m, int k){
    vector<vector<int>>arr(m.size()-1, vector<int>(m[0].size()-1, 0));
    int row = 0, col = 0;
    for(int i = 1; i < m.size(); i++){
        for(int j = 0; j < m.size(); j++){
            if(j==k) continue;
            arr[row][col++] =  m[i][j];
        }
        row++; col = 0;
    }
    return arr;
}

int determinantOfMatrix(vector<vector<int> > m, int n)
{
    if(n==1) return m[0][0];
    int ans = 0;
    for(int i = 0; i < n; i++){
        int el = m[0][i];
        int sign = (i%2 == 0) ? +1 : -1;
        vector<vector<int>> cofac = get_cofac(m, i);
        int det_cofac = determinantOfMatrix(cofac, n-1);
        ans += (el*sign*det_cofac);
    } 
    return ans;
}