class Solution
{
    public:
    long long maximumSum(int arr[], int n) {
       int meh = 0, ans = INT_MIN;
       for(int i = 0; i < n; i++){
           meh += arr[i];
           ans = max(ans, meh);
           meh = max(meh, 0);
       }
       return ans;
    }
};