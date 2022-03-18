class Solution
{
    public:
    //Function to find length of shortest common supersequence of two strings.
    int shortestCommonSupersequence(char* X, char* Y, int m, int n) {
        vector<vector<int>>arr(m+1, vector<int>(n+1));
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                if(X[i-1] == Y[j-1])
                    arr[i][j] = arr[i-1][j-1]+1;
                else
                    arr[i][j] = max(arr[i-1][j], arr[i][j-1]);
            }
        }
        return m+n-arr[m][n];
    }
};