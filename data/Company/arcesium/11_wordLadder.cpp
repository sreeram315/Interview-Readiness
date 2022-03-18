/*
A transformation sequence from word beginWord to word endWord 
using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:
    - Every adjacent pair of words differs by a single letter.
    - Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.

sk == endWord
Given two words, beginWord and endWord, and a dictionary wordList, return the number of words 
in the shortest transformation sequence from beginWord to endWord, 
or 0 if no such sequence exists.

https://leetcode.com/problems/word-ladder/
*/

class Solution {
public:
    bool stringsDifferByOne(string& a, string& b){
        int ans = 0;
        for(int i = 0; i < a.size(); i++){
            ans += (a[i]!=b[i] ? 1 : 0);
            if(ans > 1) break;
        }
        return (ans==1);
    }
    
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size();
        vector<bool>vis(n, false);
        queue<pair<string, int>>q;
        q.push({beginWord, 1});
        
        while(!q.empty()){
            pair<string, int>p = q.front(); q.pop();
            for(int i = 0; i < n; i++){
                if(vis[i] || !stringsDifferByOne(p.first, wordList[i])) continue;
                if(wordList[i] == endWord)
                    return p.second+1;
                q.push({wordList[i], p.second+1});
                vis[i] = true;
            }
        }
        return 0;
        
    }
};