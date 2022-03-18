class Solution
{
    public:
    //Function to count number of ways to reach the nth stair.
    int countWays(int n) {
        long long M = 1000000007;
        vector<int>arr(n+1, 0);
        arr[0] = 1; arr[1] = 1;
        for(int i = 2; i <= n; i++){
            arr[i] = (arr[i]+arr[i-1]+arr[i-2])%M;
        }
        return arr[n];
    }
};

/*

Reaching a sum
Order Matter -> denominations inner loop (can reuse denos as long as order is different)
Order does not matter -> denomination outer loop (avoid reusing denos)

*/
