class Solution {
public:
    
    bool getPath(TreeNode *root, TreeNode *target, vector<TreeNode*>& path){
        if(!root) return false;
        if(root == target || getPath(root->left, target, path)
                          || getPath(root->right, target, path)){
            path.push_back(root);
            return true;
        }
        return false;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*>path1, path2;
        getPath(root, p, path1); getPath(root, q, path2);
        int n1 = path1.size(), n2 = path2.size(), i, j;
        for(i = n1-1, j = n2-1; i>=0 && j>=0; i--, j--)
            if(path1[i]!=path2[j]) break;
        return path1[i+1];
    }
};