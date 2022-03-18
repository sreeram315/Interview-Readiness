int minNumber(int arr[], int l, int r) {
    if(arr[l] < arr[r])
        return arr[l];
    while(l<=r) {
        int mid = (l+r)/2;
        if(arr[l] < arr[r])
            return arr[l];
        if(mid>0 && (arr[mid]<arr[mid-1]))
            return arr[mid];
        if(arr[mid] >= arr[l])
            l = mid+1;
        else
            r = mid-1;
    }
    return -1;
}