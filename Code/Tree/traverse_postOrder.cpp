// https://leetcode.com/problems/binary-tree-postorder-traversal/
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>ans;
        stack<TreeNode*>st;
        while(!st.empty() || root){
            while(root){
                ans.push_back(root->val);
                st.push(root);
                root = root->right;
            }
            root = st.top(); st.pop();
            root = root->left;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};