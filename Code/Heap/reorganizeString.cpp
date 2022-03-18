class Solution {
public:
    
    struct comp{
         bool operator()(pair<char, int>a, pair<char, int>b){
            return a.second<b.second;
        }
    };
    
    string reorganizeString(string s) {
        unordered_map<char, int>mp;
        for(char ch: s) mp[ch]++;
        priority_queue<pair<char, int>, vector<pair<char, int>>, comp>pq;
        for(auto p: mp) pq.push(p);
        pair<char, int>a, b;
        string ans = "";
        while(pq.size()>1){
            a = pq.top(); pq.pop();
            b = pq.top(); pq.pop();
            ans += a.first; ans += b.first;
            if(a.second>1) pq.push({a.first, a.second-1});
            if(b.second>1) pq.push({b.first, b.second-1});
        }
        if(pq.size()==0) return ans;
        a = pq.top(); pq.pop();
        if(a.second!=1) return "";
        return ans+a.first;
    }
};

// https://leetcode.com/problems/reorganize-string/