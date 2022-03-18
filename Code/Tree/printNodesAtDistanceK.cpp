// https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/submissions/

class Solution {
public:
    vector<int>ans;
    
    void distanceKBelow(TreeNode *p, int k){
        if(!p || k<0) return;
        if(k == 0){
            ans.push_back(p->val);
            return;
        }
        distanceKBelow(p->left, k-1);
        distanceKBelow(p->right, k-1);
    }
    
    int search(TreeNode* p, TreeNode* target, int K){
        if(!p) return -1;
        if(p == target){
            distanceKBelow(p, K);
            return 1;
        }
        int x = search(p->left, target, K),
            y = search(p->right, target, K);
        if(x != -1){
            if(K == x) ans.push_back(p->val);
            distanceKBelow(p->right, K-x-1);
            return x+1;
        }
        if(y != -1){
            if(K == y) ans.push_back(p->val);
            distanceKBelow(p->left, K-y-1);
            return y+1;
        }
        return -1;
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        search(root, target, K);
        return ans;
    }
};