class Solution
{
    public:
    long long minimumNumberOfCoins(int coins[], int n, int val) {
        vector<int>arr(val+1, INT_MAX);
        arr[0] = 0;
        for(int c = 0; c < n; c++){
            int coin = coins[c];
            for(int i = coin; i <= val; i++)
                arr[i] = min(arr[i], 
                            arr[i-coin]!=INT_MAX ? (1+arr[i-coin]): INT_MAX
                        );
        }
        return arr[val]==INT_MAX ? -1 : arr[val];
    }
};