class Solution {
public:
    int minDistance(string w1, string w2) {
        int n1 = w1.length(), n2 = w2.length();
        vector<vector<int>>arr(n1+1, vector<int>(n2+1));
        for(int i = 0; i <= n1; i++){
            for(int j = 0; j <= n2; j++){
                if(i==0 || j==0)
                    arr[i][j] = max(i, j);
                else if (w1[i-1] == w2[j-1])
                    arr[i][j] = arr[i-1][j-1];
                else
                    arr[i][j] = 1+min(arr[i-1][j-1], min(arr[i-1][j], arr[i][j-1]));
            }
        }
        return arr[n1][n2];
    }
};