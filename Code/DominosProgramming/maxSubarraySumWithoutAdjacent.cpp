class Solution
{
    public:
        
    long long maximumSum(int nums[], int n)
    {
       vector<int>arr(n, INT_MIN);
       arr[0] = nums[0];
       arr[1] = max(nums[0], nums[1]);
       for(int i = 2; i < n; i++)
            arr[i] = max(nums[i]+max(arr[i-2], 0), arr[i-1]);
       return arr[n-1];
    }
};