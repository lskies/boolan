/**
Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.
*/
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        // Start typing your Java solution below
        // DO NOT write main() function
        if (l1 == null)
            return l2;
        if (l2 == null)
            return l1;
        ListNode head = l1.val < l2.val? l1:l2;
        ListNode temp = new ListNode(0);
        while (l1 != null && l2 !=null) {
            if (l1.val < l2.val) {
                temp.next = l1;
                temp = l1;
                l1 = l1.next;
            } else {
                temp.next = l2;
                temp = l2;
                l2 = l2.next;
            } 
        }
        
        if (l1 == null) {
            temp.next = l2;
        }
        if (l2 == null) {
            temp.next = l1;
        }
        return head;
    }
}
