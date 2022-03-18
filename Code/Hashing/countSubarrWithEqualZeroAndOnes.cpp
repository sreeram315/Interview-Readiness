long long int countSubarrWithEqualZeroAndOne(int arr[], int n, int sum = 0) {
    for(int i = 0; i < n; i++)
        if(arr[i] == 0) arr[i] = -1;
    unordered_map<int, int>ms;
    int c = 0, ans = 0, rem;
    for(int i = 0; i < n; i++){
        c += arr[i];
        if(c == 0) ans++;
        ans += ms[c];
        ms[c]++;
    }
    return ans;
}