// https://leetcode.com/problems/maximum-sum-circular-subarray/submissions/
class Solution {
public:
    int kadane(vector<int>& arr){
        int msf = arr[0], mx = arr[0];
        for(int i = 1; i < arr.size(); i++){
            msf = max(msf+arr[i], arr[i]);
            mx = max(msf, mx);
        }
        return mx;
    }
    
    int maxSubarraySumCircular(vector<int>& arr) {
        int num = arr.size();
        int notFormingCircle = kadane(arr);
        int totalSum = accumulate(arr.begin(), arr.end(), 0);
        if(notFormingCircle <= 0) return notFormingCircle;
        for(int i = 0; i < num; i++)
            arr[i] *= -1;
        int mn = -1*kadane(arr);
        int formingCircle = totalSum - mn;
        return max(formingCircle, notFormingCircle);   
    }
};