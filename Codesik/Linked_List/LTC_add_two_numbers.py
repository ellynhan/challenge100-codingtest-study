"""
문제:
    You are given two non-empty linked lists representing two non-negative integers.
    The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

    You may assume the two numbers do not contain any leading zero, except the number 0 itself.

제한:
   The number of nodes in each linked list is in the range [1, 100].
    0 <= Node.val <= 9
    It is guaranteed that the list represents a number that does not have leading zeros.
입력:
    -
출력:
    -
시작:
    9.19 16:20
소요시간:
    15분
"""

from typing import Optional


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        num_1 = []
        num_2 = []

        is_end_1 = False
        is_end_2 = False

        while True:
            if l1.next is not None:
                num_1.append(l1.val)
                l1 = l1.next
            if l2.next is not None:
                num_2.append(l2.val)
                l2 = l2.next
            if l1.next is None and not is_end_1:
                is_end_1 = True
                num_1.append(l1.val)
            if l2.next is None and not is_end_2:
                is_end_2 = True
                num_2.append(l2.val)
            if is_end_1 and is_end_2:
                break

        num_1.reverse()
        num_2.reverse()

        print(num_1, num_2)
        str_answer = int("".join(map(str, num_1))) + int("".join(map(str, num_2)))
        str_answer = [x for x in str(str_answer)]
        str_answer.reverse()

        node_next = ListNode(int(str_answer[len(str_answer) - 1]), None)

        for i in range(len(str_answer) - 2, -1, -1):
            node = ListNode(int(str_answer[i]), node_next)
            node_next = node

        return node_next