bool detectLoop(Node* head) {
    if(!head || !head->next) return false;
    Node *s = head, *f = head;
    while(s && f && f->next){
        s = s->next;
        f = f->next->next;
        if(s==f) break;
    }
    return s==f;
}