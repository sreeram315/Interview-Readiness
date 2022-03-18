class Solution
{
    public:
    //Function to find the length of longest common subsequence in two strings.
    int lcs(int x, int y, string s1, string s2)
    {
        int n = s1.length(), m = s2.length();
        vector<vector<int>>arr(n+1, vector<int>(m+1, 0));
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++)
                arr[i][j] = (s1[i-1]==s2[j-1]) ? 
                                    1+arr[i-1][j-1] : 
                                    max(arr[i-1][j], arr[i][j-1]);
        return arr[n][m];
    }
};