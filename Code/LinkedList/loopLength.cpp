int countNodesinLoop(struct Node *h)
{
    if(!h || !h->next) return 0;
    Node *p = h, *q = h;
    while(p && q && p->next){
        p = p->next->next;
        q = q->next;
        if(p==q){
            Node *t = p;
            int c = 0;
            do{
                t = t->next; c++;
            }while(t!=p);
            return c;
        }
    }
    return 0;
}