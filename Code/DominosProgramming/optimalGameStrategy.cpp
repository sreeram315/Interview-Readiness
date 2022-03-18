class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return true;
        long long x, y, s, e;
        vector<vector<int>>arr(n, vector<int>(n));
        for(int i = 0; i < n; i++)
            arr[i][i] = nums[i];
        for(int i = 0; i+1 < n; i++)
            arr[i][i+1] = max(nums[i], nums[i+1]);
        for(int gap = 2; gap < n; gap++){
            for(int i = 0; i+gap<n; i++){
                s = i; e = i+gap; 
                x = nums[s] + min(arr[s+1][e-1], arr[s+2][e]);
                y = nums[e] + min(arr[s+1][e-1], arr[s][e-2]);
                arr[i][i+gap] = max(x, y);
            }
        }
        int p1 = arr[0][n-1], p2 = accumulate(nums.begin(), nums.end(), 0)-arr[0][n-1];
        return (p1>=p2);
    }
};

// https://leetcode.com/problems/predict-the-winner/