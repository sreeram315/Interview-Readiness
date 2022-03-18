// https://www.geeksforgeeks.org/maximum-sum-path-across-two-arrays/
// https://leetcode.com/problems/get-the-maximum-score/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size(), i = 0, j = 0;
        long sum1 = 0, sum2 = 0, ans = 0, M = 1000000007;
        while(i<n1 && j<n2){
            if(nums1[i] < nums2[j])
                sum1 += nums1[i++];
            else if(nums1[i] > nums2[j])
                sum2 += nums2[j++];
            else {
                ans = (ans+max(sum1, sum2)+nums1[i])%M;
                sum1 = sum2 = 0;
                i++; j++;
            }
        }
        while(i<n1)
            sum1 += nums1[i++];
        while(j<n2)
            sum2 += nums2[j++];
        return (ans+max(sum1, sum2))%M;
    }
};

int main(){
	cout << Solution().maxSum(arr1, arr2);
}





