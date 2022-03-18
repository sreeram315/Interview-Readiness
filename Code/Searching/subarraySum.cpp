vector<int> subarraySum(int arr[], int n, int s){
    int l = 0, r = 0;
    int csum = 0;
    while(l<n && r<n){
        while(r<n && csum<s){
            csum += arr[r++];
        }
        while(l<=r && csum>s){
            csum -= arr[l++];
        }
        if(csum==s){
            return {l+1, r};
        }
    }
    return {-1};
}