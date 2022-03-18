// https://leetcode.com/problems/trapping-rain-water/


class Solution {
public:
    int trap(vector<int>& arr) {
        int n = arr.size();
        int l = 0, r = n-1, lm = 0, rm = 0, ans = 0;
        while(l <= r){
            if (lm<=rm){
                ans += max(lm-arr[l++], 0);
                lm = max(lm, arr[l-1]);
            }else{
                ans += max(rm-arr[r--], 0);
                rm = max(rm, arr[r+1]);
            }
        }
        return ans;
    }
};

