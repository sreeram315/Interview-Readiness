// IF width of level includes the absent nodes between first and last node of a level
class Solution {
public:
    vector<int>l, r;
    int get_height(TreeNode* p){
        if(!p) return 0;
        return 1+max(get_height(p->left), get_height(p->right));
    }
    
    void util(TreeNode* p, int ind = 0, int level = 0){
        if(!p) return;
        l[level] = min(l[level], ind);
        r[level] = max(r[level], ind);
        
        int x = ind-l[level];
        if(p->left)
            util(p->left, 2*x+1, level+1);
        if(p->right)
            util(p->right, 2*x+2, level+1);
    }
    
    int widthOfBinaryTree(TreeNode* root) {
        int h = get_height(root);
        l.resize(h, INT_MAX); r.resize(h, INT_MIN);
        util(root);
        int ans = 0;
        for(int i = 0; i < h; i++)
            ans = max(ans, r[i]-l[i]+1);
        return ans;
    }
};






