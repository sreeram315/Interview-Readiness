/*
https://leetcode.com/problems/insert-interval/
*/
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int i = 0, n = intervals.size(), newStart = newInterval[0], newEnd = newInterval[1];
        vector<vector<int>>ans;
        while(i<n && intervals[i][1]<newStart)      // before new interva;
            ans.push_back(intervals[i++]);
        while(i<n && intervals[i][0]<=newEnd){              // intervals merging because of new addition
            newStart = min(newStart, intervals[i][0]);
            newEnd   = max(newEnd, intervals[i++][1]);
        }
        ans.push_back({newStart, newEnd});
        while(i<n)                              // after new interval 
            ans.push_back(intervals[i++]);
        return ans;
    }
};