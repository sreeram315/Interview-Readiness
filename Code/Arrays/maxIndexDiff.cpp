
int maxIndexDiff(int arr[], int n) {
    int l[n], r[n];
    l[0] = arr[0];
    for(int i = 1; i < n; i++)
        l[i] = min(arr[i], l[i-1]);
    r[n-1] = arr[n-1];
    for(int i = n-2; i >= 0; i--)
        r[i] = max(arr[i], r[i+1]);
    int i = 0, j = 0, ans = -1;
    while(i<n && j<n){
        if(l[i] <= r[j]){
            ans = max(ans, j-i);
            j++;
        }else{
            i++;
        }
    }
    return ans;
} 
    
int maxIndexDiff2(int arr[], int n) 
{ 
    int l = arr[0], r = arr[0];
    int ans = INT_MIN;
    for(int i = 1; i < n; i++){
        if(arr[i] < l) l = arr[i];
        if(arr[i] > r) r = arr[i];
        ans = max(ans, r-l);
    }
    return ans;
}