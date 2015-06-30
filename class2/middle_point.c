ListNode *midpoint( ListNode *head) {
    ListNode *chaser = head, *runner = head;
    if (head == NULL)
        return NULL;

    while (runner->next && runner->next->next ) {
        chaser = chaser->next;
        runner = runner->next->next;
    }
    return chaser;
}

