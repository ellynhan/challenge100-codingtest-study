"""
    topics : Linked List, Two Pointers, Stack, Recursion
    link : https://leetcode.com/problems/palindrome-linked-list/
    elapsed time : 10분
"""
import time
from collections import Counter
from operator import itemgetter
from typing import Optional, List, Dict

""" My solutions """
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:
    def isPalindrome(self, head: Optional[ListNode]) -> bool:
        list = []
        while head:
            list.append(head.val)
            head = head.next
        list_size = len(list)
        center = list_size // 2
        is_odd = list_size % 2 == 1
        i = center - 1
        j = center + 1 if is_odd else center
        while i >= 0 and j < list_size:
            if list[i] != list[j]:
                return False
            i -= 1
            j += 1
        return True

""" Comments
Follow up: Could you do it in O(n) time and O(1) space?
을 푸는법을 고민해봤는데 ListNode를 뒤집고, 앞뒤로 바로 비교하는 방법이 생각이 남. 베스트 솔루션은 아닐거 같음.
"""

""" Other solutions """
# https://leetcode.com/problems/palindrome-linked-list/discuss/1695170/Python-Very-Easy-Approach
# -> 와 세상엔 천재가 많은듯 ㅋㅋ
""" Test cases """
solution = Solution()
start_time = time.process_time()

case1 = solution.isPalindrome(ListNode(1, ListNode(2, ListNode(2, ListNode(1)))))
# case2 = solution.isPalindrome([2, 2, 1, 1, 1, 2, 2])
# case3 = solution.reverseList()

elapsed_time = round((time.process_time() - start_time) * 1000, 4)
print("-" * 30)
print(f"time elapsed : {'%.4f' % elapsed_time}ms")
print(f"case1 : {case1}")
# print(f"case2 : {case2}")
# print(f"case3 : {case3}")
print("-" * 30)
