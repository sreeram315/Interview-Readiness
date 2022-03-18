void convert(Node *h, TreeNode *&root) {
    root = new TreeNode(h->data);
    h = h->next;
    queue<TreeNode*>q;
    q.push(root);
    while(h){
        TreeNode *p = q.front();
        q.pop();
        p->left = new TreeNode(h->data);
        h = h->next;
        if(!h) break;
        q.push(p->left);
        p->right = new TreeNode(h->data);
        h = h->next;
        q.push(p->right);
    }
}