// https://leetcode.com/problems/boundary-of-binary-tree/submissions/

class Solution {
public:
    
    vector<int> getLeftBoundary(TreeNode *root){
        vector<int> leftBoundary;
        root = root->left;
        while(root){
            if(!root->left && !root->right)
                return leftBoundary;
            leftBoundary.push_back(root->val);
            root = (root->left) ? (root->left) : (root->right);
        }
        return leftBoundary;
    }
    vector<int> getRightBoundary(TreeNode *root){
        vector<int> rightBoundary;
        root = root->right;
        while(root){
            if(!root->left && !root->right)
                return rightBoundary;
            rightBoundary.push_back(root->val);
            root = (root->right) ? (root->right) : (root->left);
        }
        return rightBoundary;
    }
    vector<int> getBottomBoundary(TreeNode *p){
        stack<TreeNode*>st;
        vector<int>bottomBoundary;
        while(p || !st.empty()){
            while(p){
                st.push(p);
                p = p->left;
            }
            p = st.top(); st.pop();
            if(!p->left && !p->right)
                bottomBoundary.push_back(p->val);
            p = p->right;
        }
        return bottomBoundary;
    }
    
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        if(!root) return {};
        if(!root->left && !root->right) return {root->val};
        vector<int>leftBoundary = getLeftBoundary(root),
                   rightBoundary = getRightBoundary(root),
                   bottomBoundary = getBottomBoundary(root);
        reverse(rightBoundary.begin(), rightBoundary.end());
        vector<int>boundaryTraversal;
        boundaryTraversal.push_back(root->val);
        boundaryTraversal.insert(boundaryTraversal.begin()+1, rightBoundary.begin(), rightBoundary.end());
        boundaryTraversal.insert(boundaryTraversal.begin()+1, bottomBoundary.begin(), bottomBoundary.end());
        boundaryTraversal.insert(boundaryTraversal.begin()+1, leftBoundary.begin(), leftBoundary.end());
        return boundaryTraversal;
    }
};









