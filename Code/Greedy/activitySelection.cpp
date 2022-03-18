/*
N meetings in one room
one person N meetings
*/
class Solution
{
    public:
    int activitySelection(vector<int> start, vector<int> end, int n)
    {
        vector<pair<int, int>>arr(n);
        for(int i = 0; i < n; i++)
            arr[i] = {start[i], end[i]};
        // sort by end time
        sort(arr.begin(), arr.end(), [](pair<int, int>a, pair<int, int>b){return a.second==b.second ? a.first<b.first :  a.second<b.second;});
        int t = 0, ans = 0;
        for(pair<int, int> m: arr){
            if(m.first <= t) continue;
            t = m.second;
            ans++;
        }
        return ans;
    }
};