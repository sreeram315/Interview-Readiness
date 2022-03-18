class Solution
{
    public:
    long long countWays(int n)
    {
        vector<int>arr(n+1, 0);
        arr[0] = 1;
        for(int i = 1; i <= n; i++)
            arr[i] += arr[i-1];
        for(int i = 2; i <= n; i++)
            arr[i] += arr[i-2];
        return arr[n];
    }
};