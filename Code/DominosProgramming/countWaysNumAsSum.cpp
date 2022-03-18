class Solution
{
    public:
    int countWays(int n)
    {
        long long M = 1000000007;
        vector<int>arr(n+1, 0);
        arr[0] = 1;
        for(int i = 1; i < n; i++)
            for(int j = i; j <= n; j++)
                arr[j] = (arr[j]+arr[j-i])%M;
        return arr[n];
    }
};