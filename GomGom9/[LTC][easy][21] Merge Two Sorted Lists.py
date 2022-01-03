"""
    topics : Linked List, Recursion
    link : https://leetcode.com/problems/merge-two-sorted-lists/
    elapsed time : 10min
"""
import time
from collections import deque
from typing import Optional

""" My solutions """
# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

    def __str__(self):
        _list = [self.val]
        _next = self.next
        while _next is not None:
            _list.append(_next.val)
            _next = _next.next
        return _list.__str__()

class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        merged_list_head = ListNode()
        merged_list_node = merged_list_head
        while list1 is not None and list2 is not None:
            if list1.val <= list2.val:
                merged_list_node.next = list1
                merged_list_node = merged_list_node.next
                list1 = list1.next
            else:
                merged_list_node.next = list2
                merged_list_node = merged_list_node.next
                list2 = list2.next
        merged_list_node.next = list1 if list1 is not None else list2
        return merged_list_head.next

""" Comments """

""" Other solutions """
class _Solution:
    # reference : https://leetcode.com/problems/merge-two-sorted-lists/discuss/398326/Python3-beats-99.96-runtime-28ms
    #   -> 풀이는 동일한데 while (l1 and l2)가 왜 되는 것이지...?
    #       -> 파이썬의 False, None, 0, empty list, empty tuple, empty dictionary, empty string 은 모두 false
    #           - reference : https://stackoverflow.com/questions/3914667/false-or-none-vs-none-or-false
    #           (참고 : python3에서 bool이 int 기반으로 만들어 졌기에, False == 0, True == 1)
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:

        head = sort_list = ListNode(0)

        while (l1 and l2):
            if (l1.val < l2.val):
                sort_list.next = l1
                l1 = l1.next
                sort_list = sort_list.next

            elif (l1.val >= l2.val):
                sort_list.next = l2
                l2 = l2.next
                sort_list = sort_list.next

        sort_list.next = l1 or l2
        return head.next

""" Test cases """
solution = Solution()
start_time = time.process_time()

case1 = solution.mergeTwoLists(ListNode(1, ListNode(2, ListNode(4))), ListNode(1, ListNode(3, ListNode(4))))
case2 = solution.mergeTwoLists(ListNode(), ListNode())
case3 = solution.mergeTwoLists(ListNode(), ListNode(0))

elapsed_time = round((time.process_time() - start_time) * 1000, 4)
print("-" * 30)
print(f"time elapsed : {'%.4f' % elapsed_time}ms")
print(f"case1 : {case1}")
print(f"case2 : {case2}")
print(f"case3 : {case3}")
print("-" * 30)
