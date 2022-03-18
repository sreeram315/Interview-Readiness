class Solution {
public:
    int index = 0;
    unordered_map<int, int>mp;
    
    TreeNode* util(vector<int>& preorder, vector<int>& inorder, int l, int r){
        if(l>r) return NULL;
        int val = preorder[index++];
        int i = mp[val];
        TreeNode *node = new TreeNode(val, 
                                      util(preorder, inorder, l, i-1),
                                      util(preorder, inorder, i+1, r)
                                     );
        // if postOrder, remember to traverse right before left.
        return node;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        for(int i = 0; i < n; i++)
            mp[inorder[i]] = i;     // hash map makes searching O(1) in above function
        return util(preorder, inorder, 0, n-1);
    }
};









