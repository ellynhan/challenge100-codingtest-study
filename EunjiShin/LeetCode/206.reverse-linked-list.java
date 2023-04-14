package Easy;

/*
 * @lc app=leetcode id=206 lang=java
 *
 * [206] Reverse Linked List
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * public class ListNode {
 * int val;
 * ListNode next;
 * ListNode() {}
 * ListNode(int val) { this.val = val; }
 * ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode reverseList(ListNode head) {
        return reverse(head, null);
    }

    public ListNode reverse(ListNode head, ListNode newHead) {
        if (head == null)
            return newHead;
        ListNode nextNode = head.next;
        head.next = newHead;
        newHead = head;
        head = nextNode;
        return reverse(head, newHead);
    }
}
// @lc code=end
