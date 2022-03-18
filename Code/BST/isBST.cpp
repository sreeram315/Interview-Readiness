bool util(Node *root, int min = INT_MIN, int max = INT_MAX){
    return (!root) ? true :
            ( (root->data > min) && (root->data < max) &&
                util(root->left, min, root->data) && util(root->right, root->data, max)
            );
}


bool isBST(Node* root) {
    return util(root);
}