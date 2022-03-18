

int util(Node *p, int &res){
    if(!p) return 0;
    int l = util(p->left, res),
        r = util(p->right, res);
    res = max(res, 1+l+r);
    return 1+max(l, r);
}

int diameter(Node* root) {
    int res = INT_MIN;
    util(root, res);
    return res;
}