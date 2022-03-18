vector<int> mergeKArrays(vector<vector<int>> arr, int k) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> >pq;
    vector<int>ans(k*k+1000); int ind = 0;
    for(int i = 0; i < k; i++)
        pq.push({arr[i][0], i});
    vector<int>index(k, 1);
    while(!pq.empty()){
        auto el = pq.top(); pq.pop();
        ans[ind++] = el.first;
        if(index[el.second] != k)
            pq.push({ arr[el.second][index[el.second]++], el.second });
    }
    return ans;
}