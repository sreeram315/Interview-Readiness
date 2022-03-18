int searchInSorted(int arr[], int N, int K) {     
    int l = 0, r = N-1;
    while(l <= r){
        int mid = (l+r)/2;
        if(arr[mid] == K) return 1;
        if(arr[mid] > K)
              r = mid-1;
        else
              l = mid+1;
    }
    return -1;
}

