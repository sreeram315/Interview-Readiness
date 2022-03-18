int getMaxWidth(Node* h)  {
    int ans = 0;
    if(!h) return 0;
    queue<Node *>q;
    q.push(h);
    int size;
    Node *p;
    while(!q.empty()){
        size = q.size();
        ans = max(ans, size);
        while(size--){
            p = q.front(); q.pop();
            if(p->left)
                q.push(p->left);
            if(p->right)
                q.push(p->right);
        }
    }
    return ans;
}