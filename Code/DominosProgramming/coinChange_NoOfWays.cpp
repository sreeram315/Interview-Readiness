class Solution
{
    public:
    long long numberOfWays(int coins[],int n,int val) {
        vector<int>arr(val+1, 0);
        arr[0] = 1;
        for(int i = 0; i < n; i++){
            int c = coins[i];
            for(int j = c; j <= val; j++)
                arr[j]+= arr[j-c];
        }
        return arr[val];
    }
};