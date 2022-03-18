// https://leetcode.com/problems/sort-colors/

class Solution {
public:
    void sortColors(vector<int>& arr) {
        int n = arr.size(), l = -1, r = n, i = 0;
        while(i<r){
            if(arr[i] == 0)
                swap(arr[++l], arr[i++]);
            else if(arr[i]==2)
                swap(arr[--r], arr[i]);
            else if(arr[i]==1)
                i++;
        }
    }
};