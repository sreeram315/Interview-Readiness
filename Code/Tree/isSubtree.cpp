// https://leetcode.com/problems/subtree-of-another-tree/submissions/


class Solution {
public:
    void in(TreeNode *p, string &s){
        if(!p) {s+='$';return;}
        in(p->left, s);
        s += (p->val + '0');
        in(p->right, s);
    }    
    
    void pre(TreeNode *p, string &s){
        if(!p) {s+='$';return;}
        s += (p->val + '0');
        pre(p->left, s);
        pre(p->right, s);
    }
    //Function to check if S is a subtree of tree T.
    bool isSubtree(TreeNode* T, TreeNode* S) 
    {
        string in1, in2;
        in(T, in1); in(S, in2);
        string p1, p2;
        pre(T, p1); pre(S, p2);
        return (in1.find(in2) != string::npos) &&
                (p1.find(p2) != string::npos);
    }
    
};