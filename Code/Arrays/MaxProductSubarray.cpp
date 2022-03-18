// https://leetcode.com/problems/maximum-product-subarray/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // prefix product and suffix product. reset at arr[i]=0
    int maxProduct(vector<int> nums) {
        int pp = 1, sp = 1, n = nums.size(), ans = INT_MIN;
        for(int i = 0; i < n; i++){
            pp = (pp!=0 ? pp : 1)*nums[i];
            sp = (sp!=0 ? sp : 1)*nums[n-i-1];
            ans = max(ans, max(pp, sp));
        }
        return ans;
    }
};

int main(){
    cout << Solution().maxProduct({1,2,-3,4}) << endl;
}

//

int maxProduct(vector<int>& nums) {
    int mx = nums[0], mn = nums[0], n = nums.size(), ans = nums[0];
    for(int i = 1; i < n; i++){
        mx = mx!=0 ? mx : 1;
        mn = mn!=0 ? mn : 1;
        int nextMax = max(max(mx*nums[i], mn*nums[i]), nums[i]),
            nextMin = min(min(mx*nums[i], mn*nums[i]), nums[i]);
        ans = max(nextMax, ans);
        mx = nextMax; mn = nextMin;
    }
    return ans;
}