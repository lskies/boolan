ListNode *rotateRight(ListNode *head, int k) {
    int len = 0;
    ListNode *cur = head;
    
    if(head == NULL)
        return head;
    
    while(cur){
        len++;
        cur = cur->next;
    }

    k = k%len;
    if(k == 0)  
        return head;

    cur = head;
    for(int i = 0; i < len - k - 1;i++)
        cur = cur->next;
  
    ListNode *const newHead = cur->next; 
    ListNode *const newTail = cur;
    newTail ->next = NULL;
    newHead ->next = head;
    return newHead；
};

