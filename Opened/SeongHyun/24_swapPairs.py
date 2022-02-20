# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def swapPairs(self, head: Optional[ListNode]) -> Optional[ListNode]:
        result = head
        
        while head and head.next:
            tmp = head.val
            head.val = head.next.val
            head.next.val = tmp
            head = head.next.next
    
        return result
    
