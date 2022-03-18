Node *head = NULL, *prev = NULL;

void util(Node *p){
    if(!p) return;
    util(p->left);
    if(!prev){
        head = p;
    }else{
        prev->right = p;
        p->left = prev;
    }
    prev = p;
    util(p->right);
}


Node *bTreeToCList(Node *root)
{
    head = NULL; prev = NULL;
    util(root);
    head->left = prev;
    prev->right = head;
    return head;
}