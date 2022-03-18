class Solution {
public:
    int get_length(ListNode *l){
        int count = 0;
        while(l){
            count++;
            l = l->next;
        }
        return count;
    }
    
    void add_nums(ListNode* l1, ListNode* l2, ListNode*prev = NULL,int c = 0){
        if(!l1){
            if(c) prev->next = new ListNode(c);
            return;
        }
        int a = l1->val, b = l2 ? l2->val : 0;
        int sum = (a+b+c)%10; c = (a+b+c)/10;
        l1->val = sum; 
        add_nums(l1->next, l2?l2->next:NULL, l1, c);
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int len1 = get_length(l1), len2 = get_length(l2);
        if(len1<len2) swap(l1, l2);
        add_nums(l1, l2);
        return l1;
    }
};