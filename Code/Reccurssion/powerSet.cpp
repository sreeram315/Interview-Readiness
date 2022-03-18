

vector<string>ans;
string st;

void util(string s, int i = 0){
    if(i == s.length()) {
        ans.push_back(st);
        return;
    }
    st += s[i];
    util(s, i+1);
    st.pop_back();
    
    util(s, i+1);
}

vector <string> powerSet(string s) {
    ans.clear(); 
    st = "";
    util(s);
    return ans;
}
