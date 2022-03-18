// https://leetcode.com/problems/binary-tree-preorder-traversal/
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>ans;
        stack<TreeNode *>st;
        TreeNode *p = root;
        while(p || !st.empty()){
            while(p){
                ans.push_back(p->val);
                if(p->right)st.push(p->right);
                p = p->left;
            }
            if(!st.empty()){
                p = st.top();
                st.pop();
            }
        }
        return ans;
    }
};