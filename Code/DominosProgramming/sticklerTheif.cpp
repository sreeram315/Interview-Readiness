class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    int FindMaxSum(int arr[], int n) {
        vector<int>ans(n, 0);
        ans[0] = arr[0];
        ans[1] = max(arr[0], arr[1]);
        for(int i = 2; i < n; i++)
            ans[i] = max(ans[i-2]+arr[i], ans[i-1]);
        return ans[n-1];
    }
};
// https://practice.geeksforgeeks.org/problems/stickler-theif-1587115621/1/?track=P100-DP&batchId=238