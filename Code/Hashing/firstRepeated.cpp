int firstRepeated(int arr[], int n) {
    unordered_set<int>ms;
    int ans = -1;
    for(int i = n-1; i >= 0; i--){
        if(ms.count(arr[i]))
            ans = i+1;
        ms.insert(arr[i]);
    }
    return ans;
}