struct Node* reverseList(struct Node *head)
{
    Node *p = head->next, *q = head, *t = NULL;
    head->next = NULL;
    if(!p)
    	return q;
    while(p->next){
        t = p->next;
        p->next = q;
        q = p;
        p = t;

    }
    p->next = q;
    return p;
}