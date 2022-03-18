bool findPartition(int a[], int n) {
    int s = accumulate(a, a+n, 0);
    if(s%2) return false;
    vector<vector<int>>arr(s/2+1, vector<int>(n+1, false));
    for(int i = 0; i <= s/2; i++) for(int j = 0; j <= n; j++)
        arr[i][j] = (i==0) || (j>0 && ( arr[i][j-1] || (i-a[j-1]>=0 && arr[i-a[j-1]][j-1]) ));
    return arr[s/2][n];
}