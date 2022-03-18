    int ans;
    int util(Node *p){
        if(!p) return 0;
        int l = util(p->left),
            r = util(p->right);
        ans = max(ans, p->data+l+r);
        return max(max(l, r)+p->data, 0);
    }
    
    int findMaxSum(Node* root)
    {
        ans = INT_MIN;
        util(root);
        return ans;
    }