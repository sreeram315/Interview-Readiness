// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};
        queue<TreeNode*>q;
        q.push(root);
        vector<vector<int>>ans;
        bool rev = false;
        while(!q.empty()){
            int size = q.size();
            vector<int>temp(size); int ind = 0;
            while(size--){
                TreeNode* p = q.front(); q.pop();
                temp[ind++] = p->val;
                if(p->left) q.push(p->left);
                if(p->right) q.push(p->right);
            }
            if(rev)
                reverse(temp.begin(), temp.end());
            rev = !rev;
            ans.push_back(temp);
        }
        return ans;
    }
};