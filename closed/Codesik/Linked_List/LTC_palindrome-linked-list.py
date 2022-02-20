"""
문제:
    Given the head of a singly linked list, return true if it is a palindrome.

제한:
    The number of nodes in the list is in the range [1, 105].
    0 <= Node.val <= 9
입력:
    -
출력:
    -
시작:
    9.19 23:20
소요시간:
    5분
"""

# Definition for singly-linked list.
from typing import Optional


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def isPalindrome(self, head: Optional[ListNode]) -> bool:
        num = []
        while True:
            if head.next is None:
                num.append(head.val)
                break
            num.append(head.val)
            head = head.next
        return num == num[::-1]
