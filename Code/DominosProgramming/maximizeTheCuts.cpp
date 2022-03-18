int maximizeTheCuts(int n, int x, int y, int z) {
    vector<int>arr(n+1);
    arr[0] = 0;
    for(int i = 1; i <= n; i++){
        int a = (i-x>=0) ? arr[i-x]+1 : INT_MIN,
            b = (i-y>=0) ? arr[i-y]+1 : INT_MIN,
            c = (i-z>=0) ? arr[i-z]+1 : INT_MIN;
        arr[i] = max(a, max(b, c));
    }
    return max(arr[n], 0);
}