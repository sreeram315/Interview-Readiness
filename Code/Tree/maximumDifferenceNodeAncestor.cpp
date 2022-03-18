int ans, MAX = 100005;
int util(Node *p){
     if(!p) return MAX;
     int l = min(util(p->left), util(p->right));
     ans = max(ans, p->data - l);
     return min(l, p->data);
 }


int maxDiff(Node* root)
{
    ans = INT_MIN;
    util(root);
    return ans;
}