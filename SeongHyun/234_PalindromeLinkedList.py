# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def isPalindrome(self, head: Optional[ListNode]) -> bool:
        tmp = head
        tmp2 = head
        check = 0
        pylist = []
        result = True
        while tmp:
            tmp = tmp.next
            check += 1
            if check%2 ==0:
                pylist.append(tmp2.val)
                tmp2 = tmp2.next
        if check%2 == 0:
            while tmp2:
                if pylist.pop() != tmp2.val:
                    result = False
                tmp2 = tmp2.next
        else:
            tmp2 = tmp2.next
            while tmp2:
                if pylist.pop() != tmp2.val:
                    result = False
                tmp2 = tmp2.next
        return result
      
