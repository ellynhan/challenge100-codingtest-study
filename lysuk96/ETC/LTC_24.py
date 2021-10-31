import ListNode

def swapPairs(self, head:ListNode)->ListNode:
    cur = head
    while cur and cur.next:
        cur.val, cur.next.val= cur.next.val, cur.val
        cur = cur.next.next

    return head