// https://leetcode.com/problems/intersection-of-two-linked-lists/

class Solution {
public:
    
    int getLength(ListNode *p){
        if(!p) return 0;
        return 1+getLength(p->next);
    }
    
    void advance(ListNode* &h, int diff){
        while(diff--)
            h = h->next;
    }
    
    ListNode *getIntersectionNode(ListNode *h1, ListNode *h2) {
        int l1 = getLength(h1), l2 = getLength(h2);
        int diff = abs(l1-l2);
        advance(l1>l2 ? h1 : h2, diff);
        while(h1!=h2){
            h1 = h1->next;
            h2 = h2->next;
        }
        return h1;
    }
};