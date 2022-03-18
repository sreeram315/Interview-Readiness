class Solution
{
    public:
    int nCrModp(int N, int R) { 
        vector<vector<int>> arr(N+1, vector<int>(R+1));
        for(int n = 0; n <= N; n++)
            for(int r = 0; r <= R; r++)
                arr[n][r] = (n==r) ? 1 :
                            ((n<r) ? 0 : (arr[n-1][r-1]+arr[n-1][r])%1000000007);
        return arr[N][R];
    } 
};

/*

nCr = (n-1)C(r-1) + (n-1)C(r);
    = 0 (if n < c)
    = 1 (if n = c)

*/