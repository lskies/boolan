class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode dummy(0);
        ListNode* p = &dummy;

        int cn = 0;

        while(l1 || l2) {
            int val = cn + (l1 ? l1->val : 0) + (l2 ? l2->val : 0);
            cn = val / 10;
            val = val % 10;
            p->next = new ListNode(val);
            p = p->next;
            if(l1) {
                l1 = l1->next;
            }
            if(l2) {
                l2 = l2->next;
            }
        }

        if(cn != 0) {
            p->next = new ListNode(cn);
            p = p->next;
        }

        return dummy.next;
    }
};
