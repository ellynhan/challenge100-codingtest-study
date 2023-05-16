package Easy;

/*
 * @lc app=leetcode id=876 lang=java
 *
 * [876] Middle of the Linked List
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
    public ListNode middleNode(ListNode head) {
        ListNode[] array = new ListNode[100];
        ListNode node = head;
        int i = 0;

        while (node != null) {
            array[i++] = node;
            node = node.next;
        }

        return array[i / 2];
    }
}
// @lc code=end
