vector <int> calculateSpan(int price[], int n) {
    stack<pair<int , int>>s; 
     vector<int>ans(n);
     for(int i = 0; i < n; i++){
        while(!s.empty() && s.top().first <= price[i])
         s.pop();
         if(s.empty()){
             s.push({ price[i], i });
             ans[i] = i+1;
             continue;
         }
        ans[i] = i-s.top().second;
        s.push({ price[i], i });
     }
     return ans;
 }