class Solution {
public:
    int longestNonOverlapping(vector<vector<int>>& arr) {
        sort(arr.begin(), arr.end(), [](vector<int>& v1, vector<int>&v2){return v1[1]<v2[1];});
        int endTime = arr[0][1], length = 1;
        for(int i = 0; i < arr.size(); i++){
            if(arr[i][0]>=endTime){
                endTime = arr[i][1];
                length++;
            }
        }
        return length;
    }
};