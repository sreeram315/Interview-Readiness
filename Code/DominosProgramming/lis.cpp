class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[]) {
        int e = 0;
        vector<int>arr(n, INT_MAX);
        arr[0] = a[0];
        for(int i = 1; i < n; i++){
            if(a[i] < arr[0])
                arr[0] = a[i]; 
            else if(a[i] > arr[e])
                arr[++e] = a[i];
            else{
                auto itr = lower_bound(arr.begin(), arr.begin()+e+1, a[i]);
                *itr = a[i];
            }
        }
        return (e+1);
    }
};