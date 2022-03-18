
// self
 Node* connect(Node* root) {
        Node *p = root;
        if(!root) return root;
        while(p->left){
            Node *l = p->left, *r = p->right, *q = p;
            while(q){
                l->next = r;
                l = l->next;
                if(r!=q->right){
                    r->next = q->right;
                    l = l->next;
                }
                r = q->next ? q->next->left : NULL;
                q = q->next;
            }
            p = p->left;
        }
        return root;
    }


// online
void connect(TreeLinkNode *root) {
    if (root == NULL) return;
    TreeLinkNode *pre = root;
    TreeLinkNode *cur = NULL;
    while(pre->left) {
        cur = pre;
        while(cur) {
            cur->left->next = cur->right;
            if(cur->next) cur->right->next = cur->next->left;
            cur = cur->next;
        }
        pre = pre->left;
    }
}