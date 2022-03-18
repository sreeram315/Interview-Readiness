class Solution
{
    public:
    //Function to return maximum sum subarray by removing at most one element.
    void calc(vector<int>& f, vector<int>& b, int *arr, int n){
        int meh = 0, msf = INT_MIN;
        for(int i = 0; i < n; i++){
            meh += arr[i];
            f[i] = meh;
            meh = max(meh, 0);
        }
        meh = 0; msf = INT_MIN;
        for(int i = n-1; i >= 0; i--){
            meh += arr[i];
            b[i] = meh;
            meh = max(meh, 0);
        }
    }
    //Function to return maximum sum subarray by removing at most one element.
    int maxSumSubarray(int arr[], int n)
    {
        vector<int>f(n), b(n);
        calc(f, b, arr, n);
        int ans = max(0, arr[0]) + max(b[1], 0);
        for(int i = 1; i < n-1; i++){
            int val = max(f[i-1], 0)+max(arr[i], 0)+max(b[i+1],0);
            ans = max(ans, val);
        }
        ans = max(ans, max(arr[n-1], 0)+max(f[n-2], 0));
        return (ans!=0) ? ans : *max_element(arr, arr+n);
    }
};