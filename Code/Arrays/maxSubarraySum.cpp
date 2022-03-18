// https://leetcode.com/problems/maximum-subarray/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxEndingHere = 0, ans = INT_MIN;
        for(int x: nums){
            maxEndingHere += x;
            ans = max(maxEndingHere, ans);
            maxEndingHere = max(maxEndingHere, 0);
        }
        return ans;
    }
};