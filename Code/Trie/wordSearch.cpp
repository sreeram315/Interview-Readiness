// https://leetcode.com/problems/word-search-ii/
class Solution {
    struct Node{
        bool isEnd;
        vector<Node*>children;
        Node(){
            isEnd = false;
            children.resize(26, NULL);
        }
    };
    
    Node *head;
    int m, n;
    string str;
    vector<vector<bool>>re;
    vector<pair<int, int>> paths = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    unordered_set<string>ms;
    vector<string>ans;
    
    void insert(string& word){
        Node *p = head;
        int len = word.length(), index = 0;
        while(index != len){
            char ch = word[index++]-'a';
            if(!p->children[ch])
                p->children[ch] = new Node();
            p = p->children[ch];
        }
        p->isEnd = true;
    }
    
    inline bool is_valid(int x, int y){
        return x>=0 && y>=0 && x<m && y<n;
    }
    
    void util(vector<vector<char>>& arr, int i, int j, Node *p){
        if(p->isEnd){
            ans.push_back(str);
            p->isEnd = false;
        }
        re[i][j] = true;
        for(pair<int, int>& path: paths){
            int x = i+path.first, y = j+path.second;
            if(!is_valid(x, y)) continue;
            char ch = arr[x][y]-'a';
            if(!re[x][y] && p->children[ch]){
                str.push_back(arr[x][y]);
                util(arr, x, y, p->children[ch]);
                str.pop_back();
            }
        }
        re[i][j] = false;
        return ;
    }
    
public:
    
    
    vector<string> findWords(vector<vector<char>>& arr, vector<string>& words) {
        m = arr.size(); n = arr[0].size();
        re.resize(m, vector<bool>(n, false));
        head = new Node();
        for(string word: words) insert(word);
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                char ch = arr[i][j]-'a';
                if(head->children[ch]){
                    str.push_back(arr[i][j]);
                    util(arr, i, j, head->children[ch]);
                    str.pop_back();
                }
            }
        }
        return ans;   
    }
};