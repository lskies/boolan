ListNode *findkthtoLast(ListNode *head,int k){
    ListNode *runner = head;
    ListNode *chaser = head;

    if (head == NULL || k < 0)
    return NULL;
    
    for(int i = 0; i < k; i++)
        runner = runner->next;
    
    if( runner == NULL )
        return NULL;
    
    while( runner->next != NULL ) {
        chaser = chaser->next;
        runner = runner->next;
    }
    return chaser;
}

