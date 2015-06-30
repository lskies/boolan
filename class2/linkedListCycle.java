public class Solution {
    public ListNode detectCycle(ListNode head) {
        if (head == null) {
            return null;
        }

        ListNode fast, slow;
        fast = slow = head;
        do {
            if (fast.next == null || fast.next.next == null) {
                return null;
            }
            fast = fast.next.next;
            slow = slow.next;
        } while (fast != slow);

        while (head != slow) {
            head = head.next;
            slow = slow.next;
        }
        return head;
    }
}
