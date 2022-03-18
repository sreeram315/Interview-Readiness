bool subArrayExists(int arr[], int n) {
    int csum = 0;
    unordered_set<int>ms;
    for(int i = 0; i < n; i++){
        csum += arr[i];
        if(csum==0) return true;
        if(ms.count(csum)) return true;
        ms.insert(csum);
    }
    return 0;
}