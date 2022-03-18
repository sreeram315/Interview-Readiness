void removeLoop(Node* head)
{
    Node *p = head, *q = head; 
    p = head;
    while(p && q && p->next){
        p = p->next->next;
        q = q->next;
        if(p==q){
            if(q == head){
                do{
                    p = p->next;
                }while(p->next!=q);
            }
            else{
                q = head;
                while(p->next != q->next){
                    p = p->next;
                    q = q->next;
                }
            }
            p->next = NULL;
        }
    }
}