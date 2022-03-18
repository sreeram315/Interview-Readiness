vector<long long> nextLargerElement(vector<long long> arr, int n){
    vector<long long> ans(n);
    ans[n-1] = -1;
    stack<long long> S; S.push(arr[n-1]);
    for(int i = n-2; i >= 0; i--){
        while(!S.empty() && S.top() < arr[i])
            S.pop();
        if(S.empty()){
            ans[i] = -1;
            S.push(arr[i]);
            continue;
        }
        ans[i] = S.top();
        S.push(arr[i]);
    }
    return ans;
}