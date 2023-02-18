# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def reverseList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        nodes = []
        curr = head
        
        if not head:
            return head

        if not head.next:
            return head

        while curr:
            nodes.append(curr)
            curr = curr.next

        re = nodes.pop()
        curr = re
        while len(nodes) > 0:
            curr.next = nodes.pop()
            curr = curr.next
        curr.next = None
        return re