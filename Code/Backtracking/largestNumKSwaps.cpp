class Solution
{
    public:
    int n;
    string ans, str;
    
    void util(int k, int i = 0){
        if(k==0 || i==n) return;
        util(k, i+1);
        char ch = *max_element(str.c_str()+i+1, str.c_str()+n);
        if(ch==str[i]) return;
        for(int j = i+1; j < n; j++){
            if(str[j]==ch){
                swap(str[i], str[j]);
                ans = max(ans, str);
                util(k-1, i+1);
                swap(str[i], str[j]);
            }   
        }
    }
    
    string findMaximumNum(string str, int k) {
        this->n = str.length();
        this->str = str;
        this->ans = str;
        util(k);
        return ans;
    }
};