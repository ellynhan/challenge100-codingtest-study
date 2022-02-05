# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        heap=[]
        ans = None
        
        for lst in lists:
            while lst:
                heapq.heappush(heap, lst.val*-1)
                lst=lst.next

        while heap:
            added_node = ListNode()
            added_node.val = heapq.heappop(heap)*-1
            added_node.next = ans
            ans = added_node
            
        return ans
      
