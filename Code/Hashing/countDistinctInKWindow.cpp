vector <int> countDistinct (int A[], int n, int k) {
    unordered_map<int, int>mp;
    int d = 0;
    for(int i = 0; i < k; i++){
        int k = A[i];
        mp[k]++;
        if(mp[k]==1) d++;
    }
    vector<int>ans;
    ans.push_back(d);
    for(int i = k; i < n; i++){
        int a = A[i-k], b = A[i];
        mp[a]--;
        if(mp[a]==0) d--;
        mp[b]++;
        if(mp[b]==1) d++;
        ans.push_back(d);
    }
    return ans;
}