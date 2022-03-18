Node* sortedMerge(Node* head1, Node* head2)  
{  
    if(!head1) return head2;
    if(!head2) return head1;
    Node *t;
    Node *p = head1, *q = head2;
    if(p->data <= q->data){
        t = p; p = p->next;
    } else {
        t = q; q = q->next;
    }
    Node *ans = t;
    while(p && q){
        if(p->data <= q->data){
            t->next = p;
            t = t->next;
            p = p->next;
        }else{
            t->next = q;
            t = t->next;
            q = q->next;
        }
    }
    if(p) t->next = p;
    if(q) t->next = q;
    return ans;
} 