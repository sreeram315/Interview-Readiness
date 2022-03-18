

int maxOccured(int L[], int R[], int n, int maxx){
    vector<int>arr(maxx+2);
    for(int i = 0; i < n; i++){
        arr[L[i]]++; arr[R[i]+1]--;
    }
    int ind = 0, ans = arr[0];
    for(int i = 1; i <= maxx; i++){
        arr[i] += arr[i-1];
        if(arr[i] > ans){
            ans = arr[i];
            ind = i;
        }
    }
    return ind;
}