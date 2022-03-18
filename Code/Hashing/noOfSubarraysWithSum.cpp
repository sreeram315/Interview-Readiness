int subArraySum(int arr[], int n, int sum) {
    unordered_set<int>ms;
    int c = 0, ans = 0;
    unordered_map<int, int>mp;
    for(int i = 0; i < n; i++){
        c += arr[i];
        if(c==sum) ans++;
        int rem = c-sum;
        ans += mp[rem];
        mp[c]++;
    }
    return ans;
}