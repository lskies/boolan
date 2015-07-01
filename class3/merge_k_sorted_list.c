struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct cmp {
    bool operator() (const ListNode *a, const ListNode *b)
    {
        if (a->val < b->val)
            return false;
        else
            return true;
    }
};

ListNode *mergeKLists(vector<ListNode *> &lists) {
    priority_queue<ListNode *, vector<ListNode *>, cmp> heap;

    for (int i = 0; i < lists.size(); i++) {
        if (lists[i]) {
            // for the corner case: [{}]
            heap.push(lists[i]);
        }
    }

    ListNode *prevNode = NULL;
    ListNode *head = NULL;
    ListNode *curNode = NULL;
    while (!heap.empty()) {
        curNode = heap.top();
        heap.pop();
        if (head == NULL) {
            head = curNode;
        }
        if (curNode->next) {
            heap.push(curNode->next);
        }
        if (prevNode) {
            prevNode->next = curNode;
        }
        prevNode = curNode;
    }

    return head;
}
