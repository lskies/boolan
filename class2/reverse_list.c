ListNode *reverseLinkedList( ListNode *head ) {
    ListNode *prev = NULL;
    ListNode *next = head->next;
    while(head) {
        head->next = prev;
        prev = head;
        head = next;
        next = next->next;
    }
    return prev;
}

