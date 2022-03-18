class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        TreeNode *succ = NULL;
        while(root){
            if(root->val <= p->val)
                root = root->right;
            else{
                succ = root;
                root = root->left;
            }
        }
        return succ;
    }
};