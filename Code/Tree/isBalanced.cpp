
bool ans;
int util(Node *root){
    if(!root) return 0;
    int lh = util(root->left),
        rh = util(root->right);
    if(abs(lh-rh)>1)
        ans = false;
    return 1+max(lh, rh);
}


bool isBalanced(Node *root) {
    if(!root) return true;
    ans = true;
    util(root);
    return ans;
}