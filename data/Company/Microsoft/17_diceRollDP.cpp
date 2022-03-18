// https://www.geeksforgeeks.org/dice-throw-dp-30/

class Solution {
public:
    long M = 1000000007;
    int numRollsToTarget(int d, int f, int target) {
        vector<vector<int>> arr(d+1, vector<int>(target+1));
        for(int i = 0; i <= d; i++){
            for(int j = 0; j <= target; j++){
                if(i==0)
                    arr[i][j] = (j==0);
                else{
                    for(int face = 1; (face <= f) && (j-face >= 0); face++)
                        arr[i][j] = (arr[i][j] + arr[i-1][j-face])%M;
                }
            }
        }
        return arr[d][target];
    }
};
