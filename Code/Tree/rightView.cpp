

void do_it(Node *p, vector<int>&ans, int h = 0){
    if(!p) return;
    if(ans[h]==-1) ans[h] = p->data;
    do_it(p->right, ans, h+1);
    do_it(p->left, ans, h+1);
}


vector<int> rightView(Node *root) {
    int h = get_h(root);
    vector<int>ans(h+1, -1);
    do_it(root, ans);
    return ans;
}