


// single traversal
class Solution {
public:
    int largestHistogramArea(vector<int>& arr) {
        int n = arr.size(), ans = 0;
        stack<pair<int, int>>st;
        for(int i = 0; i < n; i++){
            while(!st.empty() && arr[st.top().first]>=arr[i]){
                pair<int, int>p = st.top(); st.pop();
                ans = max(ans, arr[p.first]*(i-p.second-1));
            }
            st.push({i, st.empty() ? -1 : st.top().first});
        }
        while(!st.empty()){
            pair<int, int>p = st.top(); st.pop();
            ans = max(ans, arr[p.first]*(n-p.second-1));
        }
        return ans;
    }
};

// 3 traversals
class Solution {
public:
    
    vector<int> getPrevDip(const vector<int>& arr){
        stack<int> st;
        int n = arr.size();
        vector<int> prevDip(n);
        for(int i = 0; i < n; i++){
            while(!st.empty() && arr[st.top()]>=arr[i]) 
                st.pop();
            prevDip[i] = (!st.empty()) ? st.top() : -1;
            st.push(i);
        }
        return prevDip;
    }
    
    vector<int> getNextDip(const vector<int>& arr){
        stack<int> st;
        int n = arr.size();
        vector<int> nextDip(n);
        for(int i = n-1; i >= 0; i--){
            while(!st.empty() && arr[st.top()]>=arr[i]) 
                st.pop();
            nextDip[i] = (!st.empty()) ? st.top() : n;
            st.push(i);
        }
        return nextDip;
    }
    
    int largestRectangleArea(vector<int>& arr) {
        vector<int> prevDip = getPrevDip(arr),
                    nextDip = getNextDip(arr);
        int ans = 0;
        for(int i = 0; i < arr.size(); i++)
            ans = max(ans, (nextDip[i]-prevDip[i]-1)*arr[i]);
        return ans;
    }
};

