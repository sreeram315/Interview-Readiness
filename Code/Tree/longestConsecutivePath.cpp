// https://leetcode.com/problems/binary-tree-longest-consecutive-sequence-ii/


class Solution {
public:
    int ans = 0;
    
    pair<int, int> util(TreeNode *p){
        if(!p) return {0, 0};
        pair<int, int> l = util(p->left), r = util(p->right);
        int inc = 1, dec = 1;
        if(p->left && abs(p->val - p->left->val)==1){
            if(p->val > p->left->val) inc = l.first+1;
            if(p->val < p->left->val) dec = l.second+1;
        }
        if(p->right && abs(p->val - p->right->val)==1){
            if(p->val > p->right->val) inc = max(inc, r.first+1);
            if(p->val < p->right->val) dec = max(dec, r.second+1);
        }
        ans = max(ans, max(inc, dec));
        if(p->left && p->right){
            if(abs(p->val - p->left->val)==1 && 
               abs(p->val - p->right->val)==1 && 
               p->left->val!=p->right->val){
                int a = (p->left->val < p->val) ? l.first : l.second;
                int b = (p->right->val < p->val) ? r.first : r.second;
                ans = max(ans, a+b+1);
            }
        }
        return {inc, dec};
    }
    
    int longestConsecutive(TreeNode* root) {
        util(root);
        return ans;
    }
};