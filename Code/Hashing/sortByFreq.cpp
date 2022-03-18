

vector<int> sortByFreq(int arr[],int n) {
    map<int, int>mp;
    for(int i = 0; i < n; i++)
        mp[arr[i]]++;
    vector<vector<int>>freq(n+1);
    for(auto x: mp)
        freq[x.second].push_back(x.first);
    vector<int>ans(n);
    int ind = 0; int c = 0;
    for(int i = freq.size()-1; i >= 0; i--){
        for(auto x: freq[i]){
            for(int j = 0; j < i; j++){
                ans[ind++] = x;
                c++;
                if(c==n)
                    return ans;
            }
        }
    }
}