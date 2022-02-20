"""
    topics : Linked List, Recursion
    link : https://leetcode.com/problems/reverse-linked-list/
    elapsed time : 7분
"""
import time
from typing import Optional, List, Counter, Dict

""" My solutions """
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        top_node = None
        while head:
            bottom_node = head.next
            head.next = top_node
            top_node = head
            head = bottom_node
        return top_node

""" Comments

"""

""" Other solutions """

""" Test cases """
solution = Solution()
start_time = time.process_time()

case1 = solution.reverseList(ListNode(1, ListNode(2, ListNode(3, ListNode(4, ListNode(5))))))
# case2 = solution.reverseList()
# case3 = solution.reverseList()

elapsed_time = round((time.process_time() - start_time) * 1000, 4)
print("-" * 30)
print(f"time elapsed : {'%.4f' % elapsed_time}ms")
print(f"case1 : {case1}")
# print(f"case2 : {case2}")
# print(f"case3 : {case3}")
print("-" * 30)
