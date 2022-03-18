// https://leetcode.com/problems/minimum-number-of-taps-to-open-to-water-a-garden/

class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        int size = ranges.size();
        vector<int>maxRanges(size);
        for(int i = 0; i < size; i++){
            int start = max(i-ranges[i], 0), end = min(i+ranges[i], n);
            maxRanges[start] = max(maxRanges[start], end);
        }
        int i = 0, maxRechable = maxRanges[0], count = 1, currMax = maxRechable;
        for(; i < size; i++){
            currMax = max(currMax, maxRanges[i]);
            if(maxRechable == n)
                return count;
            if(maxRechable == i){
                maxRechable = currMax; 
                count++;
            }
        }
        return -1;
    }
};