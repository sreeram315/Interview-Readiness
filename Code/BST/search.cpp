bool search(Node* root, int x)
{
    while(root){
        if(root->data == x)
            return 1;
        if(root->data <= x)
            root = root->right;
        else
            root = root->left;
    }
    return 0;
}