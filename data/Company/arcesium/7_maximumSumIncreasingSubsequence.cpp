
int maxSumIncreasingSubsequence(int arr[], int n) {  
    vector<int>ans(n, 0);
    ans[0] = arr[0];
    for(int i = 1; i < n; i++){
        ans[i] = max(ans[i], arr[i]);
        for(int j = 0; j < i; j++){
            if(arr[j]<arr[i])
                ans[i] = max(ans[i], ans[j]+arr[i]);
        }
    }
    return *max_element(ans.begin(), ans.end());
}  