

int getNthFromLast(Node *head, int n) {
    Node *s = head, *f = head;
    while( f->next && --n)
        f = f->next;
    if(n>1) return -1;
    while(f->next){
        f = f->next; s = s->next;
    }
    return s->data;
}