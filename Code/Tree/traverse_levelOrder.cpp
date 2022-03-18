// https://leetcode.com/problems/binary-tree-level-order-traversal/
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>> ans;
        vector<int>temp;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            temp.clear();
            int size = q.size();
            while(size--){
                TreeNode* p = q.front(); q.pop();
                if(p->left )
                    q.push(p->left);
                if(p->right)
                    q.push(p->right);
                temp.push_back(p->val);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};