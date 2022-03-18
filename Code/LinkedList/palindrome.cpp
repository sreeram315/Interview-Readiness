
Node* rev(Node *&h){
    Node *p = h, *q = NULL;
    while(p){
        Node *t = p->next;
        p->next = q;
        q = p;
        p = t;
    }
    return q;
}

bool isPalindrome(Node *head)
{
    Node *p = head, *q = head;
    while(p && p->next){
        p = p->next->next;
        q = q->next;
    }
    q = rev(q);
    p = head;
    while(q){
        if(p->data != q->data) return false;
        p = p->next;
        q = q->next;
    }
    return true;
}

