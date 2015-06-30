ListNode *reorderList(ListNode *head, int x) {        
    ListNode *newHead = NULL;
    ListNode *aDummy = new ListNode(0);
    ListNode *aCurr = aDummy;
    ListNode *bDummy = new ListNode(0);
    ListNode *bCurr = bDummy;

    while(head) {       
        ListNode *next = head->next;
        head->next = NULL;        
        if( head->val < x ) {
            aCurr->next = head;
            aCurr = head;
        } else {
            bCurr->next = head;
            bCurr = head;
        }         
        head = next;
    }      

    aCurr->next = bDummy->next;
    newHead  = aDummy->next;

    delete aDummy;
    delete bDummy;

    return newHead;
}

