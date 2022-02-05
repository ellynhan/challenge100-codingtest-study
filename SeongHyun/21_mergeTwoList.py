# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        heap=[]
        ans = None

        while list1:
            heapq.heappush(heap, list1.val*-1)
            list1=list1.next
        while list2:
            heapq.heappush(heap, list2.val*-1)
            list2=list2.next

        while heap:
            added_node = ListNode()
            added_node.val = heapq.heappop(heap)*-1
            added_node.next = ans
            ans = added_node

        return ans
