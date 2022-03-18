class Solution {
public:
    // seperate arrays, to sort, single travelsal
    int minMeetingRooms(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<int>startTime(n), endTime(n);
        for(int i = 0; i < n; i++){
            startTime[i] = intervals[i][0];
            endTime[i]   = intervals[i][1];
        }
        sort(startTime.begin(), startTime.end());
        sort(endTime.begin(), endTime.end());
        int count = 0, i = 0, j = 0, ans = INT_MIN;
        while(i<n){
            if(startTime[i]<endTime[j]){
                count++;
                ans = max(ans, count);
                i++;
            }else{
                count--;
                j++;
            }
        }
        return ans;
    }
};

// simulating using a priority queue
class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        int ans = 0;
        sort(intervals.begin(), intervals.end());
        priority_queue<int, vector<int>, greater<int>>pq;
        for(const vector<int>&m: intervals){
            if(!pq.empty() && pq.top()<=m[0])
                pq.pop();
            pq.push(m[1]);
            ans = max(ans, (int)pq.size());
        }
        return ans;
    }
};
