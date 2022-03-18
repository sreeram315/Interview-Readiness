// https://leetcode.com/problems/copy-list-with-random-pointer/submissions/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return head;
        Node *p = head, *q;
        // creating new nodes
        while(p){
            q = new Node(p->val);
            q->next = p->next;
            p->next = q;
            p = p->next->next;
        }
        p = head, q = head->next;
        Node *ans = q;
        // setting random pointers
        while(p){
            if(p->random)
                q->random = p->random->next;
            p = p->next->next;
            q = (q->next) ? q->next->next : NULL;
        }
        p = head, q = head->next;
        // detaching 
        while(p){
            p->next = p->next->next;
            q->next = (q->next) ? q->next->next : NULL;
            p = p->next;
            q = q->next;
        }
        return ans;
    }
};














