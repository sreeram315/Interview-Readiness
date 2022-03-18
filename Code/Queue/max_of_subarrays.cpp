vector <int> max_of_subarrays(int *arr, int n, int k){
    deque<pair<int, int>>d;
    vector<int>ans(n-k+1); int ind = 0;
    for(int i = 0; i < k; i++){
        while(!d.empty() && (d.back()).first <= arr[i])
            d.pop_back();
        d.push_back({arr[i], i});
    }
    ans[0] = d.front().first;
    for(int i = k; i < n; i++){
        while(!d.empty() && (d.back()).first <= arr[i])
            d.pop_back();
        while(!d.empty() && (d.front()).second <= i-k)
            d.pop_front();
        d.push_back({arr[i], i});
        ans[i-k+1] = d.front().first;
    }
    return ans;
}