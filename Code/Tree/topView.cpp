vector<int> topView(Node *root)
{
    map<int, int>mp;
    queue<pair<Node*, int>>q;
    q.push({root, 0});
    pair<Node*, int> x;
    int val, level, c = 0, ind = 0;
    Node *p;
    while(!q.empty()){
        x = q.front(); q.pop();
        p = x.first; level = x.second;
        if(!mp.count(level)) mp[level] = p->data; 
        if(p->left) q.push({p->left, level-1});
        if(p->right) q.push({p->right, level+1});
    }
    vector<int>ans;
    for(const pair<int, int> &x: mp){
        ans.push_back(x.second);
    }
    return ans;
}