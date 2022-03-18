vector<int> verticalOrder(Node *root) {
    map<int, vector<int>>mp;
    queue<pair<Node*, int>>q;
    q.push({root, 0});
    pair<Node*, int> x;
    int val, level, c = 0, ind = 0;
    Node *p;
    while(!q.empty()){
        x = q.front(); q.pop();
        p = x.first; level = x.second;
        mp[level].push_back(p->data); c++;
        if(p->left) q.push({p->left, level-1});
        if(p->right) q.push({p->right, level+1});
    }
    vector<int>ans(c);
    for(const pair<int, vector<int>> &x: mp){
        for(const int &val: x.second)
            ans[ind++] = val;
    }
    return ans;
}