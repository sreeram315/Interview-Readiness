
// BINARY SEARCH SOLUTION
class Solution
{
  public:
    
    bool possible(int *arr, int n, long long m, int k){
        int i = 0;
        while(i<n && k>0){
            int s = 0;
            while(i<n && s+arr[i] <= m) s += arr[i++];
            k--;
        }
        return (i==n);
    }
  
    long long minTime(int arr[], int n, int k) {
	    long long l = *max_element(arr, arr+n), r = accumulate(arr, arr+n, 0LL), mid, ans = INT_MAX;
        while(l<=r){
            mid = l + (r - l) / 2;
            if(possible(arr, n, mid, k)){
                r = mid-1;
                ans = min(ans, mid);
            }
            else{
                l = mid+1;
            }
        }
        return ans;
    }
};