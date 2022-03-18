// https://leetcode.com/problems/sort-list/submissions/
class Solution {
public:
    ListNode* merge(ListNode *h1, ListNode *h2){
        if(!h1 && !h2) return NULL;
        if(!h1 || !h2) return h1?h1:h2;
        if(h1->val < h2->val){
            h1->next = merge(h1->next, h2);
            return h1;
        }else{
            h2->next = merge(h1, h2->next);
            return h2;
        }
        return NULL;
    }
    
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode *fast = head->next, *slow = head;
        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode *temp = slow->next;
        slow->next = NULL;
        head = sortList(head);
        temp = sortList(temp);
        head = merge(head, temp);
        return head;
    }
};