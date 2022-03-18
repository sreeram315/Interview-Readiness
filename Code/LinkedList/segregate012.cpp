Node* segregate(Node *head) {
    Node *p = head;
    Node *s0 = NULL, *e0 = NULL, *s1 = NULL, *e1 = NULL, *s2 = NULL, *e2 = NULL;
    while(p){
        int d = p->data;
        switch(d){
            case 0:
                if(!s0){
                    s0 = p;
                    e0 = p;
                }else{
                    e0->next = p;
                    e0 = p;
                }
            break;
            case 1:
                if(!s1){
                    s1 = p;
                    e1 = p;
                }else{
                    e1->next = p;
                    e1 = p;
                }
            break;
            case 2:
                if(!s2){
                    s2 = p;
                    e2 = p;
                }else{
                    e2->next = p;
                    e2 = p;
                }
            break;
        }
        p = p->next;
    }

    e2 ? e2->next = NULL : e2 = NULL;
    e1 ? e1->next = s2 : s1 = s2;
    e0 ? e0->next = s1 : s0 = s1;
    
    return s0;
}