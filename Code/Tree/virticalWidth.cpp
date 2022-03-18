int L, R;
void util(Node *p, int l = 0){
    if(!p) return;
    util(p->left, l-1);
    util(p->right, l+1);
    L = min(L, l);
    R = max(R, l);
}


int verticalWidth(Node* root) {
    if(!root) return 0;
    L = 0; R = 0;
    util(root);
    return (R-L+1);
}