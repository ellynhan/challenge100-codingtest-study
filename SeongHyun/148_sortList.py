# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def sortList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        pylist = []
        result = before = head
        while head:
            pylist.append(head.val)
            head = head.next

        pylist.sort()
        
        for num in pylist:
            before.val = num
            before = before.next
        
        return result
      
