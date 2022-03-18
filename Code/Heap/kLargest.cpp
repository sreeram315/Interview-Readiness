vector<int> kLargest(int arr[], int n, int k){
    priority_queue<int>pq(arr, arr+n);
    vector<int>ans(k); int i = 0;
    while(!pq.empty() && k--){
        ans[i++] = pq.top();
        pq.pop();
    }
    return ans;
}