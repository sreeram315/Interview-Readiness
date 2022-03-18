// https://leetcode.com/problems/symmetric-tree/submissions/
class Solution {
public:
    
    bool util(TreeNode *p, TreeNode *q){
        if(!p && !q) return true;
        if(!p || !q) return false;
        return  (p->val==q->val) 
                && util(p->left, q->right) 
                && util(p->right, q->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        return util(root->left, root->right);
    }
};