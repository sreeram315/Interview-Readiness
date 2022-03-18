int findCeil(Node* root, int input) 
{ 
    if (root == NULL) 
        return -1; 
  
    int ans = INT_MAX;
    while(root){
        if(root->data == input)
            return input;
        if(root->data > input && root->data < ans)
            ans = root->data;
        if(root->data > input)
            root = root->left;
        else if(root->data < input)
            root = root->right;
    }
    if(ans == INT_MAX)
        return -1;
    return ans;
} 