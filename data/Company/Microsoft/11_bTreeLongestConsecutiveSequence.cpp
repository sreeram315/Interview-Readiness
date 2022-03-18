// https://leetcode.com/problems/binary-tree-longest-consecutive-sequence/

class Solution {
public:
    int ans = 0;
    
    void util(TreeNode *p, int target, int curr = 0){
        if(!p) return;
        curr = (p->val == target) ? (curr+1) : 1;
        ans = max(ans, curr);
        util(p->left, p->val+1, curr);
        util(p->right, p->val+1, curr);
    }
    
    int longestConsecutive(TreeNode* root) {
        util(root, root->val);
        return ans;
    }
};