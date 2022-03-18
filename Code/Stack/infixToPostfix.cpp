string infixToPostfix(string s) {
    stack<int>st;
    unordered_map<char, int>mp;
    mp['^'] = 3;
    mp['*'] = 2;
    mp['/'] = 2;
    mp['+'] = 1;
    mp['-'] = 1;
    string ans = "";
    
    for(char ch: s){
        if(isalpha(ch)){
            ans += ch;
        }
        else{
            if(st.empty() || ch=='(')
                st.push(ch);
            else if(ch == ')'){
                while(st.top() != '('){
                    ans += st.top();
                    st.pop();
                }
                st.pop();
            }
            else{
                if(mp[ch] > mp[st.top()]){
                    st.push(ch);
                } else{
                    while(!st.empty() && (mp[st.top()] >= mp[ch])){
                        ans += st.top();
                        st.pop();
                    }
                    st.push(ch);
                }
            }
        }
    }
    while(!st.empty()){
        ans += st.top();
        st.pop();
    }
    return ans;
}